#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> w(n+1,0);
    vector<ll> f(n+1,0);
    int s,v;
    for(int i = 1;i <= n;i++){
        cin >> s >> v;
        w[s] = max(w[s],v);
    }
    int t = 0;
    for(int i = 1;i <= n;i++){
        if(w[i] > t){
            for(int j = i;j <= n;j++){
                f[j] = max(f[j],f[j-i]+w[i]);
            }
            t = w[i];
        }
    }
    for(int i = 1;i <= n;i++) cout << f[i] << ' ';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T --){
        solve();
    }
    return 0;
}
