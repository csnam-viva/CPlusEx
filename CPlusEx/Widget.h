#pragma once
class Widget
{
public:
	Widget();
	~Widget();
private:
	struct Impl {
		int aa;
	};
	Impl* pImpl;
};


