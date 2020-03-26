#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;
class belenko
{
public:
	belenko()
	{
	}
	belenko(const char* one1)
	{
		cout<<one1<<endl;
	}
	virtual ~belenko()
	{
		cout<<typeid(*this).name()<<endl;
	}
};
class Ivan : public belenko
{
public:
	Ivan(const char* one1)
	{
		cout<<one1<<endl;
	}
	~Ivan()
	{
		cout<<typeid(*this).name()<<endl;
	}
};

int main()
{
	vector<belenko*> all;
	all.push_back(new belenko("belenko"));
	all.push_back(new Ivan("Ivan"));
	for(int i=0;i<all.size();i++)
		delete all[i];
	return 0;
}