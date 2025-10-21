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
    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    cin >> t;

    const int P=15;
    const int prim[P]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

    vector<ll> a;
    a.push_back(1);
    for (int i=0;i<P;i++){
        int p=prim[i];
        int sz=a.size();
        for(int j=0;j<sz;j++)a.push_back(a[j]*p);
    }
    sort(a.begin(),a.end());
    
    while(t--){
        int n;
        cin >> n;
        vector<bool>vis(60);
        while(n--){
            int x;
            cin>>x;
            vis[x]=true;
        }

        for (auto v:a){
            bool ok=true;
            for(int x=2;x<=50;x++){
                if(vis[x]&&gcd(x,v)==1){
                    ok=false;break;
                }
            }
            
            if(ok){
                cout<<v<<'\n';
                break;
            }
        }
    }

    // while (t--) {

    //     solve();

    // }

    return 0;
}
