#include <bits/stdc++.h>
 
using namespace std;
constexpr int N = 100000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m;
    cin >> m;
    vector<array<int, 3>> b(m);
    for (int i = 0, t, x, l, c; i < m; i++) {
        cin >> t;
        if (t == 1) {
            cin >> x;
            b[i][0] = 1;
            b[i][1] = x;
        } else {
            cin >> l >> c;
            b[i][0] = 2;
            b[i][1] = l;
            b[i][2] = c;
        }
    }
    int n;
    cin >> n;
    vector<long long> q(n);
    for (auto& x : q) {
        cin >> x;
        x -= 1;
    }
    vector<int> ans(n);
    vector<int> a;
    a.reserve(N);
    long long curr = 0;
    for (int i = 0, k = 0; k < n && i < m; i++) {
        if (b[i][0] == 1) {
            curr += 1;
            if (a.size() < N) a.push_back(b[i][1]);
            if (q[k] < curr) ans[k++] = b[i][1];
        } else {
            long long pre = curr;
            curr += 1LL * b[i][1] * b[i][2];
            while (k < n && q[k] < curr) {
                ans[k] = a[(q[k] - pre) % b[i][1]];
                k += 1;
            }
            for (int p = 0; p < b[i][2]; p++) {
                if (a.size() + b[i][1] > N) {
                    copy(a.begin(), a.begin() + N - a.size(), back_inserter(a));
                    break;
                }
                copy(a.begin(), a.begin() + b[i][1], back_inserter(a));
            }
        }
    }
    for (auto& x : ans) {
        cout << x << " ";
    }
    return 0;
}

