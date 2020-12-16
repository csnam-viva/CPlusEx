#include <iostream>
using namespace std;


struct Pen
{
	int a;
	int b; 
	Pen(int _a, int _b)
	{
		a = _a;
		b = _b;
	};
	void Print() {
		cout << "\ta=" << a << "\tb=" << b << endl;
	};
};

template <typename T, typename A1, typename A2>
T* Factory(A1 a1, A2 a2)
{
	return new T(a1, a2);
}



class RefPen
{
public:
	RefPen(int& a, int& b) {};
	//RefPen(const int& a, const int& b) = default;
	//RefPen(int&& a, int&& b) = default;
	void Print() {
		cout << "\ta=" << a << "\tb=" << b << endl;
	};
	int a;
	int b;
};

template <typename T, typename B1, typename B2>
T* RefFactory(B1&& b1, B2&& b2)
{
	//return new T(static_cast<B1&&>(b1), static_cast<B2&&>(b2));

	return new T(forward<B1>(b1),forward<B2>(b2));
}

void main_forward1()
{

	//Pen* pen = Factory<Pen>(4, 5);
	//pen->Print();

	int a = 6; int b = 7;


	RefPen* refpen = RefFactory<RefPen>(a, b);

	//RefPen* refpen = RefFactory<RefPen>(8, 7);
	refpen->Print();

}