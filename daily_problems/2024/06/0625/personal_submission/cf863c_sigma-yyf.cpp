#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    ll k;
    int a, b;
    cin >> k >> a >> b;
    a--, b--;

    int A[3][3], B[3][3];

    for (int i = 0; i < 3; ++i) {
    	for (int j = 0; j < 3; ++j) {
    		cin >> A[i][j];
    		A[i][j]--;
    	}
    }
    for (int i = 0; i < 3; ++i) {
    	for (int j = 0; j < 3; ++j) {
    		cin >> B[i][j];
    		B[i][j]--;
    	}
    }

    vector<array<ll, 3>> D(3);
    vector<array<int, 3>> f(3), p(3);
    int cnt = 1;
    int x = a, y = b, len = 0;

    while (cnt <= k) {
    	if (f[x][y] == 0) {
    		f[x][y] = cnt;
    	} else {
    		len = cnt - f[x][y];
    		break;
    	}
    	D[x][y]++;
    	f[x][y] = cnt++;
    	int p = x, q = y;
    	x = A[p][q], y = B[p][q];
    }

    if (len > 0) {
    	int x1 = x, y1 = y;
	    for (int i = 0; i < len; ++i) {
	    	p[x1][y1]++;
	    	x = A[x1][y1], y = B[x1][y1];
	    	x1 = x, y1 = y;
	    }

	    ll t = (k + 1 - cnt) / len;

	    for (int i = 0; i < 3; ++i) {
	    	for (int j = 0; j < 3; ++j) {
	    		D[i][j] += t * p[i][j];
	    	}
	    }

	    x1 = x, y1 = y;

	    int r = (k + 1 - cnt) % len;

	    for (int i = 0; i < r; ++i) {
	    	D[x1][y1]++;
	    	x = A[x1][y1], y = B[x1][y1];
	    	x1 = x, y1 = y;
	    }
    }

    long long c1 = 0, c2 = 0;

    for (int x = 0; x < 3; ++x)
    	for (int y = 0; y < 3; ++y) {
    		if (x == y) continue;
    		if (x == 0) {
	    		if (y == 2) c1 += D[x][y];
	    		else c2 += D[x][y];
	    	} else if (x == 1) {
	    		if (y == 2) c2 += D[x][y];
	    		else c1 += D[x][y];
	    	} else {
	    		if (y == 1) c1 += D[x][y];
	    		else c2 += D[x][y];
	    	}
    	}

    cout << c1 << ' ' << c2 << '\n';

    return 0;
}
