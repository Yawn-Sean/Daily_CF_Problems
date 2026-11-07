#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> p(n+1,-1);
    vector<int> ans = {1};
    vector<int> h(n+1,0);
    int x;
    for(int i = 2;i <= n;i++){
        cin >> x;
        p[i] = x;
    }
    for(int u = n;u > 1;u--){
        if(h[u] == k-1){
            ans.push_back(u);
        }else{
            h[p[u]] = max(h[p[u]],h[u]+1);
        }
    }
    cout << ans.size() << '\n';
    for(auto t : ans){
        cout << t << ' ';
    }
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
