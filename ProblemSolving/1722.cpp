#include <bits/stdc++.h>
using namespace std;

long long N, Q;

long long facto(long long n) {
	if (n <= 1) return 1;
	else return n * facto(n - 1);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> Q;

	if (Q == 1) {
		long long t;
		cin >> t;
		t--;

		vector<int>res(N);
		vector<int>name(N);
		for (int i = 1;i <= N;i++) name[i - 1] = i;

		int index = 0;

		while (index < N) {
			int cnt = 0;
			long long now = facto(N - index - 1);
			while (t >= now) {
				cnt++;
				t -= now;
			}

			int targetIndex;
			for (targetIndex = 0;targetIndex < N;targetIndex++) {
				if (name[targetIndex] == 0) {
					continue;
				}
				if (cnt == 0) break;
				cnt--;
			}

			res[index] = name[targetIndex];
			name[targetIndex] = 0;

			index++;
		}

		for (int i = 0;i < N;i++) cout << res[i] << " ";
	}
	else {
		vector<int>L(N);
		vector<int>name(N);
		for (int i = 0;i < N;i++) {
			cin >> L[i];
			name[i] = i + 1;
		}

		long long res = 1;

		for (int i = 0;i < N;i++) {
			int cnt = 0;

			for (int j = 0;j < L[i] - 1;j++) {
				if (name[j] != 0) cnt++;
			}

			res += cnt * facto(N - i - 1);
			name[L[i] - 1] = 0;
		}

		cout << res;
	}
}
//https://acmicpc.net/problem/1722