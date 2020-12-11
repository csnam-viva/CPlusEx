﻿// NugetTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


#include <windows.h>
#include <iostream>

#include <cpprest/http_client.h>
#include <tinyxml.h>

int main()
{
    


}
void tiny_xml_test()
{
	TiXmlDocument doc;
	TiXmlDeclaration* pDec1 = new TiXmlDeclaration("1.0", "", "");
	doc.LinkEndChild(pDec1);

	//루트 노드 추가
	TiXmlElement* pRoot = new TiXmlElement("DB");
	doc.LinkEndChild(pRoot);

	//주석 문장 추가
	TiXmlComment* pComment = new TiXmlComment();
	pComment->SetValue("This is score DB");
	pRoot->LinkEndChild(pComment);

	// 하위노드 및 데이터 추가
	TiXmlElement* pElem = new TiXmlElement("class1");
	pRoot->LinkEndChild(pElem);
	TiXmlElement* pElem0 = new TiXmlElement("Teacher");
	pElem0->LinkEndChild(new TiXmlElement("JJJ"));
	pElem->LinkEndChild(pElem0);

	//하위노드 및 속성 추가
	TiXmlElement* pSubElem = new TiXmlElement("English");
	pElem->LinkEndChild(pSubElem);
	pSubElem->SetAttribute("name", "score");
	pSubElem->SetAttribute("aa", 100);
	pSubElem->SetAttribute("bb", 50);
	pSubElem->SetAttribute("cc", 90);

	pSubElem = new TiXmlElement("Math");
	pElem->LinkEndChild(pSubElem);
	pSubElem->SetAttribute("name", "score");
	pSubElem->SetAttribute("aa", 90);
	pSubElem->SetAttribute("bb", 70);
	pSubElem->SetAttribute("cc", 95);

	pElem = new TiXmlElement("class2");
	pRoot->LinkEndChild(pElem);
	pElem0 = new TiXmlElement("Teacher");
	pElem0->LinkEndChild(new TiXmlElement("SSS"));
	pElem->LinkEndChild(pElem0);

	pSubElem = new TiXmlElement("English");
	pElem->LinkEndChild(pSubElem);
	pSubElem->SetAttribute("name", "score");
	pSubElem->SetAttribute("ab", 70);
	pSubElem->SetAttribute("vc", 90);
	pSubElem->SetAttribute("ds", 30);

	pSubElem = new TiXmlElement("Math");
	pElem->LinkEndChild(pSubElem);
	pSubElem->SetAttribute("name", "score");
	pSubElem->SetAttribute("ab", 60);
	pSubElem->SetAttribute("vc", 70);
	pSubElem->SetAttribute("ds", 25);

	doc.SaveFile("Test.xml");

}
void http_client_test()
{

    std::wcout.imbue(std::locale("kor"));
    web::http::client::http_client client(L"http://www.naver.com/index.html");



    utility::string_t response =
        client.request(web::http::methods::GET).get().extract_string().get();
    std::wcout << response.c_str() << std::endl;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
