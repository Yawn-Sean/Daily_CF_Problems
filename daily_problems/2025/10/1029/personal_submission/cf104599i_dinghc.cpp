#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for (auto& x : a) {
	    scanf("%d", &x);
	}
	vector<int> parents(n, 0);
	for (int i = 1, x; i < n; i++) {
	    scanf("%d", &x);
	    parents[i] = x - 1;
	}
	int ans = 0;
	for (int u = n - 1; u > 0; u--) {
	    int pa = parents[u];
	    int curr = a[u] + 1;
	    ans = max(ans, a[pa] + curr);
	    if (a[pa] < curr) {
	        a[pa] = curr;
	    }
	}
	printf("%d\n", ans);
    return 0;
}

