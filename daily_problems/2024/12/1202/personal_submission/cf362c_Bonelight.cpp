/*
    Bonelight =^x^=
    20241117: 单枪匹马，无畏粉身碎骨
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
    VC a(n+1);
    For(i,1,n) cin >> a[i], a[i] ++;
    
    MAT pre(n+1,VC(n+1)); // 下标 x 数值 y， 区间查询
    For(i,1,n) pre[i][a[i]] = 1;

    For(i,1,n) For(j,1,n) pre[i][j] += pre[i-1][j];
    For(i,1,n) For(j,1,n) pre[i][j] += pre[i][j-1];

    int ans = 0;
    For(i,1,n) For(j,1,i-1) ans += (a[j] > a[i]);
    
    int res = 0, cnt = 0;
    For(i,1,n) For(j,1,i-1) if(a[j] > a[i]){
        //2*查 (j+1,a[i]+1) (i-1,a[j]-1) + 两数的交换
        int t = 2*(pre[i-1][a[j]-1] + pre[j][a[i]-1] - pre[i-1][a[i]] - pre[j][a[j]-1]) + 1;   
        if(t > res) res = t, cnt = 1;
        else if(t == res) cnt ++;
    }
    cout << ans - res << ' ' << cnt << endl;
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
