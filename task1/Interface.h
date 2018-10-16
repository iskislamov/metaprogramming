#pragma once


#include <iostream>
#include <string>
#include <time.h>
#include <unordered_map>
#include <vector>


enum Patterns {
	OBSERVER,
	PROXY,
	MEDIATOR
};


class Interface {
public:
	virtual ~Interface() = default;
	virtual void execute() = 0;
};