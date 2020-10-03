#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#define ll long long
using namespace std;
int num1[501], num2[501];
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	string a, b;
	char c;
	while (cin >> a >> c >> b)
	{
		string ans;
		int d = a.length();
		int e = b.length();
		for (int i = d - 1, j = 0; i >= 0; i--)
			num1[j++] = a[i] - '0';
		for (int i = e - 1, j = 0; i >= 0; i--)
			num2[j++] = b[i] - '0';
		int num3[1002] = { 0 };
		int quotient[501] = { 0 };
		int remainder[501] = { 0 };
		string ch;
		bool cmp = 0;
		switch (c)
		{
		case '*':
			for (int i = 0; i < d; i++)
				for (int j = 0; j < e; j++)
				{
					num3[i + j] += num1[i] * num2[j];
				}
			for (int i = 0; i < 101; i++)
			{
				if (num3[i] >= 10)
				{
					num3[i + 1] += num3[i] / 10;
					num3[i] %= 10;
				}
			}
			for (int i = 0; i < d + e; i++)
			{
				ans += num3[i] + '0';
			}
			reverse(ans.begin(), ans.end());
			if (ans[0] == '0') ans.erase(0, 1);
			break;
		case '/':		
			for (int i = 0; i < d; i++)
				remainder[i] = a[i] - '0';
			for (int i = 0; i < d - e + 1; i++)
			{
				while (remainder[i] >= 0)
				{
					for (int j = 0; j < e; j++)
					{
						remainder[i + j] -= b[j] - '0';
						if (remainder[i + j] < 0 && j>0)
						{
							remainder[i + j - 1]--;
							remainder[i + j] += 10;
						}
					}
					quotient[i]++;
				}
				for (int j = 0; j < e; j++)
					remainder[i + j] += b[j] - '0';
				for (int j = i + e - 1; j >= i; j--)
				{
					if (remainder[j] >= 10)
					{
						remainder[j] -= 10;
						remainder[j - 1]++;
					}
				}
				quotient[i]--;
				remainder[i + 1] += remainder[i] * 10;
				remainder[i] = 0;
				ans += quotient[i] + '0';
				for (int i = 0; i < ans.length(); i++)
					if (ans[i] == '0') ans.erase(i--, 1);
					else break;
			}
			break;
		case '+':
			if (d > e)
			{
				for (int i = 0; i < d - e; i++)
					ch += '0';
				ch += b;
				b = ch;
				for (int i = d - 1, j = 0; i >= 0; i--)
				{
					num3[j++] = a[i] - '0' + b[i] - '0';
				}
				for (int i = 0; i < d+1; i++)
				{
					if (num3[i] >= 10)
					{
						num3[i + 1] += num3[i] / 10;
						num3[i] %= 10;
					}
					ans += num3[i] + '0';
				}
				reverse(ans.begin(), ans.end());
				for (int i = 0; i < ans.length(); i++)
					if (ans[i] == '0') ans.erase(i--, 1);
					else break;
			}
			else
			{
				for (int i = 0; i < e - d; i++)
					ch += '0';
				ch += a;
				a = ch;
				for (int i = e - 1, j = 0; i >= 0; i--)
				{
					num3[j++] = a[i] - '0' + b[i] - '0';
				}
				for (int i = 0; i < e + 1; i++)
				{
					if (num3[i] >= 10)
					{
						num3[i + 1] += num3[i] / 10;
						num3[i] %= 10;
					}
					ans += num3[i] + '0';
				}
				reverse(ans.begin(), ans.end());
				for (int i = 0; i < ans.length(); i++)
					if (ans[i] == '0') ans.erase(i--, 1);
					else break;
			}
			break;
		case '-':
			if (d > e) cmp = 1;
			else if (d < e) cmp = 0;
			else if (d == e)
			{
				for (int i = 0; i < d; i++)
				{
					if (a[i] > b[i])
					{
						cmp = 1;
						break;
					}
					else if (a[i] < b[i])
					{
						cmp = 0;
						break;
					}
					else continue;
				}
			}
			if (cmp)
			{			
				for (int i = 0; i < d; i++)
				{
					num1[i] = num1[i] - num2[i];
					if (num1[i] < 0)
					{
						num1[i] += 10;
						num1[i + 1]--;
					}
				}
				for (int i = 0; i < d; i++)
					ans += num1[i] + '0';
				reverse(ans.begin(), ans.end());
				for (int i = 0; i < ans.length(); i++)
					if (ans[i] == '0') ans.erase(i--, 1);
					else break;
			}
			else
			{				
				for (int i = 0; i < e; i++)
				{
					num2[i] = num2[i] - num1[i];
					if (num2[i] < 0)
					{
						num2[i] += 10;
						num2[i + 1]--;
					}
				}
				for (int i = 0; i < e; i++)
					ans += num2[i] + '0';
				ans += '-';
				reverse(ans.begin(), ans.end());
				for (int i = 0; i < ans.length(); i++)
					if (ans[i] == '0') ans.erase(i--, 1);
					else if(ans[i]<='9'&&ans[i]>'0') break;

			}
		}
		if (ans.empty()) cout << 0 << '\n';
		else
			cout << ans << '\n';
		memset(num1, 0, sizeof(num1));
		memset(num2, 0, sizeof(num2));
	}
}
