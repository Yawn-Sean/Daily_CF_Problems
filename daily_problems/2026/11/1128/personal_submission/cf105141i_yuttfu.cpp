#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> s(n+1,0);
    vector<int> w(n+1,0);
    vector<int> d(n+1,0);
    cin >> s[0] >> w[0];
    map<int,int> mp;
    for(int i = 1;i <= n;i++) cin >> s[i] >> w[i] >> d[i],mp[d[i]] ++;
    vector<int> p;
    vector<int> sumt;
    vector<ll> sum;
    sum.push_back(0);
    sumt.push_back(0);
    for(auto [u,v] : mp){
        p.push_back(u);
        sumt.push_back(sumt.back()+v);
        sum.push_back(sum.back()+1ll*u*v);
    }
    int k0 = upper_bound(p.begin(),p.end(),s[0]) - p.begin();
    int x = sumt[k0];
    ll L = 1,R = w[0]-sum[k0];
    for(int i = 1;i <= n;i++){
        int k = upper_bound(p.begin(),p.end(),s[i]) - p.begin();
        int T = sumt[k];
        ll summ = sum[k];
        if(summ > w[i]) continue;
        if(d[i] > s[i]) T ++,summ += d[i];
        if(T > x){
            L = max(L,w[i]+1-summ);
            R = min(R,(ll)s[i]);
        }else if(T == x){
            L = max(L,min(w[i]+1-summ,(ll)s[i]+1));
        }
    }
    if(R >= L) cout << "Yes\n";
    else cout << "No\n";
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

