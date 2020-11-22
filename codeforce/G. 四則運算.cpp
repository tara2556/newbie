#include <bits/stdc++.h>
#include <unordered_set>
#define ll long long
#define pi pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mem(a) memset((a),0,sizeof(a))
#define mk make_pair
using namespace std;

vector<string> infixToPostfix(string s)
{
	stack<char> st;
	vector<string> result;
	for (int i = 0; i < s.length() * 2 + 1; i++) {
		if (!(i % 2)) {
			result.pb("1");
		}
		else {
			while (!st.empty() && (st.top() == '/' || st.top() == '*') && (s[i / 2] == '+' || s[i / 2] == '-')) {
				result.pb(string(1, st.top()));
				st.pop();
			}
			st.push(s[i / 2]);
		}
	}
	while (!st.empty())
	{
		result.pb(string(1, st.top()));
		st.pop();
	}
	return result;
}

int evalOP(int x, int y, string op) {
	if (op == "+") {
		return x + y;
	}
	if (op == "-") {
		return x - y;
	}
	if (op == "*") {
		return x * y;
	}
	if (op == "/") {
		return x / y;
	}
	if (op == "%") {
		return x % y;
	}
	return 0;
}

int evalr(vector<string>& tokens) {
	stack<int> evalStack;
	for (string token : tokens) {
		if (token.size() == 1 && (token[0] > '9' || token[0] < '0')) {
			int x = evalStack.top();
			evalStack.pop();
			int y = evalStack.top();
			evalStack.pop();
			evalStack.push(evalOP(x, y, token));
		}
		else {
			evalStack.push(atoi(token.c_str()));
		}
	}
	return evalStack.top();
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	string a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a.size() == 1) {
			if (a[0] == '-') cout << 0 << '\n';
			else if (a[0] == '+') cout << 2 << '\n';
			else
				cout << 1 << '\n';
			continue;
		}
		vector<string> ans = infixToPostfix(a);
		cout << evalr(ans) << '\n';
	}
}
