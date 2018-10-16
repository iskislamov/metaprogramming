#pragma once


#include "classes.h"


template <>
class Pattern<Patterns::OBSERVER> : public Interface {
private:
	B* ptr_ = nullptr;
	std::vector<A*> subscribers_;

	void notify() {
		if (!ptr_) {
			std::cout << "No subject to observe, cannot send notifications" << std::endl;
			return;
		}
		std::cout << "Notification sent by " << ptr_ << " B member" << std::endl;
		if (subscribers_.empty()) {
			std::cout << "No subscribers" << std::endl;
		}
		for (auto it = subscribers_.begin(); it != subscribers_.end(); ++it) {
			(*it)->execute();
		}
	}
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

	void addSubscriber(A* a) {
		if (!ptr_) {
			std::cout << "No subject to observe, cannot subscribe" << std::endl;
			return;
		}
		for (auto it = subscribers_.begin(); it != subscribers_.end(); ++it) {
			if (*it == a) {
				std::cout << "Subscriber has already been added" << std::endl;
				return;
			}
		}
		subscribers_.push_back(a);
	}

	void execute() {
		notify();
	}
};