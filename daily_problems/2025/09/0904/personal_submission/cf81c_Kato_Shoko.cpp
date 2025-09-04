#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e6 + 5, mod = 998244353, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<int>t(n);
    for(auto &i:t)cin>>i;
    vector<int>ans(n,2);
    if(a==b){
        for(int i=0;i<a;i++)ans[i]=1;
    }else{
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            v[i]={t[i],i};
        }
        if(a<b){
            sort(v.begin(),v.end(),[&](auto &x,auto &y){
                return x.first!=y.first?x.first>y.first:x.second<y.second;
            });
        }else{
            sort(v.begin(),v.end(),[&](auto &x,auto &y){
                return x.first!=y.first?x.first<y.first:x.second<y.second;
            });
        }

        for(int i=0;i<a;i++){
            ans[v[i].second]=1;
        }
    }
    for(auto v:ans)cout<<v<<" ";
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
