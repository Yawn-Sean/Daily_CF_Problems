#include <bits/stdc++.h>
using namespace std;

#define ll long long


void solve(){
    int n;
    cin >> n;
    map<int,int> mp;
    mp[4] = 1,mp[8] = 2,mp[15] = 3,mp[16]= 4,mp[23] = 5,mp[42] = 6;
    vector<int> cnt(7,0);
    cnt[0] = n;
    int x;
    for(int i = 0; i < n; ++i){
        cin >> x;
        x = mp[x];
        if(cnt[x - 1]){
            cnt[x - 1]--;
            cnt[x]++;
        }
    }
    cout << n - 6 * cnt[6];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }
    cout << flush;
    return 0;
}