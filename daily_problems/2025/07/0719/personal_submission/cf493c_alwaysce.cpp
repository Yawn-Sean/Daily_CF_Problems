#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    cin >> m;
    vector<int> b(m);
    for (auto &x : b) {
        cin >> x;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    set<int> s(a.begin(), a.end());
    for (auto&x: b) {
        s.insert(x);
    }
    s.insert(0);

    int pt1 = 0, pt2 = 0;
    i64 ans1 = 0, ans2 = 0, maxDiff = LLONG_MIN;
    for (auto& d: s) {
        while (pt1 < n && a[pt1] <= d) {
            pt1++;
        }
        while (pt2 < m && b[pt2] <= d) {
            pt2++;
        }

        i64 score1 = 2ll * pt1 + 3ll * (n - pt1);
        i64 score2 = 2ll * pt2 + 3ll * (m - pt2);

        if (score1 - score2 > maxDiff) {
            maxDiff = score1 - score2;
            ans1 = score1;
            ans2 = score2;
        } else if (score1 - score2 == maxDiff) {
            if (score1 > ans1) {
                ans1 = score1;
                ans2 = score2;
            }
        } 
    }

    cout << ans1 << ":" << ans2 << "\n";
    
    return 0;
}
