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
	int n,k; cin >> n >> k;
	VC a(n); For(i,0,n-1) cin >> a[i];

	a.erase(unique(all(a)), end(a));
	n = a.size();
	VC cnt(k+1); cnt[a[0]] ++; cnt[a[n-1]] ++;
	For(i,1,n-2) cnt[a[i]] += 1 + (a[i-1] == a[i+1]);
	cout << max_element(all(cnt)) - begin(cnt) << endl;
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
