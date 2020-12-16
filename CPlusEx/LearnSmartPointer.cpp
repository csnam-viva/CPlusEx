#include "pch.h"
#include "LearnSmartPointer.h"

void LearnSmartPointer::MakeSong()
{
	unique_ptr<song> song1(new song(_TEXT("song_1"),
		_TEXT("123")));
	tstring titles = song1->title;
}

void LearnSmartPointer::SmartPointerDemo()
{
	unique_ptr<LargeObj> pLO(new LargeObj());

	pLO->DoSomething();
	ProcessLargeObj(*pLO);

}
void LearnSmartPointer::ProcessLargeObj(LargeObj& lo)
{
	lo.DoSomething();
}


void LearnSmartPointer::SmartPonterDemo2()
{
	unique_ptr<LargeObj> pLarge(new LargeObj());
	pLarge->DoSomething();



	LargeObj* rawPointer = pLarge.get();
	rawPointer->DoSomething();


	/*pLarge.reset();
	pLarge->DoSomething();*/

}
void LearnSmartPointer::SmartPonterDemo3()
{
	unique_ptr<LargeObj> pLargeObj(new LargeObj());

	pLargeObj->DoSomething();
	unique_ptr<LargeObj> ab = std::move(pLargeObj);
	ab->DoSomething();
	pLargeObj->DoSomething();

}
void LearnSmartPointer::SmartPonterDemo4()
{
//���� �����ϱ� 
	 auto p = make_unique<LargeObj>();
	 p->DoSomething();



	 vector<unique_ptr<LargeObj>> vc;
	 //->DoSomething();vc.push_back(p);
	 vc.push_back(move(p)); //���� �����ڿ� ������ ������� �ʱ⿡ std::move�� ����Ѵ�.

	 // emplace_back  //�ӽð�ü�� ������ copy,move�� ���� �ʾƵ� ���ɻ� ������.
	   //������ �ʿ��� ���ڸ� ������ �޾ƻ� ������.
	 vc.push_back(unique_ptr<LargeObj>(new LargeObj()));
	 vc.emplace_back(new LargeObj());

	 vc.front()->DoSomething();


}

void LearnSmartPointer::SharePinterDomo1()
{
	shared_ptr<ShareObj> p1(new ShareObj(10));
	shared_ptr<ShareObj> p2(p1);

	/*vector<shared_ptr<ShareObj>> vec;
	vec.push_back(p1);
	vec.push_back(p2);
	vec.emplace_back(new ShareObj(11));*/

	TRACE("use count =%d \n", p1.use_count());

	//vec.erase(vec.begin());
	TRACE("use count =%d \n", p1.use_count());

	//vec.erase(vec.begin());
	TRACE("use count =%d \n", p1.use_count());

	//vec.erase(vec.begin());
	TRACE("use count =%d \n", p1.use_count());


	

	

	

}

