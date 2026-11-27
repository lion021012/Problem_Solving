#include <bits/stdc++.h>
using namespace std;

int w, h;
vector<int>dx = { 1,0,-1,0,1,1,-1,-1 };
vector<int>dy = { 0,1,0,-1,1,-1,1,-1 };

int calc(const pair<int, int>& now) {
	return 100 * now.first + now.second;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	while (true) {
		cin >> w >> h;

		if (w == 0 && h == 0) break;

		vector<vector<int>>grid(h, vector<int>(w));
		vector<pair<int, int>>land;

		for (int i = 0;i < h;i++) {
			for (int j = 0;j < w;j++) {
				cin >> grid[i][j];

				if (grid[i][j] == 1) land.push_back({ i,j });
			}
		}

		set<int>visited;
		int res = 0;

		for (int j = 0;j < land.size();j++) {
			int now = calc(land[j]);
			if (visited.find(now) != visited.end()) continue;

			queue<pair<int, int>>q;
			q.push(land[j]);
			visited.insert(now);
			res++;

			while (!q.empty()) {
				pair<int, int>cur = q.front();
				q.pop();

				for (int i = 0;i < 8;i++) {
					int nextY = cur.first + dy[i];
					int nextX = cur.second + dx[i];

					if ((0 <= nextY && nextY < h) & (0 <= nextX && nextX < w)) {
						if (grid[nextY][nextX] == 1) {
							if (visited.find(calc({ nextY, nextX })) == visited.end()) {
								q.push({ nextY,nextX });
								visited.insert(calc({ nextY, nextX }));
							}
						}
					}
				}
			}
		}

		cout << res << '\n';
	}
}
//https://acmicpc.net/problem/4963