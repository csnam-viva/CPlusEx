#pragma once
#include <string>
#include <memory.h>
#include <malloc.h>
using namespace std;
typedef std::basic_string<TCHAR> tstring;

class song
{
private:
	tstring _artis;
	tstring _title;
public:
	song();
	~song();
	song(tstring, tstring);

	tstring artis;
	tstring title;

	int test_blanks();
};


//https://docs.microsoft.com/en-us/cpp/cpp/new-and-delete-operators?view=msvc-160
//class Blanks
//{
//public:
//	Blanks() {}
//	void* operator new(size_t stAllocateBlock, char chInit);
//};
//
//void* Blanks::operator new(size_t stAllocateBlock, char chInit)
//{
//	void* pvTemp = malloc(stAllocateBlock);
//	if (pvTemp != 0)
//		memset(pvTemp, chInit, stAllocateBlock);
//	return pvTemp;
//}