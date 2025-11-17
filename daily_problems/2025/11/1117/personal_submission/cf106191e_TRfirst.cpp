#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



void ask(int n, int m) {
    cout << "? ";
    cout << n - (m > 0) << " ";
    for (int i = 1; i <= n; i++) if (i != m) cout << i << " ";
    cout << n - (m > 0) << " ";
    for (int i = 1; i <= n; i++) {
        if (i != m) {
            cout << i;
            if (i == n || m == n && i == n - 1) break;
            cout << " ";
        }
    }
    cout << endl;
}

void solve(){
    int n;
    cin >> n;
    ll num;
    ask(n, 0);
    cin >> num;
    vector<ll> in(n + 5);
    ll sum = 0;
    for (int i = 1; i <= n - 1; i++) {
        ask(n, i);
        cin >> in[i];
        in[i] = num - in[i];
        sum += in[i];
    }
    in[n] = 2 * num - sum;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 1) {
            cout << "!" << " " << i << endl;
            return;
        }
    }
    cout << "!" << " " << -1 << endl;
}

signed main(){
    int _T = 1;
    cin >> _T;
    while (_T--){ 
        solve();
    }
    return 0;
}