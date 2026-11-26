#include <bits/stdc++.h>
using namespace std;

int startX, startY, endX, endY;
int n;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int T;
	cin >> T;

	while (T--) {
		cin >> startX >> startY >> endX >> endY;
		cin >> n;

		vector<vector<int>>g(n, vector<int>(3));

		for (int i = 0;i < n;i++) {
			cin >> g[i][0] >> g[i][1] >> g[i][2];
		}

		vector<int>s1;
		set<int>s2;

		for (int i = 0;i < n;i++) {
			int len1 = pow((startX - g[i][0]), 2) + pow(startY - g[i][1], 2);
			int len2 = pow(endX - g[i][0], 2) + pow(endY - g[i][1], 2);

			if (len1 > pow(g[i][2], 2)) s1.push_back(i);
			if (len2 > pow(g[i][2], 2)) s2.insert(i);
		}

		int intersection = 0;
		for (int i = 0;i < s1.size();i++) {
			if (s2.find(s1[i]) != s2.end()) intersection++;
		}
		cout << s1.size() + s2.size() - 2 * intersection << '\n';
	}
}
//https://acmicpc.net/problem/1004