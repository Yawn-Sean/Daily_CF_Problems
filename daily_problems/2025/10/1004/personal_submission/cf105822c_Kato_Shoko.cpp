#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e3 + 5, mod =1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    int n;
    string s;
    cin>>n>>s;

    ll x=count(s.begin(),s.end(),'E');
    ll needo=x/2,neede=x/2;
    if(x&1){
        cout<<"NO\n";
        return ;
    }

    set<int>sto,ste;
    for(int i=1;i<=2*n;i++){
        if(i&1)sto.insert(i);
        else ste.insert(i);
    }

    vector<pair<int,int>>ans(n);
    for(int i=0;i<n;i++){
        if(s[i]=='E'){//偶数
            //奇+奇，偶+偶

            bool odd=(needo&&sto.size()>=2);
            bool eve=(neede&&ste.size()>=2);

            if(!odd&&!eve){
                cout<<"NO\n";
                return ;
            }

            if(odd&&eve){
                auto it1=sto.begin();
                int o1=*it1;
                it1++;
                int o2=*it1;

                auto it2=ste.begin();
                int e1=*it2;
                it2++;
                int e2=*it2;

                if(o1+o2<=e1+e2){
                    ans[i]={o1,o2};
                    sto.erase(o1);
                    sto.erase(o2);
                    needo--;
                }else{
                    ans[i]={e1,e2};
                    ste.erase(e1);
                    ste.erase(e2);
                    neede--;
                }
            }else if(odd){
                auto &[x,y]=ans[i];
                x=*sto.begin();
                sto.erase(x);
                y=*sto.begin();
                sto.erase(y);
                needo--;
            }else{
                auto &[x,y]=ans[i];
                x=*ste.begin();
                ste.erase(x);
                y=*ste.begin();
                ste.erase(y);
                neede--;
            }

        }else{
            //奇+偶
            if(sto.empty()||ste.empty()){
                cout<<"NO\n";
                return ;
            }
            auto &[x,y]=ans[i];
            x=*sto.begin();
            y=*ste.begin();

            sto.erase(x);
            ste.erase(y);
        }
    }
    cout<<"YES\n";
    for(auto [x,y]:ans){
        cout<<x<<" "<<y<<'\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    cin >> t;

    while (t--) {

        solve();

    }

    return 0;
}
