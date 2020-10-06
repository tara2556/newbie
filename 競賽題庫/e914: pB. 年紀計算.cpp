#include <pch.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#define ll long long
#define pi pair
#define mk make_pair
using namespace std;
map<int, int> old;
void form()
{
	for (int i = 1; i <= 99; i++)
	{
		if (i % 10)
		{
			int cnt = 0;
			int t = i;
			int n1 = i % 10;
			int n2 = i / 10;
			int j = n1 * 10 + n2;
			if (t > j)
			{
				while (t != 2 * j)
				{
					t++, j++, cnt++;
					if (t > 99)
					{
						break;
					}
				}
				if (t > 99)
				{
					if (old[cnt] < 1)
						old[cnt] = 0;
				}
				else
					old[cnt] = j;
			}
			else
			{
				while (j != 2 * t)
				{
					t++, j++, cnt++;
					if (j > 99)
					{
						break;
					}
				}
				if (j > 99)
				{
					if (old[cnt] < 1)
						old[cnt] = 0;
				}
				else
					old[cnt] = t;
			}
		}
	}
}
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	form();
	if (old[n] == 0)
		cout << "no answer";
	else if(old[n]-n != 1)
		cout << old[n] - n;
	else if(old[n] - n == 1)
		cout << "no answer";
}
