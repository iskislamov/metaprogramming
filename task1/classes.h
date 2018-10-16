#pragma once


#include "Interface.h"


class A : public Interface {
public:
	A() {}

	~A() {}

	void execute() {
		std::cout << this << " A member is executing" << std::endl;
	}

	void execute(Interface* exemplar) {
		if (!exemplar) {
			std::cout << "Pointer to nullptr" << std::endl;
			return;
		}
		exemplar->execute();
	}
};


class B : public Interface {
public:
	B() {}

	~B() {}

	void execute() {
		std::cout << this << " B member is executing" << std::endl;
	}
};


template <Patterns T>
class Pattern;