#pragma once


#include "classes.h"


template <>
class Pattern<Patterns::PROXY> : public Interface {
private:
	B* ptr_ = nullptr;
public:
	Pattern() {}

	Pattern(B* ptr) {
		if (!ptr) {
			std::cout << "Pointer to nullptr" << std::endl;
			return;
		}
		ptr_ = ptr;
	}

	void attach(B* b) {
		if (ptr_) {
			std::cout << "Pointer to B member has already been attached" << std::endl;
			return;
		}
		if (!b) {
			std::cout << "Pointer to nullptr" << std::endl;
			return;
		}
		ptr_ = b;
	}

	void execute() {
		if (!ptr_) {
			std::cout << "Pointer to nullptr" << std::endl;
			return;
		}
		std::cout << this << " proxy is executing" << std::endl;
		std::cout << "Redirecting to real subject" << std::endl;
		ptr_->execute();
	}
};