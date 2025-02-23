/*
    Bonelight =^x^=
    20241203: 挑灯战夜，不畏魑魅魍魉
    我尝试过无数次了，但我知道，机会只会出现在其中的一两次
 */
#include <bits/stdc++.h>
using namespace std;

#define int long long 
#define endl '\n'
#define pii pair<int,int>
#define tiii tuple<int,int,int>  
#define INF 2e18
#define VC vector<int>
#define VCii vector<pii>
#define MAT vector<VC>
#define MATii vector<VCii>
#define For(_tag,x,y) for(int _tag = x; _tag <= y; _tag ++)
#define Rof(_tag,y,x) for(int _tag = y; _tag >= x; _tag --)
#define all(_tag) begin(_tag),end(_tag)
#define x first
#define y second



/*希望残酷的世界还能为我这样的蝼蚁留下一丝美好*/
void solve(){
    int n; cin >> n;
    vector<string> g(n);
    For(i,0,n-1) cin >> g[i];

    VC r1(n),c1(n);
    int ans = 0;
    For(i,0,n-1) Rof(j,n-1,i+1){
        if((g[i][j]-'0') != r1[i] ^ c1[j]){
            r1[i] ^= 1;
            c1[j] ^= 1;
            ans ++;
        }
    }
    VC r2(n),c2(n);
    Rof(i,n-1,0) For(j,0,i-1){
        if((g[i][j]-'0') != r2[i] ^ c2[j]){
            r2[i] ^= 1;
            c2[j] ^= 1;
            ans ++;
        }
    }

    For(i,0,n-1){
        if((g[i][i]-'0') != (r1[i]^r2[i]^c1[i]^c2[i])){
            ans ++;
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1; //cin >> T;
    
    while(T --){
        solve();
    } 
}
