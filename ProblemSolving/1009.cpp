#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int T;
	cin >> T;

	vector<vector<int>>v = {
		{ 10 }, { 1 },{ 2,4,8,6 },{ 3,9,7,1 },{ 4,6 },{ 5 },{ 6 },{ 7,9,3,1 },{ 8,4,2,6 },{ 9,1 }
	};

	while (T--) {
		int a, b;
		cin >> a >> b;
		a %= 10;

		int len = size(v[a]);
		int index = b % len - 1;

		if (index < 0) index += len;

		cout << v[a][index] << '\n';
	}
}
//https://acmicpc.net/problem/1009