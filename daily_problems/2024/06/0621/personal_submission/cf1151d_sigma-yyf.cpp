#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < 2; ++j) {
    		cin >> a[i][j];
    	}
    	a[i][2] = i;
    }

    sort(a.begin(), a.end(), [&](auto &x, auto &y){
    	return x[0] - x[1] > y[0] - y[1];
    });

    long long c = 0;
    for (int i = 0; i < n; ++i) {
    	int x = a[i][0], y = a[i][1];
    	c += (x - y) * 1ll * i + n * 1ll * y - y;
    }
    cout << c << '\n';

    return 0;
}
