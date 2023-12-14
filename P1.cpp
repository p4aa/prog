#include<iostream>
using namespace std;
void swap(int &x, int &y)
{
	int temp;
	temp=x;
	x=y;
	y=temp;
}
int main()
{
	int a,b;
	cout<<"Enter 'a' value :";
	cin>>a;
	cout<<"Enter 'b' value :";
	cin>>b;
	cout<<"VAlues before swaping :";
	cout<<"A : "<<a<<"B : "<<b<<endl;
	swap(a,b);
	cout<<"Values After swap : ";
	cout<<"A : "<<a<<"B : "<<b;
}
