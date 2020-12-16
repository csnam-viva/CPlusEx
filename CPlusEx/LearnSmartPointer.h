#pragma once
#include <memory>
#include <string>	
#include <vector>
#include "song.h"

using namespace std;

class LargeObj
{
private:
	char OneByte;
public:
	LargeObj() { OneByte = 0x05; };
	~LargeObj() {};
	void DoSomething() { TRACE("Do Someting =%d \n", OneByte); }
};

class ShareObj
{
private:
	char OneByte;
	int  _no;
public:
	ShareObj() { OneByte = 0x05; };
	ShareObj(int no) { _no = no; };
	~ShareObj() {};
	void DoSomething() { TRACE("Do Someting =%d \n", OneByte); }
};
class LearnSmartPointer
{
private:
	void ProcessLargeObj(LargeObj& lo);
public:
	//step1:
	void MakeSong();
	//step2:
	void SmartPointerDemo();
	void SmartPonterDemo2();

	void SmartPonterDemo3();
	void SmartPonterDemo4();

	void SharePinterDomo1();

	

	

};

//
//unique_ptr<song> SongFactory(const std::wstring& aritis,
//	const std::wstring& title)
//{
//	return nullptr;
//}








