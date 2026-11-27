#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

constexpr int N = 1e6;
constexpr int md = 998244353;

vector<i64> D(N + 1), A(N + 1);
void init() {
	A[0] = 1;
	for (int i = 1; i <= N; i++) {
		A[i] = A[i - 1] * i % md;
	}
	D[0] = 1, D[1] = 0, D[2] = 1;
	for (int i = 3; i <= N; i++) {
		D[i] = (i - 1) * (D[i - 1] + D[i - 2]) % md;
	}
}

void solve() {
	int n;
	cin >> n;

	if (!(n & 1)) {
		cout << 1 << "\n";
		return;
	}
	if (n == 1) {
		cout << 0 << "\n";
		return;
	}

	cout << D[n] * A[n] % md << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}