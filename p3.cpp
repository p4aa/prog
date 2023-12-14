#include<iostream>
using namespace std;
double Power(double n,int p)
{
	int i;
	double t=n;
	for(i=1;i<p;i++)
	{
		t*=n;
	}
	return(t);
}
double Power(double n)
{
	return n*n;
}
int main()
{
	int ch,p;
	double n;
	cout<<"Enter value :";
	cin>>n;
	cout<<"Enter 1 to enter custom power "<<endl<<"Enter 0 to use default Power";
	cin>>ch;
	if(ch==0)
	{
		cout<<double(Power(n))<<endl;
	}
	cout<<"Enter Power :";
	cin>>p;
	cout<<double(Power(n,p));
}
