#include<bits/stdc++.h>
using namespace std;
const int N=100000+5;
char s[N];
char s_new[N*2];
int p[N*2];
int Init()
{
    int len = strlen(s);
    s_new[0] = '$';
    s_new[1] = '#';
    int j = 2;
    for (int i = 0; i < len; i++)
    {
        s_new[j++] = s[i];
        s_new[j++] = '#';
    }
    s_new[j] = '\0';  //别忘了哦
    return j;  //返回s_new的长度
}
int Manacher()
{
    int len = Init();  //取得新字符串长度并完成向s_new的转换
    int maxLen = -1;   //最长回文长度
    int id;
    int mx = 0;
    for (int i = 1; i < len; i++)
    {
        if (i < mx)
            p[i] = min(p[2 * id - i], mx - i);  //需搞清楚上面那张图含义, mx和2*id-i的含义
        else
            p[i] = 1;

        while (s_new[i - p[i]] == s_new[i + p[i]])  //不需边界判断，因为左有'$',右有'\0'
            p[i]++;

        //我们每走一步i，都要和mx比较，我们希望mx尽可能的远，这样才能更有机会执行if (i < mx)这句代码，从而提高效率
        if (mx < i + p[i])
        {
            id = i;
            mx = i + p[i];
        }
        maxLen = max(maxLen, p[i] - 1);
    }
    return maxLen;
}
int main()
{
    while (printf("请输入字符串：\n"))
    {
        scanf("%s", s);
        printf("最长回文长度为 %d\n\n", Manacher());
    }
    return 0;
}
