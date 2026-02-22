#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n;
    cin >> n;
    vector<ll> f(n + 1);
    for(int i = 1;i <= n;i++){
        cin >> f[i];
    }
    vector<ll> a(n + 1);
    ll d = (f[1] + f[n]) / (n - 1);
    ll pre = 0;
    for(int i = 1;i <= n - 1;i++){
        a[i] = (f[i + 1] - f[i] + d - pre) / 2;
        pre += 2 * a[i];
    }
    a[n] = d;
    for(int i = 1;i <= n - 1;i++){
        a[n] -= a[i];
    }
    for(int i = 1;i <= n;i++){
        cout << a[i] << " ";
    }   cout << "\n";
}

int main(){
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}