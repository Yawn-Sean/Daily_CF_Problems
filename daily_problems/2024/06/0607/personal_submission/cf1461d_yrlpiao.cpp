#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <array>
using namespace std;
#define int long long
#define ar2 array<int, 2>
#define ar3 array<int, 3>


int arr[1 << 17] {}, sum[1 << 17] {};

void dfs(int l, int r, auto& us) {
	us.insert(sum[r] - sum[l - 1]);
	if (arr[l] == arr[r]) return;
	int mid = arr[l] + arr[r] >> 1;
	int h = l, t = r;
	while (h < t) {
		int m = (h + t + 1) >> 1;
		if (arr[m] > mid) t = m - 1;
		else h = m;
	}
	
	dfs(l, h, us);
	dfs(h + 1, r, us);
	return;
}
void yrlpSolve() {
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + arr[i];
	}
	unordered_set<int> us;
	dfs(1, n, us);
	for (int i = 0; i < q; i++) {
		int x; cin >> x;
		if (us.count(x)) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
    return; 
}

signed main() {
    int T = 1; cin >> T;
    while (T--) yrlpSolve();
}
