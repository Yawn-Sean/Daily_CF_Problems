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
    int n;
    cin>>n;

    vector<pair<ll,ll>>pa;
    if(n&1){
        pa.push_back({0,0});
        int x=0,y=0;
        for(int i=0;i<n/2-1;i++){
            y+=25;
            pa.push_back({x,y});
            x+=25;
            pa.push_back({x,y});
        }
        x=max(x,25);
        pa.push_back({x,0});
        pa.push_back({x/25*9,-x/25*12});
    }else{
        pa.push_back({0,0});
        int x=0,y=0;
        for(int i=0;i<n/2-1;i++){
            y+=25;
            pa.push_back({x,y});
            x+=25;
            pa.push_back({x,y});
        }
        pa.push_back({x,0});
    }
    for(auto [x,y]:pa){
        cout<<x*5+y*12<<" "<<x*-12+y*5<<'\n';
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
