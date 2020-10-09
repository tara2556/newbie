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
#define ll long long
#define pi pair<int,int>
#define mk make_pair
using namespace std;
int number, mthsmall;
int calculate(int i, int j)
{
	return i * i + j * j + (number - 10000)*i + j;
}
bool NoBigThanSmall(int value)
{
	int total = 0, right, left, middle, count;
	for (int i = 0; i < number; ++i)
	{
		left = 1, right = number, count = 0;
		while (left <= right)
		{
			middle = (right + left) / 2;
			if (calculate(i, middle - 1) <= value)
				count = middle, left = middle + 1;
			else
				right = middle - 1;
		}
		total += count;
		if (total >= mthsmall) return true;
	}
	return false;
}
int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
	int upper, lower, middle, answer;
	while (cin >> number >> mthsmall)
	{
		upper = 214783647, lower = -upper;
		while (lower <= upper)
		{
			middle = (lower + upper) / 2;
			if (NoBigThanSmall(middle))
				answer = middle, upper = middle - 1;
			else
				lower = middle + 1;
		}
		cout << answer << '\n';
	}
}
