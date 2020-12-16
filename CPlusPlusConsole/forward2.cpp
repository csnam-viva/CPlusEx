#include <iostream>
#include <algorithm>
using namespace std;

class MemBlock
{

public:

	explicit MemBlock(size_t len):_len(len), _data( new int[len])
	{
		cout << "MB(size_t len):" << _len << endl;
	}
	~MemBlock(){
		cout << "~MB():" << _len << endl;
		if (_data != nullptr)
		{
			cout << "delete resource" << endl;
			delete[] _data;
		}
	}

	//복사생성자
	MemBlock(const MemBlock& other) : _len(other._len),_data(new int[other._len])
	{
		cout << "복사생성자 MB(size_t len):" << other._len << endl;
		std::copy(other._data, other._data + _len, _data);
	}
	// 대입연산자
	MemBlock& operator=(const MemBlock& other)
	{
		cout << "대입연산자 MB(size_t len):" << other._len << endl;
		if (this != &other)
		{
			delete[] _data;
			_len = other._len;
			_data = new int[other._len];
			copy(other._data,other._data+_len,_data);
		}
		return *this;
	}
	
	// Move 생성자
	MemBlock(MemBlock&& other) : _data(nullptr),_len(0)
	{
		cout << "Move 생성자 MemBlock(MemBlock&& other)" << other._len << endl;
		_data = other._data;
		_len = other._len;

		other._data = nullptr;
		other._len = 0;
	}
	// Move 대입연상자 

	MemBlock& operator=(MemBlock&& other)
	{
		cout << "Move 대입연산자 MemBlock(MemBlock&& other)" << other._len << endl;
		if (this != &other)
		{
			delete[] _data;
			_data = other._data;
			_len = other._len;

			other._data = nullptr;
			other._len = 0;
		}
		return *this;

	}

	//객체 내부 변수 변경 불가.
	//const 함수만 호출 가능.
	size_t Length() const {
		return _len;
	}

private:
	size_t _len;
	int* _data;
};

#include <vector>
//int main_forward2()
int main_forward2()
{
	vector<MemBlock> v;

	v.push_back(MemBlock(10));
	cout << "------------" << endl;
	v.push_back(MemBlock(5));
	cout << "------------" << endl;
	v[0] = MemBlock(50);
	cout << "------------" << endl;

	v.insert(v.begin() + 1, MemBlock(30));
	cout << "------------" << endl;
	return 1;
}