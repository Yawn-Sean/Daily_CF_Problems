/*
Mayoeba Yabureru
*/
#pragma GCC optimize("O3,unroll-loops")

#include<bits/stdc++.h>
using namespace std;

void solve() {
    long long n, k, sum = 0;
    cin >> n >> k;

    long long nn = n;
    deque a(n, 0);
    multiset<int> s;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        s.insert(a[i]);
        sum += a[i];
    }
    if (sum < k) {
        cout << -1 << endl;
        return;
    }

    long long kk = 0;
    while (s.size()) {
        int x = *s.begin() - kk;
        s.erase(s.begin());

        if (nn * x <= k) {
            kk += x;
            k -= nn * x;
            nn --;
        }
        else break;
    }

    if (nn == 0) return;

    long long num = k / nn;
    k %= nn;
    deque b(0, vector(0, 0));
    for (int i = 0; i < n; i ++) {
        a[i] -= kk;
        if (a[i] <= 0) continue;
        a[i] -= num;
        b.push_back({a[i], i});
    }
    while (k --) {
        b.push_back({b[0][0] - 1, b[0][1]});
        b.pop_front();
    }
    for (auto v : b) {
        if (v[0] == 0) continue;
        cout << v[1] + 1 << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;

    for (int I = 1; I <= T; I ++){
        solve();
    }
}
