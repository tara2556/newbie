#include <bits/stdc++.h>
#include <random>
#define ll long long
#define pb push_back
#define pi pair<int, int>
#define x first
#define y second
#define mem(a) memset(a, 0, sizeof(a))
using namespace std;

random_device rd;
mt19937_64 geneator(rd());

int other(int doorA, int doorB, int n)
{
	int doorC;
	uniform_int_distribution<int> option(0, n - 2);
	if (doorA == doorB)
	{
		doorC = option(geneator);
		if (doorC >= doorA)
			++doorC;
	}
	else
	{
		for (doorC = 0; doorC == doorA || doorC == doorB; ++doorC)
		{
			// empty
		}
	}
	return doorC;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int n, host_car = 0, choose = 0, host_open = 0, mod, res;
	double win_count, lose_count, t;
	win_count = 0, lose_count = 0;
	cin >> t >> n >> mod;
	vector<string> door(n);
	uniform_int_distribution<int> unif(0, n-1);
	res = t;
	while (t--) {
		for (int i = 0; i < n; i++) door[i] = "goat";
		host_car = 0, choose = 0, host_open = 0;
		if (mod) {
			choose = unif(geneator);
			host_car = unif(geneator);
			host_open = other(choose, host_car, n);
			int select_door = other(host_open, choose, n);
			if (select_door == host_car) win_count++;
			else lose_count++;
			door[host_car] = "car";
			cout << door[choose] << '\n';
		}
		else {
			choose = unif(geneator);
			host_car = unif(geneator);
			host_open = other(choose, host_car, n);
			int select_door = choose;
			if (select_door == host_car) win_count++;
			else lose_count++;
			door[host_car] = "car";
			cout << door[choose] << '\n';
		}
	}
	double i, j;
	i = (double)((double)win_count / (double)res);
	j = (double)((double)lose_count / (double)res);
	if (mod) cout << "select change:\n";
	else cout << "select original:\n";
	cout << fixed << setprecision(2) <<"Win Rate: "<< i * 100 << "%\nLose Rate: " << j * 100 << "% \n";

}

