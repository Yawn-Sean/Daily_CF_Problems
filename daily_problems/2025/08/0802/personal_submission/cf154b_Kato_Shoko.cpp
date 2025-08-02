#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod = 1e9+7, inf = 1e18;
const double esp=1e-3;
double PI=3.1415926;

//欧拉函数
int spf[N];//最小质因子
il void euler(ll n){//欧拉筛
    vector<bool>vis(n+5,true);
    vis[0]=vis[1]=false;
    vector<ll>prim;
    for(ll i=2;i<=n;i++){
        if(vis[i]){
            prim.push_back(i);
            spf[i]=i;
        }
        for(auto j:prim){
            if(j*i>n)break;
            spf[i*j]=j;
            vis[j*i]=false;
            if(i%j==0){
                break;
            }
        }
    }
}

il auto get(int x){
    vector<int>facs;
    while(x>1){
        int p=spf[x];
        facs.push_back(p);
        while(x%p==0)x/=p;
    }
    return facs;
}

il void solve(){
    ll n,m;
    cin>>n>>m;
    euler(n+5);

    vector<bool>vis(n+5,false);
    vector<int>a(n+5,0);//当前已开并且可被p整除

    while(m--){
        char op;
        int i;
        cin>>op>>i;
        if(op=='+'){
            if(vis[i]){
                cout<<"Already on\n";
                continue;
            }
            auto facs=get(i);
            int x=0;
            for(auto p:facs){
                if(a[p]){
                    x=a[p];
                    break;
                }
            }
            if(x){
                cout<<"Conflict with "<<x<<"\n";
            }else{
                vis[i]=true;
                for(auto p:facs){
                    a[p]=i;
                }
                cout<<"Success\n";
            }
        }else{
            if(!vis[i]){
                cout<<"Already off\n";
            }else{
                auto facs=get(i);
                for(auto p:facs){
                    if(a[p]==i)a[p]=0;
                }
                vis[i]=false;
                cout<<"Success\n";
            }
        }
    }
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
