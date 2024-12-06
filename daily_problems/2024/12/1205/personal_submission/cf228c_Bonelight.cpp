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
	int n,m; cin >> n >> m;
	vector<string> g(n); for(auto &i:g) cin >> i;
	MAT dp(n,VC(m));	
	// MAT ndp(n,VC(m,-1));	
	VCii df = {{0,0},{1,0},{0,1},{1,1}};
	For(i,0,n-2) For(j,0,m-2){
		for(auto [x,y]: df){
			dp[i][j] *= 2;
			dp[i][j] += (g[i + x][j + y] == '*');
		}		
	}
	
	// For(i,0,n-1) For(j,0,m-1) {
	// 	cout << dp[i][j] << " \n"[j == m-1];
	// }

	int ans = 0;
	For(k,1,7){
		int uni = 1 << k; 
		For(i,0,n-uni*2) For(j,0,m-uni*2){
			int msk = 0;
			for(auto [nx,ny]:df){
				nx = i + nx*uni, ny = j + ny*uni;
				msk *= 2;
				msk += (dp[nx][ny] == 15);
			}
			
			bool ok = true;
			for(auto [nx,ny]:df){
				nx = i + nx*uni, ny =j + ny*uni;
				if(dp[nx][ny] != 15 && dp[nx][ny] != msk) ok = false; 
			}

			if(ok) dp[i][j] = msk, ans ++;
			else dp[i][j] = -1;
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
