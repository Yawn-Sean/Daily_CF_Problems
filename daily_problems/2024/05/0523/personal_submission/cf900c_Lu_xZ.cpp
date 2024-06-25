#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 1e5 + 5;

int n, p[N], M[N], idx, mx;
int ans = 1e9, cur;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++ i) {
		cin >> p[i];
		if(p[i] > mx) {
			M[++ idx] = i;
		}
		else ans = min(ans, p[i]);
		mx = max(mx, p[i]);
	}
	M[++ idx] = n + 1;
	for(int i = 1; i < idx; ++ i) {
		int tmp = -1;
		mx = p[M[i - 1]];
		for(int j = M[i] + 1; j < M[i + 1]; ++ j) {
			if(p[j] > mx) {
				mx = p[j];
				++ tmp;
			}
		}
		if(tmp > cur) {
			cur = tmp;
			ans = p[M[i]];
		}
		else if(tmp == cur && p[M[i]] < ans) {
			ans = p[M[i]];
		}
	}
	cout << (ans == 1e9 ? p[1] : ans);
	return 0;
}
