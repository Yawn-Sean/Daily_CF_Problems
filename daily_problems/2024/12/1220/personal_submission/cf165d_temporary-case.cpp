#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define forn(i, l, r) for(int i=l;i<r;i++)

void solve(){
    int n,m,k,x;cin>>n>>m>>k;
    map<int,int> cnt1,cnt2;
    vector<int> s;
    forn(i,0,n){
        cin>>x;
        cnt1[x]++;
        s.push_back(x);
    }
    forn(i,0,m){
        cin>>x;
        cnt2[x]++;
        s.push_back(x);
    }
    sort(s.begin(),s.end(),greater<int>());
    ll diff = 0LL;
    int last = -1;
    for(auto y : s){
        if(y == last) continue;
        diff += cnt1[y] - cnt2[y];
        if(diff > 0){
            cout<<"YES\n";
            return;
        }
        last = y;
    }
    cout<<"NO\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return 0;
}
