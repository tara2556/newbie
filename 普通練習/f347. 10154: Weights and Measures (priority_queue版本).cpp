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
int tu[5700], de[5700];
int num[5700];
bool cmp(int a, int b)
{
	
	return de[a] < de[b];
}
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int cnt = 0;
	while (cin >> tu[cnt] >> de[cnt] && !cin.eof())
	{
		de[cnt] -= tu[cnt];
		num[cnt] = cnt++;
	}
	sort(num, num + cnt, cmp);
	priority_queue<int>pq;
	int t = 0;
	for (int i = 0; i < cnt; i++)
	{
		pq.push(tu[num[i]]);
		if (de[num[i]] >= t)
			t += tu[num[i]];
		else
		{
			t -= pq.top();
			pq.pop();
			t += tu[num[i]];
		}
	}
	cout << pq.size() << '\n';
}
