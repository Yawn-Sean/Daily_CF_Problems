// https://codeforces.com/problemset/problem/1016/C
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
typedef long long ll;

const int N = 300010;

ll n,a[N][2],suf[N][2],f[N][2],front[N][2],back[N][2];

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> n;
	for (int i = 1;i <= n; i++) {
		cin >> a[i][0];
	}
	
	for (int i = 1;i <= n; i++) {
		cin >> a[i][1];
	}
	
	for (int i = n; i >= 1; i--) {
		suf[i][0] = suf[i + 1][0] + a[i][0];
		suf[i][1] = suf[i + 1][1] + a[i][1];
	}
	
	for (int i = n; i >= 1; i--) {
		ll t = 2 * (i - 1);
		
		front[i][0] = t * a[i][0] + front[i + 1][0] - suf[i + 1][0];
		front[i][1] = t * a[i][1] + front[i + 1][1] - suf[i + 1][1];
		
		back[i][0] = back[i + 1][0] - suf[i + 1][0] + (2 * n - 1) * a[i][0];
		back[i][1] = back[i + 1][1] - suf[i + 1][1] + (2 * n - 1) * a[i][1];
	}
	
	for (int i = n; i >= 1; i--) {
		ll t = 2 * (i - 1);
		f[i][0] = max(f[i + 1][1] + t * a[i][0] + (t + 1) * a[i][1], front[i][0] + back[i][1]);
		f[i][1] = max(f[i + 1][0] + t * a[i][1] + (t + 1) * a[i][0], front[i][1] + back[i][0]);
	}
	
	cout << f[1][0] << "\n";
	return 0;
}
