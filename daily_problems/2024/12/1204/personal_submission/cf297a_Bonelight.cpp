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
    string s,p; cin >> s >> p;
    int c1=0,c2=0;
    for(auto i:s) c1 += (i == '1');
    for(auto i:p) c2 += (i == '1');
    cout << ((c1 >= c2) || ((c1 & 1) && c1 + 1 >= c2)? "YES":"NO");  
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
