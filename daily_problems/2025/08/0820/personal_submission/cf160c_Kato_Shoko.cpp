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
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());

    vector<ll>val,cnt;
    for(int i=0;i<n;){
        int j=i;
        while(j<n&&a[j]==a[i])j++;
        val.push_back(a[i]);
        cnt.push_back(j-i);
        i=j;
    }
    int m=val.size();
    ll per=0,p=-1;
    for(int i=0;i<val.size();i++){
        ll block=cnt[i]*n;
        if(per+block>=k){
            p=i;
            break;
        }
        per+=block;
    }

    k-=per;
    per=0;
    int q=-1;
    for(int i=0;i<val.size();i++){
        ll block=cnt[p]*cnt[i];
        if(per+block>=k){
            q=i;break;
        }
        per+=block;
    }

    cout<<val[p]<<" "<<val[q];
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
