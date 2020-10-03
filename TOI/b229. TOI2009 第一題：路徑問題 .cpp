#include "pch.h"
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#define ll unsigned long long
using namespace std;
ll up[53], r[53], l[54], ans;
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	up[1] = 1, r[1] = 1, l[1] = 1;
	for (int i = 1; i <= n; i++)
	{
		up[i + 1] = r[i] + l[i] + up[i];
		r[i + 1] = r[i] + up[i];
		l[i + 1] = l[i] + up[i];
	}		
	ans = r[n] + l[n] + up[n];
	cout << ans;
}
