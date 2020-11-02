#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
#define fi first
#define se second
#define mem(a) memset((a),0,sizeof(a))
using namespace std;
struct Point {
	int x, y;
	Point(int x = 0, int y = 0) :x(x), y(y) {}
};

inline bool asser(const Point& p) {
	return (p.x < 5 && p.x >= 0 && p.y < 5 && p.y >= 0);
}

vector<string> grid;
int main() {
	int t = 1;
	while (1) {
		grid.clear();
		Point block_p;
		for (int i = 0; i < 5; i++) {
			string res;
			for (int j = 0; j < 5; j++) {
				char c;
				c = getchar();
				if (!j&&c == 'Z') return 0;		
				res += c;
				if (c == ' ') {
					block_p = Point(i, j);
				}
			}
			if (res.length() == 4) {
				block_p = Point(i, 4);
				continue;
			}
			grid.push_back(res);
		}
		string it;
		while (1) {
			string res;
			getline(cin, res);
			it += res;
			bool cmp = 0;
			for (int i = 0; i < res.length(); i++) {
				if (res[i] == '0') {
					cmp = 1;
					break;
				}
			}
			if (cmp) break;
		}
		int d2 = it.length();
		if (it[d2 - 1] == 'Z') break;
		bool cmp = 0;
		Point as;
		for (int i = 0; i < d2; i++) {
			switch (it[i]) {
			case 'A':
				as.x = block_p.x - 1;
				as.y = block_p.y;
				if (asser(as)) {
					swap(grid[as.x][as.y], grid[block_p.x][block_p.y]);
					block_p = Point(block_p.x - 1, block_p.y);
				}
				else {
					cmp = 1;
					break;
				}
				break;
			case 'B':
				as.x = block_p.x + 1;
				as.y = block_p.y;
				if (asser(as)) {
					swap(grid[as.x][as.y], grid[block_p.x][block_p.y]);
					block_p = Point(block_p.x + 1, block_p.y);
				}
				else {
					cmp = 1;
					break;
				}
				break;
			case 'L':
				as.x = block_p.x;
				as.y = block_p.y - 1;
				if (asser(as)) {
					swap(grid[as.x][as.y], grid[block_p.x][block_p.y]);
					block_p = Point(block_p.x, block_p.y - 1);
				}
				else {
					cmp = 1;
					break;
				}
				break;
			case 'R':
				as.x = block_p.x;
				as.y = block_p.y + 1;
				if (asser(as)) {
					swap(grid[as.x][as.y], grid[block_p.x][block_p.y]);
					block_p = Point(block_p.x, block_p.y + 1);
				}
				else {
					cmp = 1;
					break;
				}
				break;
			case '0':
				break;
			default:
				cmp = 1;
				break;
			}
		}
		cout << "Puzzle #" << t++ << " :" << '\n';
		if (cmp) {
			cout << "This puzzle has no final configuration." << '\n';
		}
		else {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (j)
						cout << ' ' << grid[i][j];
					else
						cout << grid[i][j];
				}
				cout << '\n';
			}
		}
	}
}
