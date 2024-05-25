#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 2e5 + 5;


int n, ne[N], a[N][2], v[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n;
	if(n <= 3) {
		for(int i = 1; i <= n; ++ i) cout << i << ' ';
		exit(0);
	}
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i][0] >> a[i][1];
	}
	for(int i = 1; i <= n; ++ i) {
		if(a[a[i][0]][0] == a[i][1] || a[a[i][0]][1] == a[i][1]) {
			ne[i] = a[i][0];
		}
		else ne[i] = a[i][1];
	}
	for(int i = 1; !v[i]; i = ne[i]) cout << i << ' ', v[i] = 1;
	return 0;
}
