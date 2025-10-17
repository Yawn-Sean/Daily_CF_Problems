#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod =1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    ll n;
    cin>>n;
    ll ans=0;
    int len=0;
    ll temp=n;
    while(temp>0){
        temp/=10;
        len++;
    }
    map<ll,bool>mp;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int len1=0;len1<=len;len1++)
            for(int mask=0;mask<(1<<len1);mask++){
                ll now1=0;
                for(int k=0;k<len1;k++){
                    if((mask>>k)&1){
                        now1=now1*10+i;
                    }else{
                        now1=now1*10+j;
                    }
                }
                mp[now1]=true;
            }
        }
    }

    for(auto [x,y]:mp){
        ll need=n-x;
        //cout<<x<<"\n";
        if(mp.count(need)){
            ans++;
            //cout<<x<<" "<<need<<'\n';
        }
    }
    ll same=0;
    if(n%2==0&&mp.count(n/2))same=1;
    cout<<(ans+same)/2;
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
