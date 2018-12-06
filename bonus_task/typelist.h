#pragma once
#include <iostream>
#include <typeinfo>


// Type list declaration
struct NullType {};

template<typename ...Args>
struct TypeList {
	using head = NullType;
	using tail = NullType;
};

using EmptyList = TypeList<>;

template<typename T, typename ...Args>
struct TypeList<T, Args...> {
	using head = T;
	using tail = TypeList<Args...>;
};


// Prints
template<typename TL>
void printTypeList() {
	std::cout << typeid(typename TL::head).name() << " ";
	printTypeList<typename TL::tail>();
}

template<>
void printTypeList<EmptyList>() {
	std::cout << std::endl;
}


// Returns length
template<typename TL>
struct Length {
	enum { value = Length<typename TL::tail>::value + 1 };
};

template<>
struct Length<EmptyList> {
	enum { value = 0 };
};


// Removes type from tl
template<typename T, typename TL> 
struct Erase {};

template<typename T>
struct Erase<T, EmptyList> {
	using result = NullType;
};

template<typename T, typename ...Args>
struct Erase<T, TypeList<T, Args...>> {
	using result = TypeList<Args...>;
};

template<typename _T, typename T, typename ...Args>
struct Erase<_T, TypeList<T, Args...>> {
	using result = TypeList<T, typename Erase<_T, TypeList<Args...>>::result>;
};