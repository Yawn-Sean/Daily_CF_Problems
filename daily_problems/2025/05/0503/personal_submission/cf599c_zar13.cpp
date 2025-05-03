#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 5;
struct node {
	int val, idx;
} H[N];
bool cmp(node &a, node & b) {
	if (a.val == b.val) {
		return a.idx < b.idx;
	}
	return a.val < b.val;
}
int n, h[N], pos[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		H[i] = {t, i};
	}
	sort(H + 1, H + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		int idx = H[i].idx;
		h[idx] = i;
		pos[i] = idx;
	}
	int ans = 0, bj = 1;
	for (int i = 1; i <= n; i++) {
		bj = max(bj, pos[i]);
		if (i == bj) {
			ans++;
			bj = i + 1;
		}
	}
	cout << ans;
	return 0;
}
