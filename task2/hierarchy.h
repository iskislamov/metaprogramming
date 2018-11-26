#pragma once


#include "typelist.h"
#include "fibonacci.h"


template<class T, class Root>
struct Unit : public Root {
	T value;
};


// N is a number of types linear hierarchy should contain
template<unsigned int N, class TypeList, template <class, class> class Unit>
struct GenLinearHierarchy;

template<unsigned int N, typename T, typename ...Args, template <class, class> class Unit>
struct GenLinearHierarchy<N, TypeList<T, Args...>, Unit> : 
	public Unit<T, GenLinearHierarchy<N - 1, TypeList<Args...>, Unit>> {};

template<typename T, typename ...Args, template <class, class> class Unit>
struct GenLinearHierarchy<0, TypeList<T, Args...>, Unit> {};

template<unsigned int N, template <class, class> class Unit>
struct GenLinearHierarchy<N, EmptyList, Unit> {};


// Scatter hierarchy
template<unsigned int index, typename TL, template <class, class> class Unit>
struct FibonacciHelper;

template<unsigned int index, typename T, typename ...Args, template <class, class> class Unit>
struct FibonacciHelper<index, TypeList<T, Args...>, Unit>
	: public GenLinearHierarchy<Fibonacci<index>::value, TypeList<T, Args...>, Unit>,
	  public FibonacciHelper<index + 1, typename Skip<Fibonacci<index>::value, 
	                         TypeList<T, Args...>>::result, Unit> {};

template <unsigned int index, template <class, class> class Unit>
class FibonacciHelper<index, EmptyList, Unit> {}; //


template <typename TL, template <class, class> class Unit>
using GenScatterHierarchy = FibonacciHelper<0, TL, Unit>;