#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
using LL=long long;
const int inf = 1e9;

//
const int MXN=1e3+2;
void solve() {
	int n;
	cin>>n;
	vector<int>a(n);
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	int N=1<<n;
	vector<vector<int>>dp(N,vector<int>(MXN+1,inf));
	dp[0][0]=0;
	for(int i=0;i<n;++i){
		dp[1<<i][a[i]]=a[i];
	}
	for(int msk=1;msk<N;++msk){
		for(int x=0;x<=MXN;++x){
			if(dp[msk][x]==inf){
				continue;
			}
			for(int i=0;i<n;++i){
				if(!((msk>>i)&1)){
					int nxt=(msk|(1<<i));
					int nx1=x+a[i],nx2=abs(x-a[i]);
					if(nx1<=MXN){
						dp[nxt][nx1]=min(dp[nxt][nx1],max(nx1,dp[msk][x]));
					}
					if(nx2<=MXN){
						dp[nxt][nx2]=min(dp[nxt][nx2],max(nx2,dp[msk][x]));
					}
				}
			}
		}
	}
	int ans=inf;
	for(int i=0;i<=MXN;++i){
		ans=min(dp[N-1][i],ans);
	}
	cout<<ans<<endl;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int loop = 1;
	//cin >> loop;
	while (loop--){
		solve();
	}
	return 0;
}