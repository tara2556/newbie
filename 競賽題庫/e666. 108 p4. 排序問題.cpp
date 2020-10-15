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
int str[26];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		char a;
		cin >> a;
		str[a - 'A']++;
	}
	for (int i = 1; i < 26; i++)
		str[i] += str[i - 1];
	int t;
	for (int i = 0; i < m; i++)
	{

		cin >> t;
		for (int j = 0; j < 26; j++)
		{
			if (!j)
			{
				if (t <= str[j])
				{
					cout << char(j + 'A');
					break;
				}
			}
			else
			{
				if (t <= str[j] && t > str[j - 1])
				{
					cout << (char)(j + 'A');
					break;
				}
			}
		}
	}
	cout << '\n';
}
