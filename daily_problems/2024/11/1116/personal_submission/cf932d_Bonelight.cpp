/*
    Bonelight * v *
    20241101：重 走 西 游
    千 仇 万 恨 无 归 处， 封 灯 何 须 至 尊 骨
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e18
#define pii pair<int,int>
#define tiii tuple<int,int,int>

void solve(){
    int n; cin >> n;
    vector<vector<int>> fa,w,pfa,pw;
    fa = w = pfa = pw = vector<vector<int>>(20, vector<int>(n + 1));

    for(int i = 0; i < 20; i ++){ // 0 , 1 节点初始化
        pw[i][0] = INF;
        pw[i][1] = INF;
    }
    pw[0][1] = 0;

    int la = 0, cur = 1;
    while(n --){
        int op; cin >> op;
        int p,v; cin >> p >> v;
        p ^= la, v ^= la;

        if(op == 1){
            int o = ++cur;
            fa[0][o] = pfa[0][o] = p;
            w[0][o] = pw[0][o] = v;

            for(int i = 1; i < 20; i ++){
                fa[i][o] = fa[i-1][fa[i-1][o]];
                w[i][o] = max(w[i-1][o], w[i-1][fa[i-1][o]]);
            }

            for(int i = 19; i >= 0; i --){
                if(w[i][pfa[0][o]] < v){
                    pfa[0][o] = fa[i][pfa[0][o]];
                }
            }

            for(int i = 1; i < 20; i ++){
                pfa[i][o] = pfa[i - 1][pfa[i - 1][o]];
                pw[i][o] = pw[i - 1][o] + pw[i - 1][pfa[i - 1][o]];
                if(pw[i][o] > INF){
                    for(int j = i; j < 20; j ++){
                        pw[j][o] = INF;
                    }
                    break;
                }
            }
        } else {
            la = 0;
            for(int i = 19; i >= 0; i --){
                if(v >= pw[i][p]){
                    v -= pw[i][p];
                    p = pfa[i][p];
                    la |= 1 << i;
                }
            }
            cout << la << endl;
        }
    }


}

signed main(){
ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    // cerr << "整个程序运行时间: " << double(clock()) << " ms" << endl;
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
