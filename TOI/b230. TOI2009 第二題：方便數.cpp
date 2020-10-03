#include "pch.h"
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#define ll long long
using namespace std;
int inten[10000];
int d;
void init()
{
	for (int i = 0; i < 10000; i++)
		inten[i] = i;
	int cnt = 3;
	for (int i = 1; i <= 65; i++)
		for (int j = i + 1; j <= 65; j++)
			for (int k = j + 1; k <= 65; k++)
			{
				d = i * j + j * k + i * k;
				if (d<10000) inten[d] = 0;
			}
}
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	init();
	int ans, cnt = 0, cnt2 = 0;
	while (cnt < n)
	{
		if (inten[cnt2])
			ans = inten[cnt2], cnt++;
		cnt2++;
	}
	cout << ans;
}
