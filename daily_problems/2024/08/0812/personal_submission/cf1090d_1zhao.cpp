#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> r(m);
    for(int i=0; i<m; i++) {
        cin >> r[i].first >> r[i].second;
        if(r[i].first > r[i].second) {
            swap(r[i].first, r[i].second);
        }
    }
    if(m >= (long long)n * (n-1) / 2) {
        cout << "NO" << endl;
        return;
    }
    sort(r.begin(), r.end());
    int a = 1, b = 2;
    for(auto &[fi, se]: r) {
        if(fi == a && se == b) {
            b ++;
            if(b > n) {
                a ++;
                b = a + 1;
            }
        } else {
            break;
        }
    }
    
    cout << "YES" << endl;
    vector<int> res(n+1);
    for(int i=1, d=2; i<=n; i++) {
        if(i == a) {
            cout << "1 ";
            d --;
        } else if(i == b) {
            cout << "2 ";
            d --;
        } else {
            cout << i + d << ' ';
        }
    }
    cout << endl;
    for(int i=1, d=2; i<=n; i++) {
        if(i == a) {
            cout << "1 ";
            d --;
        } else if(i == b) {
            cout << "1 ";
            d --;
        } else {
            cout << i + d << ' ';
        }
    }
    cout << endl;
}
