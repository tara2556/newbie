#include <pch.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <vector>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
using namespace std;
int arr[55];
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	ll  n;
	while (cin >> n)
	{
		ll ans = 0;
		int d = 1;
		arr[0] = 1, arr[1] = 2;
		for (int i = 2; i < 50; i++)
		{
			d += n;
			arr[i] = d + arr[i - 1];
		}
		for (int i = 0; i < 50; i++)
		{
			ans += arr[i];
		}
		cout << ans << '\n';
		memset(arr, 0, sizeof(arr));
	}
	
}
