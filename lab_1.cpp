#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;
class belenko
{
public:
	belenko()
	{
		cout<<"construct base"<<endl;
	}
	virtual ~belenko()
	{
		cout<<"destruct base"<<endl;
	}
};
class Ivan : public belenko
{
public:
	Ivan()
	{
		cout<<"construct derivative"<<endl;
	}
	~Ivan()
	{
		cout<<"denstruct derivative"<<endl;
	}
};
void del(vector<belenko*> all)
{
	for(int i=0;i<all.size();i++)
		delete all[i];
}
int main()
{
	vector<belenko*> all;
	for(int i=0;i<1;i++)
	{
		all.push_back(new belenko);
		all.push_back(new Ivan);
	}
	del(all);
	return 0;
}