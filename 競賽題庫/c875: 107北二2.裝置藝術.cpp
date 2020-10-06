#include <pch.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
using namespace std;
int can[1000005];
ll ans;
priority_queue<pi, vector<pi>, greater<pi>>p;
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int a, b, c;
	cin >> a >> b >> c;
	c /= b;
	for (int i = 0; i < a; i++)
	{
		cin >> can[i];
		can[i] /= b;
		p.push(mk(can[i], i));
	}
	while (!p.empty())
	{
		auto m = p.top();
		p.pop();
		if (m.second != 0)
		{
			if (can[m.second - 1] - m.first > c)
			{
				ans += can[m.second - 1] - m.first - c;
				can[m.second - 1] = m.first + c;
				auto pre = mk(can[m.second - 1], m.second - 1);
				p.push(pre);
			}
		}
		if (m.second != a - 1)
		{
			if (can[m.second + 1] - m.first > c)
			{
				ans += can[m.second + 1] - m.first - c;
				can[m.second + 1] = m.first + c;
				auto pre = mk(can[m.second + 1], m.second + 1);
				p.push(pre);
			}
		}
	}
	cout << ans;
}
