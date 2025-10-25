#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 3e5 + 5, mod =998224353, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    int h,w;
    cin>>h>>w;
    vector<string>g(h);
    for(auto &s:g)cin>>s;
    vector<vector<int>>per(h+1,vector<int>(w+1));
    
    ll cnt=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            int v=(g[i][j]=='#');
            cnt+=v;
            per[i+1][j+1]=per[i+1][j]+per[i][j+1]-per[i][j]+v;
        }
    }

    auto get_sum=[&](int r1,int c1,int r2,int c2)->int{
        return per[r2+1][c2+1] - per[r1][c2+1] - per[r2+1][c1] + per[r1][c1];
    };

    int ans=1,lim=min(h,w);

    vector<int>a;
    for(ll s=1;s<=lim;s++){
        ll b=s*s;
        if(cnt%b==0)a.push_back(s);
    }

    sort(a.rbegin(),a.rend());
    for(auto s:a){
        vector<vector<bool>>vis(h,vector<bool>(w));
        bool ok=true;
        for(int i=0;i<h&&ok;i++){
            for(int j=0;j<w&&ok;j++){
                if(g[i][j]=='#' && !vis[i][j]){
                    if(i+s>h||j+s>w){ ok = false;
                        break;
                    }
                    if(get_sum(i,j,i+s-1,j+s-1)!=s*s){
                        ok=false;
                        break;
                    }
                    for(int x=i;x<i+s&&ok;x++){
                        for(int y=j;y<j+s;y++){
                            if(vis[x][y]){
                                ok=false;
                                break;
                            }
                            vis[x][y]=1;
                        }
                    }
                }
            }
        }
        if(!ok)continue;

        bool flag=true;
        for(int i=0;i<h&&flag;i++){
            for(int j=0;j<w;j++){
                if(g[i][j]=='#'&&!vis[i][j]){
                    flag=false;
                    break;
                }
            }        
        }
            

        if(flag){
            cout<<s;
            return ;
        }
    }
    cout<<1;
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
