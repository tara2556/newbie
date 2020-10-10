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
#define ll long long
#define pi pair<int,int>
#define mk make_pair
using namespace std;
int brick[52];
int main()
{
	int n;
	int t = 0;
	while (cin >> n && n)
	{
		ll bricks_high = 0;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> brick[i];
			bricks_high += brick[i];
		}
		bricks_high /= n;
		for (int i = 0; i < n; i++)
		{
			ans += (abs(brick[i] - bricks_high));
		}
		cout << "Set #" << ++t << '\n' << "The minimum number of moves is " << ans / 2 << '.' << '\n';//大於平均的減少一塊，小於平均的隨之增加一塊
	}
}
