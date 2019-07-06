#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
int n;
multiset<long long> s;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		s.insert(x);
	}
	for(multiset<long long>::iterator i=s.begin();i!=s.end();i++)
	cout<<*i<<" ";cout<<endl;
	cout<<s.size()<<endl;
	multiset<long long >::iterator p=s.find(66);
	if(p!=s.end())
	{
		s.erase(s.begin(),s.find(55));
		s.erase(s.find(55));
		for(multiset<long long>::iterator i=s.begin();i!=s.end();i++)
		cout<<*i<<" ";cout<<endl;
		cout<<*s.end()<<endl;
		cout<<*s.begin()<<endl;
	}
	return 0;
}
