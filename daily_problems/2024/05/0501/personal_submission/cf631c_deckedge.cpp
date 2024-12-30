#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
using pi = pair<int, int>; 

inline int red() {
    int x;
    cin >> x;
    return x;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = red(), m = red(), i, j;
    vector<int> a(n), b(m + 1); 
    vector<pi> d(m + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mx = 0;
    for (i = 1; i <= m; i++) {
        cin >> d[i].fi >> d[i].se;

    }
    for (i = m; i >= 1; i--) {
        b[i] = mx;
        mx = max(mx, d[i].se);
    }
    vector<int> c(mx);
    for (i = 0; i < mx; i++) {
        c[i] = a[i];
    }
    int st = 0, ed = mx - 1;
    sort(c.begin(), c.end());
    for (i = 1; i <= m; i++) {
        if(d[i].se <= b[i]) {
            continue;
        }
        if (d[i].fi == 1) {  
            for (j = 0; d[i].se - j > b[i]; j++) {
                a[d[i].se - j - 1] = c[ed];
                ed--;
            }
        } else {
            for (j = 0; d[i].se - j > b[i]; j++) {
                a[d[i].se - j - 1] = c[st];
                st++;
            }
        }
    }
    for (i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n];
    }

    return 0;
}