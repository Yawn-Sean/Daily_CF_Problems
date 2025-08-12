#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod = 998244353, inf = 2e18;
const double esp=1e-3;
double PI=3.1415926;

vector<ll>dig,limt,chose,fact(20);
ll ans,m;

il void dfs(int idx){
    if(idx==m){
        int L=0;
        for(auto x:chose)L+=x;
        ll denom=1;
        for(auto x:chose)denom*=fact[x];
        ll sum=fact[L]/denom;
        int idx0=-1;
        for(int i=0;i<m;i++){
            if(dig[i]==0){
                idx0=i;
                break;
            }
        }

        ll bad=0;
        if(idx0!=-1&&chose[idx0]>=1){
            denom=1;
            for(int i=0;i<m;i++){
                if(i==idx0)denom*=fact[chose[i]-1];//0的次数减少1
                else denom*=fact[chose[i]];
            }
            bad=fact[L-1]/denom;
        }
        ans+=sum-bad;
        return ;
    }
    for(int i=1;i<=limt[idx];i++){
        chose[idx]=i;
        dfs(idx+1);
    }
}

il void solve(){
    string s;
    cin>>s;
    vector<int>cnt(10);
    for(auto ch:s)cnt[ch-'0']++;
    for(int i=0;i<10;i++){
        if(cnt[i]){
            dig.push_back(i);
            limt.push_back(cnt[i]);
        }
    }
    m=dig.size();
    chose.assign(m,0);
    fact[0]=1;
    for(ll i=1;i<=19;i++){
        fact[i]=fact[i-1]*i;
    }
    dfs(0);
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    //cin >> t;

    while (t--) {

        solve();

    }

    return 0;
}
