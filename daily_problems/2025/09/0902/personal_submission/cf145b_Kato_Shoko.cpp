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
    ll cnt4,cnt7,cnt47,cnt74;
    cin>>cnt4>>cnt7>>cnt47>>cnt74;
    ll a=4,b=7;
    int n=cnt4+cnt7;
    ll max47=min(cnt4,cnt7);
    ll max74=min(cnt7,cnt4);
    if(abs(cnt47-cnt74)>1||(cnt47>max47)||(cnt74>max74)){
        cout<<-1;
        return ;
    }

    ostringstream oss,ans;
    if(cnt47>=cnt74){
        ll a=cnt4,b=cnt7;
        ll x=cnt47,y=cnt74+1;
        while(x--&&y--){
            oss<<47;
            a--,b--;
        }
        if(y){//差一个74
            if(a>0){
                while(a>1){
                    ans<<4;
                    a--;
                }
                ans<<oss.str();
                while(b>0)ans<<7,b--;
                ans<<4;
            }else{
                b--;
                ans<<7;
                ans<<oss.str();
                while(b>0)ans<<7,b--;
            }
        }else{
            while(a>0)ans<<4,a--;
            ans<<oss.str();
            while(b>0)ans<<7,b--;
        }
    }else{
        ll cnt=cnt74-2;
        cnt4-=cnt74;
        cnt4++;
        oss<<74;
        cnt7--;
        while(cnt4>1)oss<<4,cnt4--;
        while(cnt--){
            oss<<74;
            cnt7--;
        }
        while(cnt7>0)oss<<7,cnt7--;
        oss<<4;
        ans<<oss.str();
    }
    //cout<<ans.str()<<'\n';
    if(ans.str().size()!=n){
        cout<<-1;
    }else{
        cout<<ans.str();
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
