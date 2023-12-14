#include<iostream>
using namespace std;
class Number
{
	int a,b,c;
	public:
		void accept()
		{
			cout<<"Enter three numbers :";
			cin>>a>>b>>c;
		}
		void display()
		{
			cout<<"Display Elements : "<<endl;
			cout<<"A :"<<a<<" B : "<<b<<" C : "<<c<<endl;
		}
		void operator-()
		{
			a=-a;
			b=-b;
			c=-c;
		}
};
int main()
{
	Number num;
	num.accept();
	cout<<"Number are :"<<endl;
	num.display();
	-num;
	cout<<"Negative numbers are :"<<endl;
	num.display();
}
