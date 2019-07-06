#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        vector<long long> sum(A.size()+1);
        sum[0] = 0;
        for(int i = 0; i < (int)A.size(); i ++)
        {
            sum[i + 1] = sum[i] + A[i];
        }
        vector<int> sk(A.size()+1);
        int top = 0;
        int ans = -1;
        for(int i = A.size(); i > 0; i --)
        {
            while(top != 0 && sum[sk[top]] <= sum[i])
            {
                top --;
            }
            sk[++ top] = i;
            int x = K + sum[i - 1];
            int l = 1, r = top, mid, tmp;
            while(l < r)
            {
                mid = (l + r + 1) >> 1;
                if(sum[sk[mid]] < x)
                {
                    r = mid-1;
                }
                else l = mid;
            }
            if(sum[sk[l]] >= x) tmp = sk[l] - i + 1;
            else continue;
            cout<<l<<"_____"<<i<<endl;
            if(ans == -1) ans = tmp;
            else ans = min(ans, tmp);
        }
        return ans;
    }
};
int main()
{
	vector<int>num;
	int k=3;
	num.push_back(2);
	num.push_back(-1);
	num.push_back(2);
	Solution SS;
	cout<<SS.shortestSubarray(num,k);
	return 0;
}
