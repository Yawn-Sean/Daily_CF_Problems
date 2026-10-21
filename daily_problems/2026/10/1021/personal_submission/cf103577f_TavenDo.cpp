#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
using LL=long long;

//

void solve() {
	int n,q;
	cin>>n>>q;
	vector<int>x(n,0),y(n,0);
	int ans=0,T=0;
	vector<vector<bool>>adj(n,vector<bool>(n,0));
	auto add=[&](int i,int j)->void{
		if(adj[i][j]==1){
			return;
		}
		adj[i][j]=1;
		x[i]+=1;
		y[j]+=1;
		if(x[i]==n){
			++ans;
		}
		if(y[j]==n){
			++ans;
		}
	};
	auto sub=[&](int i,int j)->void{
		if(adj[i][j]==0){
			return;
		}
		adj[i][j]=0;
		if(x[i]==n){
			--ans;
		}
		if(y[j]==n){
			--ans;
		}
		x[i]-=1;
		y[j]-=1;
	};
	for(int i=0;i<n;++i){
		string a;
		cin>>a;
		for(int j=0;j<n;++j){
			if(a[j]=='1'){
				add(i,j);
			}
		}
	}
	while(q--){
		int op;
		cin>>op;
		if(op==1){
			int l,r,b;
			cin>>l>>r>>b;
			--l,--r;
			if(b==1){
				add(l,(r+T)%n);
			}else{
				sub(l,(r+T)%n);
			}
		}else{
			int b,ny=(n+T-1)%n;
			cin>>b;
			for(int l=n-1;l>0;--l){
				if(adj[l-1][ny]==1){
					add(l,ny);
				}else{
					sub(l,ny);
				}
			}
			if(b==1){
				add(0,ny);
			}else{
				sub(0,ny);
			}
			T+=n-1;
		}
		cout<<ans<<endl;
	}
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