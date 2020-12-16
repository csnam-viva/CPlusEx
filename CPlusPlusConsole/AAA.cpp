#include "AAA.h"

#include "MyString.h"

#include <vector>

class AImpl
{
public:
	AImpl()=default;

public: 
	vector<int> v;
	MyString _str;
};

AAA::AAA() {
	//pImpl = new AImpl();
	pImpl = std::make_shared<AImpl*>();
}

AAA::~AAA()
{
	delete pImpl;
}
