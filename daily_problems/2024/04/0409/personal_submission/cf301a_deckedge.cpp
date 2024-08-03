#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

inline int nxt() {
    int x;
    cin >> x;
    return x;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n = nxt(), i, mn = INT_MAX, sum = 0, res;
    vector<int> a(2 * n - 1);
    generate(all(a), nxt);
    int cnt = 0;
    for (i = 0; i < n * 2 - 1; ++i) {
        if (a[i] < 0) {
            ++cnt;
        }
        sum += abs(a[i]);
        mn = min(mn, abs(a[i]));
    }
    if (n & 1) {
        res = sum;
    } else {
        if (cnt & 1) {
            res = sum - 2 * mn;
        } else {
            res = sum;
        }
    }
    cout << res << '\n';
    return 0;
}