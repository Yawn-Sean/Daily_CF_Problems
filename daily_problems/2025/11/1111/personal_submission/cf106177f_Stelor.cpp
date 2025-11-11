#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


void solve(){
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1;i <= n; ++i){
        cin >> a[i];
    }
    ll ans = 0;
    int j = 0;
    map<int, int> mp, mp2;
    mp[0]++;
    for (int i = 1;i <= n; ++i){
        if (a[i] & 1)  ++j;
        int now = 2 * j - i;
        if (j & 1){
            ans += mp[now - 1] + mp2[now + 1];
        }else{
            ans += mp[now + 1] + mp2[now - 1];
        }
        if (j & 1)mp2[now]++;
        else mp[now]++;
    }
    cout << ans << endl;


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