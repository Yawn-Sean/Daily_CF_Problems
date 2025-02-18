/*
    Bonelight * v *
    20240925
    No Coding , No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    unordered_map<int,int> mp;
    for(auto &i:a) cin >> i, mp[i] ++;
    for(auto &i:b) cin >> i;
    
    // for(auto [x,y]:mp) cout << x << ' ' << y << endl; 
    unordered_set<int> st;
    int ans = 0;
    for(int i = 0; i < n; i ++){
        if(mp[a[i]] > 1){
            for(int j = 0; j < n; j ++){
                if((!st.count(j)) && (a[i] | a[j]) == a[i]){
                    // cout << a[i] << ' ' << a[j] << endl;
                    st.insert(j);
                    ans += b[j];
                }
            }
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
