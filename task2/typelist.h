#pragma once
#include <iostream>


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


// Checks if tl is empty
template<typename TL>
struct IsEmpty : std::true_type {};

template<>
struct IsEmpty<EmptyList> : std::true_type {};

template<typename ...Args>
struct IsEmpty<TypeList<Args...>> : std::integral_constant<bool,
	std::is_same<typename TypeList<Args...>::head, NullType>::value &&
	IsEmpty<typename TypeList<Args...>::tail>::value> {};


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
struct Length : std::integral_constant<unsigned int, 0> {};

template<>
struct Length<EmptyList> : std::integral_constant<unsigned int, 0> {};

template<typename ...Args>
struct Length<typename TypeList<Args...>> : std::integral_constant<unsigned int, 
	IsEmpty<TypeList<Args...>>::value 
	? 0 
	: Length<typename TypeList<Args...>::tail>::value + 1> {};


// Returns type at given index
template<unsigned int index, typename TL>
struct TypeAt {
	static_assert(index < Length<TL>::value, "Index is too large");
	using type = typename TypeAt<index - 1, typename TL::tail>::type;
};

template<typename TL>
struct TypeAt<0, TL> {
	using type = typename TL::head;
};


// Returns tl without first N elements
template<unsigned int N, typename TL>
struct Skip;

template<typename TL>
struct Skip<0, TL> {
	using result = TL;
};

template<unsigned int N>
struct Skip<N, EmptyList> {
	using result = EmptyList;
};

template<unsigned int N, typename TL>
struct Skip {
	using result = typename Skip<N - 1, typename TL::tail>::result;
};