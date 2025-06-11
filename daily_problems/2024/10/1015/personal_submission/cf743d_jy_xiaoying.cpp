//链接：https://codeforces.com/problemset/problem/743/D

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vv;
int n;
const int MAX=2e5+10;
const ll inf=-1e15-10;
ll val[MAX];
ll f[MAX];
ll f1[MAX];
ll f2[MAX];
vector<vv> g;
ll ans;

void build() {
	for(int i=0; i<=n; i++) {
		f[i]=val[i];
		f1[i]=f2[i]=inf;
	}
}

void dfs(int x,int fa) {

	for(auto y:g[x]) {
		if(y==fa) continue;
		dfs(y,x);
		ll tmp=max(f[y],f1[y]);
		if(tmp>=f1[x]) {
			swap(f1[x],f2[x]);
			f1[x]=tmp;
		} 
		else if(tmp>f2[x]) {
			f2[x]=tmp;
		}

	}
	
	if(f2[x]>inf) {
		ans=max(ans,f1[x]+f2[x]);
	}
	
	f[fa]+=f[x];
	return ;
}

void solve() {
	build();
	ans=inf;
	dfs(1,0);

//	for(int i=1;i<=n;i++){
//		cout<<f1[i]<<endl;
//	}
//	return ;

	if(ans==inf) {
		cout<<"Impossible"<<endl;     //Impossible
		return ;
	}
	cout<<ans<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	g=vector<vv>(n+1,vv());
	for(int i=1; i<=n; i++) {
		cin>>val[i];
	}
	for(int i=0; i<n-1; i++) {
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}

	solve();

	return 0;
}

/*

10
3 2 -4 2 0 3 3 3 3 4
10 8
4 2
4 9
3 5
5 2
7 4
2 6
1 8
10 9

answer:6
*/
