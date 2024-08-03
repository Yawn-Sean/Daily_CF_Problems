#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using pi = pair<int, int>;
const int N = 1e5 + 7;

inline int red() {
    int x;
    cin >> x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = red(), i, res = 1;
    vector<int> a(N), b(N);
    for (i = 0; i < n; i++) {
        int x = red();
        a[x]++;
        b[a[x]]++;
        if (a[x] * b[a[x]] == i + 1 && i != n - 1) {
            res = i + 2;
        }
        if (a[x] * b[a[x]] == i) {
            res = i + 1;
        }
    }

    cout << res << '\n';

    return 0;
}

/*
https://codeforces.com/contest/1163/problem/B2
*/

