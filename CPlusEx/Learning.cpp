#include "pch.h"
#include "Learning.h"
#include "CUtil.h"
#include <functional>

int some_fn(string str)
{
	CUtil::csDebugOutput("some fund %s", str.c_str());
	return 3;
}


void Learning::A00_Call()
{
	//1. () 를 붙이는 것은 모두 callable 이라 정의 
	Study oStudy;
	oStudy(1, 4);

	// 2. 람다를 사용하기 
	auto f2 = [](int a, int b) {  TRACE("a+b =%d", a + b); return (a + b); };
	f2(5, 4);

	// 특정함수를 std::function으로 저장하고 사용
	std::function<int(string)> f3 = some_fn;
	f3("aaaaa");

	// 클래스안에 함수가 있을 경우 
	//f4 함수 입장에서는 호출한 객체(oStudy2)를 알 수가 없다.
	Study oStudy2;
	std::function<int(Study&, string)> f4 = &Study::inner_some_fn;
	f4(oStudy2, "call fn in the class");

}
void Learning::A01_Call()
{
	//참조자 (reference)
	int a1 = 14;
	int& c1 = a1;

	int b1 = 3;
	c1 = b1;

	//
	CUtil::csDebugOutput("%c", c1);

	//레퍼런스와 포인터는 몇 가지 중요한 차이점이 있습니다.
	//레퍼런스가 한 번 별명이 되면 절대로 다른 이의 별명이 될 수 없다.
	//레퍼런스는 메모리 상에 존재하지 않을 수 도 있다.
	//인자로 전달할때 그대로 전달하는 것은 참조자를 정의할 때 그냥 int& a = b 와 같이 한 것과 일맥상통합니다.
	  


	// 포인터
	int a = 10;
	int* p = &a;

	int b = 4;
	p = &b;   // p는 a를 버리고 b를 가르킨다.


	//포인터와 다르게 배열의 레퍼런스의 경우 참조하기 위해선 반드시 배열의 크기를 명시해야 합니다.

	//참조자를 리턴하는 경우의 장점이 무엇일까요
	//레퍼런스가 참조하는 타입의 크기와 상관 없이 딱 한 번의 주소값 복사로 전달이 끝나게 됩니다.
	
	const int& c = function();
	//예외적으로 상수 레퍼런스로 리턴값을 받게 되면 해당 리턴값의 생명이 연장됩니다.그리고 그 연장되는 기간은 레퍼런스가 사라질 때 까지 입니다

}
int Learning::function() {
	int a = 5;
	return a;
}

template <typename T>
T Learning::Max(T& a, T& b)
{
	return a > b ? a : b;
}

void Learning::A01_templateFunc()
{

	int a = 4; int b = 6;
	CUtil::csDebugOutput("%d \n",Max(a, b));
	string s = "abc", t = "aba";
	CUtil::csDebugOutput("%s \n", Max(s, t).c_str());


}


template <typename T>
class VectorA {
	T* data;
	int capacity;
	int length;

public:
	// 어떤 타입을 보관하는지
	//typedef T value_type;

	// 생성자
	VectorA(int n = 1) : data(new T[n]), capacity(n), length(0) {}

	// 맨 뒤에 새로운 원소를 추가한다.
	void push_back(int s) {
		if (capacity <= length) {
			int* temp = new T[capacity * 2];
			for (int i = 0; i < length; i++) {
				temp[i] = data[i];
			}
			delete[] data;
			data = temp;
			capacity *= 2;
		}

		data[length] = s;
		length++;
	}

	// 임의의 위치의 원소에 접근한다.
	T operator[](int i) { return data[i]; }

	// x 번째 위치한 원소를 제거한다.
	void remove(int x) {
		for (int i = x + 1; i < length; i++) {
			data[i - 1] = data[i];
		}
		length--;
	}

	// 현재 벡터의 크기를 구한다.
	int size() { return length; }

	// i 번째 원소와 j 번째 원소 위치를 바꾼다.
	void swap(int i, int j) {
		T temp = data[i];
		data[i] = data[j];
		data[j] = temp;
	}

	~VectorA() {
		if (data) {
			delete[] data;
		}
	}
};

template <typename SS>
void Learning::bubble_sort(SS& ss)
{
	for (int i = 0; i < ss.size(); i++) {
		for (int j = i+1; j< ss.size(); j++) {
			if (ss[i] > ss[j]) {
				ss.swap(i, j);
			}
		}
	}
}
//클래스 템플릿

#include <functional>
#include "debug.h"

//Function Object - Functor
using namespace GE_;
void Learning::A02_templateFunc()
{
	VectorA<int> int_vec;
	int_vec.push_back(3);
	int_vec.push_back(5);
	int_vec.push_back(1);
	int_vec.push_back(4);
	int_vec.push_back(9);
	
	// templdate를 받음	
	std::function<void(Learning&)> aa = &Learning::A02_templateFunc;
	dbg::trace trc("A02", &aa);
	for (int i = 0; i < int_vec.size(); i++)
	{
		
		trc << int_vec[i];
	}
	
	trc << "" << std::endl;

	bubble_sort(int_vec);
	for (int i = 0; i < int_vec.size(); i++)
	{
		trc << int_vec[i] ;
	}
	trc << "" << std::endl;

	
}

// 바이트 계산 
void Learning::A03_BYTE_toWORD()
{
	dbg::trace trc("A03", 0);
	trc << "UINT : " << sizeof(UINT);
	trc << "DWORD : " << sizeof(DWORD);
	trc << "int : " << sizeof(int);
	trc << "WORD : " << sizeof(WORD);
	trc << "short : " << sizeof(short);
	trc << "char : " << sizeof(char);
	trc << "long : " << sizeof(long);
	trc << "float : " << sizeof(float);
	trc << "double : " << sizeof(double);
	trc << "" << std::endl;


	typedef struct item_code_tag {
		int startcode;
		int size;
	} item_code_t; //8 byte

	item_code_t hdr;
	BYTE szHeader[10] = { 0xa,0xa,0x5,0x5 };
	memset(szHeader, 0x00, sizeof(szHeader));

	hdr.size = 12345;
	hdr.startcode = 0xaa55;
	//memcpy(&hdr, szHeader, sizeof(item_code_t));
	memcpy(szHeader, &hdr, sizeof(item_code_t));


	//////////////////////////////////

	DWORD dwHdr = 0;
	DWORD dwsize = 0;
	memcpy(&dwHdr, szHeader, sizeof(UINT));
	memcpy(&dwsize, &szHeader[3], sizeof(UINT));
	trc << "dwHdr: " << dwHdr << "\n";
	trc << "dwSize: " << dwsize << "\n";



	item_code_t hdr2;
	memcpy(&hdr2, szHeader, sizeof(hdr2));
	trc << "dwHdr: " << hdr2.startcode << "\n";
	trc << "dwSize: " << hdr2.size << "\n";

	//////////////////
	////memset(szHeader, 0x00, sizeof(szHeader));
	//DWORD szSize = 2345;
	//memcpy(szHeader + 4, &szSize, sizeof(UINT));
	//
	//DWORD dwHdr=0;
	//DWORD dwsize=0;
	//memcpy(&dwHdr, &szHeader[0], sizeof(UINT));
	//memcpy(&dwsize, &szHeader[3], sizeof(UINT));

	//trc << "dwHdr: "  <<  dwHdr << "\n";
	//trc << "dwSize: " << dwsize << "\n";
	string area = "0.002, 0.003, 0.701,0.801";
	float v_f[4] = { 0,0,0,0 };
	int n= sscanf(area.c_str(), "%f,%f,%f,%f", &v_f[0], &v_f[1], &v_f[2], &v_f[3]);

	TRACE("f =%f, %f, %f, %f \n", v_f[0], v_f[1], v_f[2], v_f[3]);
	

}


//#include "json/"

void Learning::JSONTest()
{


}
