#include <bits/stdc++.h>
using namespace std;


int calc(int index, int start, int end, int v, vector<int>& seg) {
	if (start >= v) return seg[index];
	if (end < v) return 0;

	int mid = (start + end) / 2;
	return calc(2 * index, start, mid, v, seg) + calc(2 * index + 1, mid + 1, end, v, seg);
}

void update(int index, vector<int>& seg) {
	seg[index] = 1;
	while (index > 1) {
		index /= 2;
		seg[index] = seg[2 * index] + seg[2 * index + 1];
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N;
	cin >> N;

	int H = ceil(log2(N));
	int S = pow(2, H);

	vector<int>seg(2 * S);

	vector<int>L(N);
	vector<int>res(N);

	for (int i = 0;i < N;i++) cin >> L[i];

	int cnt = 0;
	while (cnt != N) {
		for (int i = 0;i < N;i++) {
			int tempC = calc(1, 0, S - 1, i, seg);
			if (L[i] == tempC) {
				res[cnt] = i + 1;
				cnt++;
				update(i + S, seg);
				L[i] = N;
				break;
			}
		}
	}

	for (int i = 0;i < N;i++) cout << res[i] << " ";
}
//https://acmicpc.net/problem/1138