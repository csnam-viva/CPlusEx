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
	//1. () �� ���̴� ���� ��� callable �̶� ���� 
	Study oStudy;
	oStudy(1, 4);

	// 2. ���ٸ� ����ϱ� 
	auto f2 = [](int a, int b) {  TRACE("a+b =%d", a + b); return (a + b); };
	f2(5, 4);

	// Ư���Լ��� std::function���� �����ϰ� ���
	std::function<int(string)> f3 = some_fn;
	f3("aaaaa");

	// Ŭ�����ȿ� �Լ��� ���� ��� 
	//f4 �Լ� ���忡���� ȣ���� ��ü(oStudy2)�� �� ���� ����.
	Study oStudy2;
	std::function<int(Study&, string)> f4 = &Study::inner_some_fn;
	f4(oStudy2, "call fn in the class");

}
void Learning::A01_Call()
{
	//������ (reference)
	int a1 = 14;
	int& c1 = a1;

	int b1 = 3;
	c1 = b1;

	//
	CUtil::csDebugOutput("%c", c1);

	//���۷����� �����ʹ� �� ���� �߿��� �������� �ֽ��ϴ�.
	//���۷����� �� �� ������ �Ǹ� ����� �ٸ� ���� ������ �� �� ����.
	//���۷����� �޸� �� �������� ���� �� �� �ִ�.
	//���ڷ� �����Ҷ� �״�� �����ϴ� ���� �����ڸ� ������ �� �׳� int& a = b �� ���� �� �Ͱ� �ϸƻ����մϴ�.
	  


	// ������
	int a = 10;
	int* p = &a;

	int b = 4;
	p = &b;   // p�� a�� ������ b�� ����Ų��.


	//�����Ϳ� �ٸ��� �迭�� ���۷����� ��� �����ϱ� ���ؼ� �ݵ�� �迭�� ũ�⸦ ����ؾ� �մϴ�.

	//�����ڸ� �����ϴ� ����� ������ �����ϱ��
	//���۷����� �����ϴ� Ÿ���� ũ��� ��� ���� �� �� ���� �ּҰ� ����� ������ ������ �˴ϴ�.
	
	const int& c = function();
	//���������� ��� ���۷����� ���ϰ��� �ް� �Ǹ� �ش� ���ϰ��� ������ ����˴ϴ�.�׸��� �� ����Ǵ� �Ⱓ�� ���۷����� ����� �� ���� �Դϴ�

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
	// � Ÿ���� �����ϴ���
	//typedef T value_type;

	// ������
	VectorA(int n = 1) : data(new T[n]), capacity(n), length(0) {}

	// �� �ڿ� ���ο� ���Ҹ� �߰��Ѵ�.
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

	// ������ ��ġ�� ���ҿ� �����Ѵ�.
	T operator[](int i) { return data[i]; }

	// x ��° ��ġ�� ���Ҹ� �����Ѵ�.
	void remove(int x) {
		for (int i = x + 1; i < length; i++) {
			data[i - 1] = data[i];
		}
		length--;
	}

	// ���� ������ ũ�⸦ ���Ѵ�.
	int size() { return length; }

	// i ��° ���ҿ� j ��° ���� ��ġ�� �ٲ۴�.
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
//Ŭ���� ���ø�

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
	
	// templdate�� ����	
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

// ����Ʈ ��� 
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
