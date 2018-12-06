#pragma once

#include "typelist.h"


template<class T>
struct Unit {
	T value_;
};


template<typename TL, template <class, class...> class Unit>
class GenScatterHierarchy;

template<typename T, typename ...Args, template <class, class...> class Unit>
class GenScatterHierarchy<TypeList<T, Args...>, Unit> : 
	public GenScatterHierarchy<T, Unit>,
	public GenScatterHierarchy<TypeList<Args...>, Unit> {

public:
	using TList = TypeList<T, Args...>;
	using LeftBase = GenScatterHierarchy<T, Unit>;
	using RightBase = GenScatterHierarchy<TypeList<Args...>, Unit>;
};

template <class T, template <class, class...> class Unit>
class GenScatterHierarchy :	public Unit<T> {
public:
	using LeftBase = Unit<T>;
};

template<template <class, class...> class Unit>
class GenScatterHierarchy<EmptyList, Unit> {};


template<typename T, typename TL, template<class, class...> class Unit>
Unit<T>& Field(GenScatterHierarchy<TL, Unit>& obj) {
	return static_cast<Unit<T>&>(obj);
}