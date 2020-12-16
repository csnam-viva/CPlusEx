#include "pch.h"
#include "EffectiveModern.h"
#include <thread>
using namespace GE_;
using namespace std;
void EffectiveModern::A1_one()
{
	dbg::out() << wd.wABC.c_str() <<"int =>" << wd.ab <<  wd.ac << std::endl;
}

void EffectiveModern::funcA(int& i)
{
	for (int j = 1; j <= 1000000; ++j)
		i++;
}
void EffectiveModern::A2_automic()
{
	int a = 0;
	thread t1(&funcA, &a);
	thread t2(&funcA, &a);
	t1.join();
	t2.join();
	dbg::out() << "a= " << a << endl;


}
