#include <bits/stdc++.h>
using namespace std;

int tab[5] = {0, 0, 1, 2, 9};

long long C(int n, int m) {
    long long res = 1;
    for(int i=n; i>n-m; i--) res *= i;
    for(int i=2; i<=m; i++) res /= i;
    return res;
}

void solve() {
    int n,k;
    cin >> n >> k;
    long long res = 1;
    for(int i=2; i<=k; i++) {
        res += C(n, i) * tab[i];
    }
    cout << res << endl;
}
