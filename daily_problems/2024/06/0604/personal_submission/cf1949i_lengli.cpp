// Problem: I. Disks
// Contest: Codeforces - European Championship 2024 - Online Mirror (Unrated, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/problemset/problem/1949/I
// Memory Limit: 256 MB
// Time Limit: 2000 ms

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

void solve(){
	int n;
	cin>>n;
	vector<array<int,3>> Disk(n);
	for(auto &[x,y,r]:Disk) cin>>x>>y>>r;
	vector<vector<int>> eg(n);
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			auto [X1,Y1,R1]=Disk[i];
			auto [X2,Y2,R2]=Disk[j];
			if(1ll*(R1+R2)*(R1+R2)==1ll*(X1-X2)*(X1-X2)+1ll*(Y1-Y2)*(Y1-Y2)){
				eg[i].pb(j);
				eg[j].pb(i);
			}
		}
		
	vector<int> st(n,-1);
	auto check=[&](int root){
		bool flag=1;
		int l=0,r=0;
		function<void(int,int,int)> dfs=[&](int u,int fa,int col){
			st[u]=col;
			if(col) l++;
			else r++;
			for(auto x:eg[u]){
				if(x==fa) continue;
				if(st[x]==-1) dfs(x,u,col^1);
				else if(st[x]!=(col^1)) flag=0;
			}
		};
		dfs(root,0,1); 
		return flag and l!=r;
	};
			
	for(int i=0;i<n;i++){
		if(st[i]==-1){
			if(check(i)) {
				cout<<"YES"<<endl;
				return;
			}
		}
	}
	cout<<"NO"<<endl;
	
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
