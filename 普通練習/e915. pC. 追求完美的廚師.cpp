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
pi food[100005];
bool cmp(pi a, pi b)
{
	return a.first*b.second > b.first*a.second;
}
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> food[i].first >> food[i].second;
	}
	sort(food, food + n, cmp);
	ll ans = 0;
	ll time = 0;
	for (int i = 0; i < n; i++)
	{
		time += food[i].second;
		ans += food[i].first*time;
	}
	cout << ans;
}
