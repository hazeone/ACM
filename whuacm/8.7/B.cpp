#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int n;
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cout<<i<<" : NO"<<endl;
	}
	cout<<n<<" : ";
	for(int i=1;i<=n;i++)
	cout<<'a';
	cout<<endl;
	return 0;
}
