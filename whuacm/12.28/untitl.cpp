#include<bits/stdc++.h>
using namespace std;
class Stu{
	private:
		string name;
		int score;
	public:
		Stu(string _name,int _score);
		friend bool operator < (const Stu&, const Stu&);
		void pt()
		{
			cout<<" name "<<name<<" score "<<score<<endl;
		}
};
Stu::Stu(string _name,int _score)
{
	name=_name;
	score=_score;
}
bool operator <(const Stu& A,const Stu& B)
{
	return A.score<B.score;
}
int main()
{
	Stu a[]={Stu("zhang",78),Stu("wang",80),Stu("zhao",92),Stu("chen",50),Stu("li",65)};
	sort(a,a+5);
	cout<<"min_score";
	a[0].pt();
	cout<<"max_score";
	a[4].pt();
}
