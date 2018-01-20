#pragma once
#include <iostream>
#include "exception.h"
#include "SimSpace.h"


template <typename T>
class SimSpace;

template <typename T>
class SimChain;

template <typename T>
class SimNode
{
public:
	friend class SimSpace<T>;
	friend class SimChain<T>;
private:
	T data;
	int link;
};
