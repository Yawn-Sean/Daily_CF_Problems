// https://codeforces.com/contest/599/problem/C

#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 100010;
int n,h[N],st[N][21],st2[N][21];

void init() {
	int p = log2(n);
	
	for (int i = 1;i <= n;i++) {
		st[i][0] = h[i];
		st2[i][0] = h[i];
	}
	
	for (int j = 1; j <= p; j++) {
		for (int i = 1;i + (1 << (j - 1)) <= n; i++) {
			st[i][j] = max(st[i][j - 1],st[i + (1 << (j - 1))][j - 1]);
			st2[i][j] = min(st2[i][j - 1],st2[i + (1 << (j - 1))][j - 1]);
		}
	}
	
}

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin >> n;
	for (int i = 1;i <= n; i++) {
		cin >> h[i];
	}	
	
	init();
	
	int ans = 0;
	for (int r = 1,l = 1;r < n; r++) {
		int p = log2(r - l + 1),p2;
		int mx = max(st[l][p],st[r - (1 << p) + 1][p]);
		
		
		p2 = log2(n - r);
		int minv = min(st2[r + 1][p2],st2[n - (1 << p2) + 1][p2]);
		
		if (mx <= minv) {
			++ans;
			l = r + 1;
		}
		
	}
	++ans;
	
	cout << ans << "\n";
	
	return 0;
}
