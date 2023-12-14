#include<iostream>
using namespace std;
class shape
{
	public: double a,b;
	void get_data()
	{
		cin>>a>>b;
	}
	virtual void display_area()=0;
};
class Rectangle:public shape
{
	public:void display_area()
	{
		cout<<"Area of rectangle :"<<a*b<<endl;
	}
};
int main()
{
	Rectangle r;
	shape *sr= &r;
	cout<<"Enter Length and breadth : ";
	sr->get_data();
	sr->display_area();
	return 0;
}
