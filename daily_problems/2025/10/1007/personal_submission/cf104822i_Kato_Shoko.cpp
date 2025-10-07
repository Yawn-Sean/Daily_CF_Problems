#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e5 + 5, mod =1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

ll n,q,phi[N];//欧拉函数
vector<ll>prim;
il void euler(ll n,vector<bool>&vis){//欧拉筛
    vis[0]=vis[1]=false;
    phi[1]=1;//初始化
    for(ll i=2;i<=n;i++){
        if(vis[i]){
            prim.push_back(i);
            phi[i]=i-1;
        }
        for(auto j:prim){
            if(j*i>n)break;

            vis[j*i]=false;
            if(i%j==0){
                phi[i*j]=phi[i]*j;
                break;
            }
            phi[i*j]=phi[i]*phi[j];
        }
    }
}

ll best,a;
vector<pair<ll,ll>>fac;

void get_div(ll idx,ll cur,const vector<pair<ll,ll>>&fac,vector<ll>&div){
    if(idx==fac.size()){
        div.push_back(cur);
        return ;
    }
    auto [p,e]=fac[idx];
    for(int i=0;i<=e;i++){
        get_div(idx+1,cur,fac,div);
        cur*=p;
    }
}

il void solve(){
    cin>>a;
    fac.clear();
    ll temp=a;
    for(auto p:prim){
        if(p*p>temp)break;
        if(temp%p==0){
            int cnt=0;
            while(temp%p==0){
                cnt++;
                temp/=p;
            }
            fac.push_back({p,cnt});
        }
    }
    if(temp>1)fac.push_back({temp,1});

    vector<ll>div;
    get_div(0,1,fac,div);
    sort(div.begin(),div.end());

    ll best=a*a;
    for(auto u:div){
        ll need=a/u+1;
        auto it=lower_bound(div.begin(),div.end(),need);
        if(it!=div.end()){
            ll res=u**it;
            if(res>a&&res<best)best=res;
        }
    }
    cout<<best-a<<'\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    cin >> t;

    vector<bool>vis(1e5+5,true);
    euler(1e5,vis);

    while (t--) {

        solve();

    }

    return 0;
}
