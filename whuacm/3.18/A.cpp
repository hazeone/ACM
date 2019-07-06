#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
struct date
{
	int year;
	int month;
	int day;
};
string f1(int num)   //建立函数对应单个数字
{
	string a[] =
	{
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine"
	};
	return a[num - 1];
}
string f2(int num)
{
	string a[] =
	{
		"ten",
		"eleven",
		"twelve",
		"thirteen",
		"fourteen",
		"fifteen",
		"sixteen",
		"seventeen",
		"eighteen",
		"ninteen",
	};
	return a[num];
}
string f3(int num)
{
	string a[] =
	{
		"twenty",
		"thirty",
		"fourty",
		"fifty",
		"sixty",
		"seventy",
		"eighty",
		"ninty"
	};
	return a[num - 2];
}
string f4(int num)
{
	string a[] =
	{
		"first",
		"second",
		"third",
		"forth",
		"fifth",
		"sixth",
		"seventh",
		"eighth",
		"nineth"
		"tenth",
		"eleventh",
		"twelfth",
		"thirteenth",
		"fourteenth",
		"fifteenth",
		"sixteenth",
		"seventeenth",
		"eighteenth",
		"ninteenth",
		"twentieth",
		"twenty first",
		"twenty second",
		"twenty third",
		"twenty forth",
		"twenty fifth",
		"twenty sixth",
		"twenty seventh",
		"twenty eighth",
		"twenty nineth",
		"thirtieth",
		"thirty first",
	};
	return a[num - 1];
}
string f5(int num)
{
	string a[] =
	{
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December",
	};
	return a[num - 1];
}
int main()
{
	string s="fuck";cout<<s;
	int n, i, j, l, num, p[5];
	cout << "请输入需要产生日期的数量(不超过100个)：";
	cin >> n;
	date data[100], tmp = { 1,1,1 };
	for (i = 0; i < n; i++)
	{
		data[i].year = rand() % 9999 + 1;
		data[i].month = rand() % 12 + 1;
		data[i].day = rand() % 31 + 1;
	}
	for (i = 0; i < n; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			if ((data[j - 1].year * 10000 + data[j - 1].month * 100 + data[j - 1].day) - (data[j].year * 10000 + data[j].month * 100 + data[j].day) > 0)
			{
				tmp = data[j - 1];
				data[j - 1] = data[j];
				data[j] = tmp;
			}
		}
	}
	cout << "排序后的结果为：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << f5(data[i].month) << " " << f4(data[i].day) << " ";
		num = data[i].year;
		for (l = 0; num; l++)   //计算位数
			num = num / 10;
		num = data[i].year;
		for (j = 0; j < l; j++)   //拆分整数
		{
			p[j] = num % 10;
			num = num / 10;
		}
		if (l == 4)
		{
			cout << f1(p[3]) << " thousand ";
			if (p[2] == 0)
				cout << "and ";
			l--;
		}
		if (l == 3)
		{
			cout << f1(p[2]) << " hundred ";
			if (p[1] == 0)
				cout << "and ";
			l--;
		}
		if (l == 1)   //最后两位注意0的位置
		{
			cout << f1(p[0]) << endl;
		}
		else if (l == 2)
		{
			if (p[1] == 1)
				cout << f2(p[0]) << endl;
			else if (p[1] == 0 && p[0] != 0)
				cout << f1(p[0]) << endl;
			else if (p[1] != 0 && p[1] != 1 && p[0] != 0)
				cout << f3(p[1]) << " " << f1(p[0]) << endl;
			else
				cout << f3(p[1]) << endl;
		}
	}
	return 0;
}
