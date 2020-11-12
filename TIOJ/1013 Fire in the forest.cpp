#include <bits/stdc++.h>
#define ll long long
#define pi pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mem(a) memset((a),0,sizeof(a))
using namespace std;

int graph[10][17] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,1,1,1,0,1,1,1,1,1,1,1,0,0,1,1,0},
	{0,0,1,1,0,1,1,1,1,0,1,0,1,0,1,1,0},
	{0,1,1,1,1,1,1,0,1,0,0,1,0,0,1,0,0},
	{0,1,1,0,0,1,1,1,0,0,1,1,0,0,1,0,0},
	{0,0,1,1,1,1,1,0,0,1,1,0,1,0,1,1,0},
	{0,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,0},
	{0,1,1,1,1,1,0,0,0,0,1,0,1,1,1,0,0},
	{0,0,0,0,1,0,1,0,1,1,1,1,1,1,1,1,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

struct Point {
	int x, y;
};

Point mk(int x, int y) {
	Point res;
	res.x = x;
	res.y = y;
	return res;
}

int ma[10][17];
Point dirs[4] = { mk(1, 0), mk(-1, 0), mk(0, 1), mk(0, -1) };
int escape[10][17];

void bfs(Point s) {
	ma[s.x][s.y] = 1;
	vector<Point> fire;
	fire.pb(mk(s.x, s.y));
	while (!fire.empty()) {
		Point st = fire.front();
		fire.erase(fire.begin());
		for (int i = 0; i < 4; i++) {
			if (graph[st.x + dirs[i].x][st.y + dirs[i].y] && !ma[st.x + dirs[i].x][st.y + dirs[i].y]) {
				ma[st.x + dirs[i].x][st.y + dirs[i].y] = ma[st.x][st.y] + 1;
				fire.pb(mk(st.x + dirs[i].x, st.y + dirs[i].y));
			}
		}
	}
}

void Bfs(Point s, int t) {
	escape[s.x][s.y] = t;
	vector<Point> fire;
	if (ma[s.x][s.y] <= t) {
		return;
	}
	fire.pb(mk(s.x, s.y));
	while (!fire.empty()) {
		Point st = fire.front();
		fire.erase(fire.begin());
		for (int i = 0; i < 4; i++) {
			if (graph[st.x + dirs[i].x][st.y + dirs[i].y] == 1 && escape[st.x + dirs[i].x][st.y + dirs[i].y] == 0) {
				if (escape[st.x][st.y] + 1 < ma[st.x + dirs[i].x][st.y + dirs[i].y] || ma[st.x + dirs[i].x][st.y + dirs[i].y] == 0) {
					escape[st.x + dirs[i].x][st.y + dirs[i].y] = escape[st.x][st.y] + 1;
					fire.pb(mk(st.x + dirs[i].x, st.y + dirs[i].y));
				}
			}
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int fx, fy;
	cin >> fx >> fy;
	int t;
	cin >> t;
	int sx, sy, ex, ey;
	cin >> sx >> sy >> ex >> ey;
	graph[ex][ey] = 0;
	bfs(mk(fx, fy));
	graph[ex][ey] = 1;
	Bfs(mk(sx, sy), t);
	if (escape[ex][ey]) cout << escape[ex][ey]-t;
	else cout << "Help!";
}
