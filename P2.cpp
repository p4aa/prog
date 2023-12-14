#include<iostream>
using namespace std;
inline int cmp(int x,int y,int z)
{
	if(x>y && x>z)
		return(x);
	else if (y>z)
		return(y);
	else
		return(z);
}
int main()
{
	int x,y,z;
	cout<<"Enter X value :";
	cin>>x;
	cout<<"Enter Y value :";
	cin>>y;
	cout<<"Enter Z value :";
	cin>>z;
	cout<<cmp(x,y,z)<<" is Larger";
	
}
