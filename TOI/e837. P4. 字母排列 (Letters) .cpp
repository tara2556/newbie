#include <pch.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <vector>
#include <iomanip>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
using namespace std;
string ans[10005];
int num[10005];
int num2[10005];
bool cmp(int a, int b)
{
	if (num[a] == num[b])
		return a > b;
	else
		return num[a] > num[b];
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	string a;
	cin >> a;
	int d = a.length();
	int cnt = 1;
	int cnt2 = 0;
	bool c = 0;
	int jud;
	for (int i = 0; i < d; i++)
	{
		if (!i)
		{
			jud = a[i];
			ans[cnt2] += a[i];
			num2[cnt2] = cnt2;
		}
		else
		{
			int t = a[i] - 1;
			if (jud == t)
			{
				ans[cnt2] += a[i];
				cnt++;
				jud = a[i];
			}
			else
			{
				if (cnt > 1)
				{
					cnt2++;
					num2[cnt2] = cnt2;
					ans[cnt2] += a[i];
					jud = a[i];
					cnt = 1;
				}
				else
				{
					cnt = 1;
					cnt2++;
					num2[cnt2] = cnt2;
					ans[cnt2] += a[i];
					jud = a[i];
				}
			}
		}
	}
	for (int i = 0; i < cnt2+1; i++)
		num[i] = ans[i].size();
	sort(num2, num2 + cnt2 + 1, cmp);
	cout << num[num2[0]] << ' ' << ans[num2[0]] << '\n';


}
