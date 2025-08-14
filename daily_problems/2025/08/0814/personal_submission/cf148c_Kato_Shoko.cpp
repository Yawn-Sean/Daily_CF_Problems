#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e5 + 5, mod = 998244353, inf = 2e18;
const double esp=1e-3;
double PI=3.1415926;

il void solve(){
    ll n,a,b;
    cin>>n>>a>>b;
    
    vector<ll>ans(n+1);
    ans[1]=1;
    int i=2;

    if(a==0&&b==0){
        for(int i=1;i<=n;i++){
            cout<<1<<" ";
        }
        return ;
    }else if(a==0){
        while(b--){
            ans[i]=ans[i-1]*2;
            if(ans[i]>50000){
                cout<<-1;
                return ;
            }
            i++;
        }
        b=0;
    }else if(b==0){
        if(a==n-1){
            cout<<-1;
            return ;
        }
        ans[1]=1;
        ans[2]=1;
        i=3;
        while(a--){
            ans[i]=ans[i-1]+1;
            i++;
        }
        a=0;
    }

    while(b--){
        ans[i]=ans[i-1]*2;
        if(ans[i]>50000){
            cout<<-1;
            return ;
        }
        i++;
    }
    while(a--){
        ans[i]=ans[i-1]+1;
        i++;
    }
    for(i;i<=n;i++)ans[i]=1;
    for(int i=1;i<=n;i++){
        if(ans[i]>50000||ans[i]<1){
            cout<<-1;
            return ;
        }
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
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
