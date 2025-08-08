#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e6 + 5, mod = 1e9+7, inf = 2e18;
const double esp=1e-3;
double PI=3.1415926;

il void solve(){
    int n;
    cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];

    if(n==1){
        cout<<"YES\n1\n";
        return ;
    }

    sort(a.begin()+1,a.end());
    vector<bool>vis(1e6+5,true);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int diff=a[j]-a[i];
            if(diff>1e6)continue;
            vis[diff]=false;
        }
    }
    
    vector<int>diff;
    for(int i=1;i<=1e6;i++){
        if(!vis[i])diff.push_back(i);
    }
    vector<bool>f(1e6+5,true);
    vector<int>b;

    for(int i=1;i<=1e6&&b.size()<n;i++){
        if(!f[i])continue;
        b.push_back(i);
        for(auto d:diff){
            int x=i+d;
            if(x>1e6)continue;
            f[x]=false;
        }
    }
    if(b.size()!=n){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
        for(auto v:b) cout<<v<<" ";
        cout<<'\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    cin >> t;

    while (t--) {
    
        solve();

    }

    return 0;
}
