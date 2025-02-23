/*
    Bonelight (=v=)
    20241219: 一个利己主义笨蛋
    == UnderLight == 
*/

#include <bits/stdc++.h>
using namespace std;

#define i64 long long
// #define endl '\n'
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define INF 2e9
#define INFF 2e18

#define VC vector<int>
#define MAT vector<vector<int>>
#define VCii vector<pii>
#define MATii vector<vector<pii>>

#define For(_i,_l,_r) for(int _i = _l; _i <= _r; _i ++)
#define Rof(_i,_r,_l) for(int _i = _r; _i >= _l; _i --)
#define all(_a) begin(_a), end(_a)

void solve(){
    int n,m; cin >> n >> m;
    VC a(2*n+1); For(i,1,2*n) cin >> a[i];
    VC vis(2*n+1), pre(2*n+1);
    For(i,1,m) {
        int x,y; cin >> x >> y; 
        pre[x] = y, pre[y] = x;
    }
    int t; cin >> t;

    int last = -1;
    For(i,1,n){
        if(t == 2){
            cin >> last;
            vis[last] = 1;
        }

        if(last!=-1 && pre[last] && !vis[pre[last]]){
            cout << pre[last] << endl;
            vis[pre[last]] = 1;
        } else {
            int chose = 0;
            For(j,1,2*n){
                if(pre[j] && !vis[j]){
                    chose = a[j] > a[pre[j]]? j:pre[j];
                    cout << chose << endl;
                    vis[chose] = 1;
                    break;
                }
            }

            if(!chose){
                int v = -1, id = -1;
                For(j,1,2*n){
                    if(!vis[j] && a[j] > v){
                        id = j;
                        v = a[j];
                    }
                }
                cout << id << endl;
                vis[id] = 1;
            }
        }

        if(t == 1){
            cin >> last;
            vis[last] = 1;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt","rt",stdin);
    freopen("out.txt","wt",stdout);
#endif
    int T = 1; //cin >> T;
    while(T --) solve();
    return 0;
}
