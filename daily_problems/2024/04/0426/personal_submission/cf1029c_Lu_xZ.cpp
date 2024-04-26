#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 3e5 + 5;

int n, L[N], R[N], a[2][N];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	memset(R, 0x3f, sizeof R);
	
	cin >> n;
	
	for(int i = 1; i <= n; ++ i) {
		cin >> a[0][i] >> a[1][i];
		L[i] = max(L[i - 1], a[0][i]);
		R[i] = min(R[i - 1], a[1][i]);
	}
	
	int cur[] = {0, 0x3f3f3f3f}, ans = 0;
	
	for(int i = n; i >= 1; -- i) {
		ans = max(ans, min(R[i - 1], cur[1]) - max(L[i - 1], cur[0]));
		cur[0] = max(cur[0], a[0][i]);
		cur[1] = min(cur[1], a[1][i]);
	}
	
	cout << ans;
	
	return 0;
}
