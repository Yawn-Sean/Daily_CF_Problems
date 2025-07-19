#include <bits/stdc++.h>
using ll = long long;
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    int x = 3 * n, y = 3 * m;
    ranges::sort(a);
    ranges::sort(b);
    int p1 = 0, p2 = 0;
    int cur = 0, ans = 3 * (n - m);
    while (p1 < n && p2 < m) {
        if (a[p1] < b[p2]) {
            cur = a[p1];
            while (p1 < n && a[p1] == cur) {
                p1++;
            }
            int xx = p1 * 2 + (n - p1) * 3;
            int yy = p2 * 2 + (m - p2) * 3;
            if (xx - yy > ans) {
                ans = xx - yy;
                x = xx, y = yy;
            }
        } else if (a[p1] > b[p2]) {
            cur = b[p2];
            while (p2 < m && b[p2] == cur) {
                p2++;
            }
            int xx = p1 * 2 + (n - p1) * 3;
            int yy = p2 * 2 + (m - p2) * 3;
            if (xx - yy > ans) {
                ans = xx - yy;
                x = xx, y = yy;
            }
        } else {
            cur = a[p1];
            while (p1 < n && a[p1] == cur) {
                p1++;
            }
            while (p2 < m && b[p2] == cur) {
                p2++;
            }
            int xx = p1 * 2 + (n - p1) * 3;
            int yy = p2 * 2 + (m - p2) * 3;
            if (xx - yy > ans) {
                ans = xx - yy;
                x = xx, y = yy;
            }
        }
    }
    if (2 * (n - m) > ans) {
        ans = 2 * (n - m);
        x = 2 * n, y = 2 * m;
    }
    cout << x << ":" << y << endl;
}
int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t = 1;
    while (t--) {
       solve();
    }
    return 0;
}
