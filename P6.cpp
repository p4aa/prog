#include<iostream>
using namespace std;
int main()
{
	char op;
	float num1,num2;
	cout<<"Enter operatore : +,-,*,/"<<endl;
	cin>>op;
	cout<<"Enter num1 value:";
	cin>>num1;
	cout<<"Enter Num2 value :";
	cin>>num2;
	switch(op)
	{
		case'+':
			cout<<num1<<"+"<<num2<<"="<<num1+num2;
			break;
		case'-':
			cout<<num1<<"-"<<num2<<"="<<num1-num2;
			break;
		case'*':
			cout<<num1<<"*"<<num2<<"="<<num1*num2;
			break;
		case'/':
			cout<<num1<<"/"<<num2<<"="<<num1/num2;
			break;
		default:
			cout<<"Incorrect Operator";
			break;
	}
}
