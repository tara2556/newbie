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
#include <cstdlib>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
using namespace std;
priority_queue<int> q;
priority_queue<int, vector<int>, greater<int>> p;
int main()
{
	int n;
	while (cin >> n)
	{
		if (q.empty()) q.push(n);
		if (!q.empty() && n > q.top())
		{
			p.push(n);
		}
		else if (!p.empty() && n < p.top())
		{
			q.push(n);
		}
		if (q.size() > p.size() + 1)
		{
			int t = q.top();
			q.pop();
			p.push(t);
		}
		else if (p.size() > q.size() + 1)
		{
			int t = p.top();
			p.pop();
			q.push(t);
		}
		if (p.size() > q.size())
		{
			cout << p.top() << '\n';
		}
		else if (q.size() > p.size())
		{
			cout << q.top() << '\n';
		}
		else
		{
			cout << (p.top() + q.top()) / 2 << '\n';
		}

	}
}
