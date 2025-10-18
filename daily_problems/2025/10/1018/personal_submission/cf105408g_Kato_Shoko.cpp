#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 5e5 + 5, mod =1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    int n;
    cin>>n;
    vector<ll>a(n);
    ll g=0;
    for(auto &i:a){
        cin>>i;
        g=gcd(i,g);
    }
    for(auto &i:a){
        i/=g;
    }
    ll maxx=*max_element(a.begin(),a.end());
    vector<ll>p(maxx+1);
    iota(p.begin(),p.end(),0);

    for(int i=2;i<=maxx;i++){
        if(p[i]==i){
            for(int j=i;j<=maxx;j+=i){
                p[j]=i;
            }
        }
    }
    vector<bool>vis(maxx+1);
    for(auto &x:a){
        while(x>1){
            int pos=p[x];
            if(vis[pos]){
                cout<<"NO";
                return ;
            }
            vis[pos]=true;
            while(x%pos==0)x/=pos;
        }
    }
    cout<<"YES";
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
