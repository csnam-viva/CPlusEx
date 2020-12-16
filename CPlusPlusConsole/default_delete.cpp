#include <iostream>
using namespace std;
class MyPencil
{
public:
	MyPencil() {
		cout << "기본생성자" << endl;
	}
	MyPencil(const MyPencil& ref)
	{
		cout << "복사생성자" << endl;
	}
	MyPencil func_one() {
		MyPencil abc;
		cout << "func_one()" << endl;
		return abc;
	}
private:
	//MyPencil(int a) { int b = a; };

	int a = 10;
	int b = 20;
	int d {40};
	
};

class Pen {
public:
	Pen() {};
	Pen(const Pen& pen) noexcept {
		cout << "복사생성자" << endl;
		a = pen.a;
		b = pen.b;
		c = pen.c;
	};

	Pen(const Pen&& pen) noexcept {
		cout << "이동 생성자" << endl;
	};
	void alloc(int _a, int _b, int _c) { a = _a, b = _b, c = _c; };
	void print() { cout << "\t" << a << "\t" << b << "\t" << c << endl; };
private:
	int a = 10;
	int b = 20;
	int c{ 40 };

};
void main_default()
{

	MyPencil aa;
	MyPencil ab (aa);
	aa.func_one();

	Pen pen;
	pen.alloc(2, 3, 4);
	pen.print();

	Pen pen1(pen);
	pen1.print();

	Pen pen2 = pen;
	pen2.print();


	Pen pen3(move(pen));
	pen3.print();
	Pen pen4(static_cast<Pen&&>(pen));
	pen4.print();






	
}