#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
int n;
int query(int l, int r, int op){
    cout << "? ";
    cout << ((op == 0) ? n : (n - 1)) << " ";
    for (int i = l; i <= r; ++i){
        if (i == op) continue;
        cout << i << " ";
    }
    cout << ((op == 0) ? n : (n - 1)) << " ";
    for (int i = l; i <= r; ++i){
        if (i == op) continue;
        if (i == r) cout << i;
        else cout << i << " ";
    }
    cout << endl;
    int ret;
    cin >> ret;
    return ret;

}

void solve(){
    cin >> n;
    vector<int> deg(n + 1);
    int sum = query(1, n, 0);
    int tmp = 0;
    for (int i = 1;i < n; ++i) {
        deg[i] = sum - query(1, n, i);
        tmp += deg[i];
    }
    deg[n] = sum * 2 - tmp;
    for (int i = 1; i <= n; ++i){
        if (deg[i] == 1){
            cout << "! ";
            cout << i << endl;
            return;
        }
    }
    cout << "! -1" << endl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}