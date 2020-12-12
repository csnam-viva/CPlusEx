#pragma once

#include "CUtil.h"
#include <string>
using namespace std;

class Study {

public:
	void operator() (int a, int b) {
		CUtil::csDebugOutput("%d %d", a, b);
	}
	int inner_some_fn(string str)
	{
		CUtil::csDebugOutput("innner some fund %s", str.c_str());
		return 3;
	}
};



class Learning
{
private:
	int function();
	template<typename T> T Max(T& a, T& b);
	template<typename SS>
	void bubble_sort(SS& ss);
public:
	//  callable, lamda, std::function
	void A00_Call();

	//ÂüÁ¶ÀÚ 
	void A01_Call();
	void A01_templateFunc();

	void A02_templateFunc();

	void A03_BYTE_toWORD();

	void StrintTest();
	
	

};

