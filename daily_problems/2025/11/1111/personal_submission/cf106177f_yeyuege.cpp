#include<bits/stdc++.h>
// #pragma GCC optimize(2)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
#define endl "\n"

void solve(){
    int n;
    cin >> n;
    map<int, map<int, int>>mp;
    ll ans = 0;
    int cnt = 0;
    int mas = 0;
    for (int i = 0; i < n; i++) {
        mp[mas][cnt]++;
        int num;
        cin >> num;
        if (num & 1) cnt--, mas ^= 1;
        else cnt++;
        ans += mp[mas][cnt - 1] + mp[mas ^ 1][cnt + 1];
    }
    // cerr << endl;
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
