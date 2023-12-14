#include<iostream>
using namespace std;
int main()
{
	int var1,var2;
	float var3;
	cout<<"Enter the dividend :"<<endl;
	cin>>var1;
	cout<<"Enter the divisor : "<<endl;
	cin>>var2;
	try
	{
		if(var2!=0)
		{
			var3 = var1/var2;
			cout<<"Outcome : "<<var3<<endl;
		}
		else
		{
			throw(var2);
		}
	}
	catch(int exc)
	{
		cout<<"Division by 0 is not possible try with different number..."<<endl;
	}
}
