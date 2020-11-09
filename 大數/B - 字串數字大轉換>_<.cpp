#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

int num1[1005], num2[1005], num3[1005];

string Plus(string a, string b) {
	int d1 = a.length(), d2 = b.length();
	for (int i = d1 - 1, j = 0; i >= 0; i--) {
		num1[j++] = a[i] - '0';
	}
	for (int i = d2 - 1, j = 0; i >= 0; i--) {
		num2[j++] = b[i] - '0';
	}
	string res;
	for (int i = 0; i < max(d1, d2); i++) {
		num3[i] += num1[i] + num2[i];
		num3[i + 1] += num3[i] / 10;
		num3[i] %= 10;
	}
	for (int i = 0; i <= max(d1, d2); i++) {
		res += (num3[i] + '0');
	}
	reverse(res.begin(), res.end());
	if (res[0] == '0') res.erase(0, 1);
	mem(num1), mem(num2), mem(num3);
	return res;
}

bool cmp(string a, string b) {
	if (a[0] == '-') return 0;
	if (a.length() == b.length()) {
		for (int i = 0; i < a.length(); i++) {
			if (a[i] != b[i]) return a[i] > b[i];
		}
	}
	return a.length() > b.length();
}

string Minus(string a, string b) {
	int d1 = a.length(), d2 = b.length();
	for (int i = d1 - 1, j = 0; i >= 0; i--) {
		num1[j++] = a[i] - '0';
	}
	for (int i = d2 - 1, j = 0; i >= 0; i--) {
		num2[j++] = b[i] - '0';
	}
	string res;
	bool s = cmp(a, b);
	if (s) {
		for (int i = 0; i < d1; i++) {
			num3[i] = num1[i] - num2[i];
			if (num3[i] < 0) {
				num3[i] += 10;
				num1[i + 1]--;
			}
			res += (num3[i] + '0');
		}
	}
	else {
		for (int i = 0; i < d2; i++) {
			num3[i] = num2[i] - num1[i];
			if (num3[i] < 0) {
				num3[i] += 10;
				num2[i + 1]--;
			}
			res += (num3[i] + '0');
		}
	}
	reverse(res.begin(), res.end());
	for (int i = 0; i < res.length(); i++) {
		if (res[i] == '0') res.erase(0, 1);
		else break;
	}
	mem(num1), mem(num2), mem(num3);
	return res;
}

string num[102], Ans[102];
int cnt[102];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) cin >> cnt[i];
	cin.ignore();
	int res = 0;
	while (t--) {
		string a;
		getline(cin, a);
		int d = a.length();
		int j = 0;
		for (int i = 0; i < d; i++) {
			if (a[i] == ' ') {
				j++;
				continue;
			}
			num[j] += a[i];
		}
		sort(num, num + j + 1, cmp);
		string ans = "0";
		for (int i = 0; i <= j; i++) {
			if (num[i][0] == '-') {
				num[i].erase(0, 1);
				ans = Minus(ans, num[i]);
			}
			else
				ans = Plus(ans, num[i]);
		}
		Ans[++res] = ans;
		for (int i = 0; i < 102; i++) num[i] = "";
	}
	string ans2;
	for (int i = 0; i < res; i++) {
		ans2 += Ans[cnt[i]];
		cout << Ans[i + 1];
		cout << '\n';
	}
	for (int i = 0; i < ans2.length(); i++) {
		cout << ans2[i];
		if (i % 3 == 2) cout << ' ';
	}
}
