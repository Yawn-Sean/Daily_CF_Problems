#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	i64 sum = 0;
	priority_queue<i64> que;
	for (int i = 1; i <= n; i++) {
		i64 x;
		cin >> x;
		sum += x;
		que.push(x);
	}

	i64 now = 0;
	for (int i = 1; i <= n; i++) {
		i64 x;
		cin >> x;
		sum += n * x;

		now += x;
		i64 t = que.top() + now;
		que.pop();
		sum -= t / 2;
		t -= t / 2;
		que.push(t - now);
	}

	cout << sum << "\n";
	return 0;
}