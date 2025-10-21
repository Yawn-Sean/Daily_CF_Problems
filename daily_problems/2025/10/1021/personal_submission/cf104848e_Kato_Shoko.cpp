#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e5 + 5, mod =1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    map<ll,ll>mp;
    mp[12]=48;
	mp[15]=5055;
	mp[18]=288;
	mp[21]=7077;
	mp[24]=8088;
	mp[27]=3699;
	mp[36]=48888;
	mp[45]=5055555555;
	mp[54]=222888888;
	mp[63]=111888;
	mp[72]=8088888888;
	mp[81]=9099999999;

    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        auto it=mp.find(n);
        if(it!=mp.end()){
            cout<<it->second<<'\n';
        }else{
            set<ll>st;
            ll x=n;
            while(x){
                st.insert(x%10);
                x/=10;
            }
            cout<<(st.size()==1?n:-1)<<'\n';
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
