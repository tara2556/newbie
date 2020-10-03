#include <pch.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#define ll long long
using namespace std;
int symbol[63];
const int maxn = 10000001, Maxn = 2000001;
int str[maxn], str1[Maxn], str2[Maxn];
void init_symbol()
{
	for (int i = 1; i < 63; i++)
	{
		symbol[i] = i;
	}
}
void init(string a, int *str)
{
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] >= 'a'&&a[i] <= 'z')
			str[i] = a[i] - 'a' + 1;
		else if (a[i] >= 'A'&&a[i] <= 'Z')
			str[i] = a[i] - 'A' + 27;
		else if (a[i] >= '0'&&a[i] <= '9')
			str[i] = a[i] - '0' + 53;
	}
}
void Symbol(int m)
{
	for (int j1 = 0; j1 < m; j1++)
		for (int i = 0; i < 63; i++)
		{
			if (symbol[i] == str1[j1])
				symbol[i] = str2[j1];
		}
}
int main()
{
	int n, m;
	cin.tie(0); ios_base::sync_with_stdio(0);
	cin >> n >> m;
	string a, b, c;
	cin >> a >> b >> c;
	init_symbol();
	init(a, str), init(b, str1), init(c, str2);
	Symbol(m);
	for (int i = 0; i < a.length(); i++)
	{
		a[i] = symbol[str[i]];
		if (a[i] <= 26)
			a[i] += 96;
		else if (a[i] <= 52)
		{
			a[i] += 38;
		}
		else
			a[i] -= 5;
	}
	cout<<a<<'\n';
}
