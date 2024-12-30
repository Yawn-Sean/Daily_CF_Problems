#include<bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int N = 3e5 + 5;

int n, m, a[N];


bool check(int k) {
	int lst = 0;
	for(int i = 1; i <= n; ++ i) {
		if(a[i] + k < m) {
			if(a[i] + k < lst) return 0;
			lst = max(a[i], lst);
		}
		else {
			if(a[i] + k - m >= lst) {
				continue;
			}
			lst = max(a[i], lst);
		}
	}
	return 1;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; ++ i) {
		cin >> a[i];
	}
	
	
	int l = 0, r = m;
	while(l < r) {
		int mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	
	cout << l;	
	return 0;
}
