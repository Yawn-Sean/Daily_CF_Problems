#include <bits/stdc++.h>
using namespace std;

#define ll long long


void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> cnt(m + 1,0);
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        if(s[m - 1] == '1') cnt[m - 1]++;
        for(int j = 0; j < m - 1; ++j){
            if(s[j] != s[j + 1]){
                cnt[j]++;
            }
        }
    }
    int ans = 0;
    for(auto x : cnt){
        ans += min(x,n - x);
    }
    cout << ans << '\n';
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }
    cout << flush;
    return 0;
}