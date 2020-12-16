// CPlusPlusConsole.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

//std::atomic<int> 를 동시성을 보장해준다.

void func1(std::atomic<int>& i)
{

    for (int j = 1; j <= 1000000; ++j)
        i++;
}

int main_0()
{
    std::atomic<int> i = 0;

    thread t1(func1, std::ref(i));
    thread t2(func1, std::ref(i));
    t1.join();
    t2.join();
    cout << i << endl;
    return 0;
}


//void func1(int& i)
//{
//
//    for (int j = 1; j <= 1000000; ++j)
//        i++;
//}
//
//void func2()
//{
//    int i = 0;
//    for (int j = 1; j <= 100; ++j)
//        std::cout << i++ << std::endl; 
//}
//int main_1()
//{
//    int  i = 0;
//   // thread t1(func1, std::ref(i));
//   // thread t2(func1, std::ref(i));
//    thread t3(func2);
//    //t1.join();
//    //t2.join();
//    t3.join();
//    std::cout << i << endl;
//    return 0;
//}


