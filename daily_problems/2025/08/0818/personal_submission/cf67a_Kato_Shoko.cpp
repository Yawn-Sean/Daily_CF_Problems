#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e6 + 5, mod = 1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    vector<ll>ans(n,1);
    for(int i=0;i<n-1;i++){
        if(s[i]=='R'){
            ans[i+1]=ans[i]+1;
        }else if(s[i]=='='){
            ans[i+1]=ans[i];
        }
    }
    for(int i=n-2;i>=0;i--){
        if(s[i]=='L'){
            ans[i]=max(ans[i],ans[i+1]+1);
        }else if(s[i]=='='){
            ans[i]=max(ans[i],ans[i+1]);
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
