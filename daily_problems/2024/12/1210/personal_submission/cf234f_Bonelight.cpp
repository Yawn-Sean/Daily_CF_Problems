/*
    Bonelight =^x^=
    20241203: 挑灯战夜，不畏魑魅魍魉
    我尝试过无数次了，但我知道，机会只会出现在其中的一两次
 */
#include <bits/stdc++.h>
using namespace std;

// #define int long long 
#define endl '\n'
#define int long long
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

// read file & write file
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout

/*希望残酷的世界还能为我这样的蝼蚁留下一丝美好*/
void solve(){

    int tot = 0;
    int n; cin >> n;
    int a,b; cin >> a >> b;
    VC vec(n+1); For(i,1,n) cin >> vec[i], tot += vec[i];

    // dp[i][tot-color-a][now-color] red-0,green-1
    // Roll [i] -> 2D
    MAT dp(tot + 1, VC(2,INF));
    MAT ndp(tot + 1, VC(2,INF));
    dp[0][1] = 0; 
    dp[0][0] = 0; 

    VCii df = {{0,0},{0,1},{1,0},{1,1}};
    For(i,1,n){
        int add = min(vec[i], vec[i-1]);
        For(j,0,tot) for(auto [x,y]:df){ // [color][color-combine(x,y)]
            if(j + vec[i]*y <= tot)
                ndp[j + vec[i]*y][y] = min(ndp[j + vec[i]*y][y], dp[j][x] + add * (x^y));
        }
        For(j,0,tot) For(k,0,1){
            dp[j][k] = ndp[j][k];
            ndp[j][k] = INF;
        }        
    } 

    int ans = INF;
    For(i,0,tot) For(j,0,1){ // [color, color-last]
        if(i <= a && tot - i <= b){
            ans = min(ans,dp[i][j]);
        }
    }
    cout << (ans < INF? ans:-1) << endl;
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
