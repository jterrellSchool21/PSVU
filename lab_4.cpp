#include <iostream>
#include <vector>
using namespace std;
class parent
{
public:
	long *x=new long[20];
	virtual void init()
	{
		for(int i=0;i<20;i++)
		{
			x[i]=i+1;
		}
	}
	virtual void print()
	{
		for(int i=0;i<20;i++)
			cout<<this->x[i]<<"\t";
		cout<<endl;
	}

};

class child:public parent
{
public:
	void init() override
	{
		for(int i=0;i<20;i++)
		{
			x[i]=i+101;
		}
	}
	void print() override
	{
		for(int i=0;i<20;i++)
			cout<<this->x[i]<<"\t";
		cout<<endl;
	}
};
void create(vector<parent*> &mas)
{
	mas.push_back(new parent);
	mas.push_back(new child);
}
void init(vector<parent*> mas1)
{
	for(int i=0;i<mas1.size();i++)
	{
		mas1[i]->init();
	}
}
void del(vector<parent*> mas)
{
	for(int i=0;i<mas.size();i++)
		delete mas[i];
}
int main()
{
	cout<<"First"<<endl;
	vector<parent*> mas;
	create(mas);
	init(mas);
	for(int i=0;i<mas.size();i++)
	{
		mas[i]->print();
	}
	del(mas);
	return 0;
}