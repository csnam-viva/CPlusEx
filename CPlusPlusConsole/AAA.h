#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class AAA
{
public:
	AAA();
	~AAA();
private:
	struct AImpl;
	std::shared_ptr<AImpl>* pImpl;
	//AImpl* pImpl;
};

