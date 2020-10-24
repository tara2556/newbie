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
#include <sstream>
#include <stack>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
#define fi first
#define se second
using namespace std;
vector<int> te_queue;
set<int> group[1005];
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int t;
	int cnt = 1;
	while (cin >> t && t)
	{
		te_queue.clear();
		for (int i = 0; i < 1005;i++) group[i].clear();
		cout << "Scenario #" << cnt++ << '\n';
		for (int i = 0; i < t; i++)
		{
			int n;
			cin >> n;
			for (int j = 0; j < n; j++)
			{
				int k;
				cin >> k;
				group[i].insert(k);
			}
		}
		string a;
		while (cin >> a)
		{
			if (a == "ENQUEUE")
			{
				int k;
				cin >> k;
				int team_num;
				for (int i = 0; i < t; i++)
				{
					int t = group[i].count(k);
					if (t)
					{
						team_num = i;
						break;
					}
				}
				bool cmp = 0;
				vector<int>::reverse_iterator it;
				for (it = te_queue.rbegin(); it != te_queue.rend(); it++)
				{
					if (group[team_num].count(*it))
					{
						cmp = 1;
						break;
					}
				}
				if (!cmp) te_queue.push_back(k);
				else te_queue.insert(it.base(), k);
			}
			else if (a == "DEQUEUE")
			{
				cout << te_queue.front() << '\n';
				te_queue.erase(te_queue.begin());
			}
			else
			{
				cout << '\n';
				break;
			}
		}
	}
}
