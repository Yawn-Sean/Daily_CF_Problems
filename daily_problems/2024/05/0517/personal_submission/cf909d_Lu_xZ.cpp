#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 2e6 + 5;


int n, L[N], R[N], v[N];
char s[N];

bool check(int p) {
	if(p < 1 || p > n || v[p]) return 0;
	if(L[p] != 0 && s[L[p]] != s[p]) {
		return 1;
	}
	if(R[p] != n + 1 && s[R[p]] != s[p]) {
		return 1;
	}
	return 0;
}

void erase(int p) {
	R[L[p]] = R[p];
	L[R[p]] = L[p];
}

int q[N], idx;

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	
	for(int i = 1; i <= n; ++ i) {
		L[i] = i - 1;
		R[i] = i + 1;
	}
	R[0] = 1;
	for(int i = 1; i <= n; ++ i) {
		if(check(i)) {
			q[++ idx] = i;
		}	
	}
	int ans = 0;
	while(idx) {
		++ ans;
		set<int> se;
		for(int i = 1; i <= idx; ++ i) {
			se.insert(L[q[i]]), se.insert(R[q[i]]);
			erase(q[i]);
			v[q[i]] = 1;
		}
		idx = 0;
		for(int x : se) {
			if(check(x)) {
				q[++ idx] = x;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
