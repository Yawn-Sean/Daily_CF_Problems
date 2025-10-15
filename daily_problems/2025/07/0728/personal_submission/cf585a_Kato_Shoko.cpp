#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 3e5 + 5, mod = 998244353, inf = 1e18;
const double esp=1e-3;
double PI=3.1415926;

il void solve(){
    ll n;
    cin>>n;
    struct Node{
        ll v,d,p;
    };
    vector<Node>a(n+1);
    for(int i=1;i<=n;i++){
        auto &[v,d,p]=a[i];
        cin>>v>>d>>p;
    }
    vector<ll>ans;
    vector<bool>vis(n+1,true);

    for(int i=1;i<=n;i++){
        if(!vis[i])continue;
        ans.push_back(i);
        auto [v,d,p]=a[i];
        for(int j=i+1;j<=n&&v>0;j++){
            if(!vis[j])continue;
            a[j].p-=v--;
        }
        queue<int>q;
        for(int j=i+1;j<=n;j++){
            if(vis[j]&&a[j].p<0){
                q.push(j);
            }
        }
        while(!q.empty()){
            int j=q.front();q.pop();
            if(!vis[j])continue;
            vis[j]=false;
            auto [v,d,p]=a[j];
            for(int k=j+1;k<=n;k++){
                if(!vis[k])continue;
                a[k].p-=d;
                if(a[k].p<0){
                    q.push(k);
                }
            }
        }
    }

    cout<<ans.size()<<'\n';
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
