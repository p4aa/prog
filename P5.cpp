#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a,b,c,x1,x2,discriminant,realpart,imaginarypart;
	cout<<"Enter a,b,c values :";
	cin>>a>>b>>c;
	discriminant = b*b-4*a*c;
	
	if(discriminant>0)
	{
		x1= -b+(sqrt(discriminant))/2*a;
		x2 = -b-(sqrt(discriminant))/2*a;
		cout<<"Roots are real and different : "<<endl;
		cout<<"X1 : "<<x1<<endl;
		cout<<"X2 : "<<x2<<endl;
	}
	else if(discriminant==0)
	{
		x1 = -b/2*a;
		cout<<"Roots are real and same : "<<endl;
		cout<<"X1 & X2 : "<<x1;
	}
	else if(discriminant<0){
		realpart = -b/2*a;
		imaginarypart = sqrt(discriminant)/2*a;
		cout<<"Roots have two differnt complex roots"<<endl;
		cout<<"X1"<<realpart<<"+"<<imaginarypart<<"i";
		cout<<"X2"<<realpart<<"-"<<imaginarypart<<"i";
		
	}
	return 0;
}
