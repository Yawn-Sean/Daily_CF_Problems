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
    ll n;
    cin>>n;
    vector<ll>a(n+5);
    for(int i=1;i<=n+1;i++)cin>>a[i];
    bool flag=true;
    for(int i=2;i<=n+1;i++){
        if(a[i-1]>1&&a[i]>1){
            flag=false;
            break;
        }
    }
    if(flag){
        cout<<"perfect";
        return ;
    }
    
    cout<<"ambiguous\n";

    int now=1,cnt=1;
    auto b=a;
    for(int i=1;i<=n+1;i++){
        while(a[i]--){
            cout<<now-1<<" ";
            cnt++;
        }
        now=cnt;
    }
    cout<<'\n';

    a=b;
    now=1,cnt=1;
    for(int i=1;i<=n+1;i++){

        if(b[i]>1&&b[i-1]>1){
            cout<<cnt-2<<" ";
            a[i]--;
            cnt++;
        }

        while(a[i]--){
            cout<<now-1<<" ";
            cnt++;
        }
        now=cnt;
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
