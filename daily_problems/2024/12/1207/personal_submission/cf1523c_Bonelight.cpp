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
    VC ans;
    while(n --){
        int x; cin >> x;
        if(x == 1) ans.push_back(1);
        else {
            while(ans.size() && ans.back() != x-1) ans.pop_back();
            if(ans.size()) ans.pop_back();
            ans.push_back(x);
        }
        For(i,0,(int)ans.size()-1) cout << ans[i] << ". "[i == ans.size() - 1];
        cout << endl;
    }
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1; cin >> T;
    
    while(T --){
        solve();
    } 
}
