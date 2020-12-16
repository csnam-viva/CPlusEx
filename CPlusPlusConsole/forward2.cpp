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

	//���������
	MemBlock(const MemBlock& other) : _len(other._len),_data(new int[other._len])
	{
		cout << "��������� MB(size_t len):" << other._len << endl;
		std::copy(other._data, other._data + _len, _data);
	}
	// ���Կ�����
	MemBlock& operator=(const MemBlock& other)
	{
		cout << "���Կ����� MB(size_t len):" << other._len << endl;
		if (this != &other)
		{
			delete[] _data;
			_len = other._len;
			_data = new int[other._len];
			copy(other._data,other._data+_len,_data);
		}
		return *this;
	}
	
	// Move ������
	MemBlock(MemBlock&& other) : _data(nullptr),_len(0)
	{
		cout << "Move ������ MemBlock(MemBlock&& other)" << other._len << endl;
		_data = other._data;
		_len = other._len;

		other._data = nullptr;
		other._len = 0;
	}
	// Move ���Կ����� 

	MemBlock& operator=(MemBlock&& other)
	{
		cout << "Move ���Կ����� MemBlock(MemBlock&& other)" << other._len << endl;
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

	//��ü ���� ���� ���� �Ұ�.
	//const �Լ��� ȣ�� ����.
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