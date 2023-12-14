#include<iostream>
using namespace std;
struct Distance
{
	int feet;
	float inch;
}d1,d2,sum;
int main()
{
	cout<<"Enter 1st distance :";
	cout<<"Enter feet :";
	cin>>d1.feet;
	cout<<"Enter Inch :";
	cin>>d1.inch;
	
	cout<<"Enter 2st distance :";
	cout<<"Enter feet :";
	cin>>d2.feet;
	cout<<"Enter Inch :";
	cin>>d2.inch;
	sum.feet = d1.feet = d2.feet;
	sum.inch = d1.inch +d2.inch;
	
	// changing feet to inches if its greater than 12
	if(sum.inch >12)
	{
		int extra = sum.inch/12;
		sum.feet +=extra;
		sum.inch -= (extra*12);
	}
	cout<<"Sum of distance = "<<sum.feet<<" Feet"<<sum.inch<<" Inch";
}
