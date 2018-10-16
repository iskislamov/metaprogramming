#pragma once


#include "classes.h"


template <>
class Pattern<Patterns::MEDIATOR> : public Interface {
private:
	std::vector<B*> members_;
public:
	Pattern() {}

	void attach(B* b) {
		for (auto it = members_.begin(); it != members_.end(); ++it) {
			if (*it == b) {
				std::cout << "This member of class B has already been attached" << std::endl;
			}
		}
		members_.push_back(b);
	}

	void execute() {
		if (members_.empty()) {
			std::cout << "No class B members to execute command" << std::endl;
			return;
		}
		members_[rand() % members_.size()]->execute();
	}
};