#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,inf=1e9;
struct node{
	int l,r;
	node(){
		l=inf,r=0;
	}
}b[N];
int siz[N],vis[N];
set<int>st[N];
void solve(){
	int n,q;cin>>n>>q;
	vector<int>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]].l=min(i,b[a[i]].l);
		b[a[i]].r=max(i,b[a[i]].r);
		//cout<<a[i]<<" "<<b[a[i]].l<<" "<<b[a[i]].r<<"   ccc\n";
		siz[a[i]]++;
	}
	// for(int i=1;i<=n;i++){
	// 	cout<<b[i].l<<" "<<b[i].r<<"\n";
	// }
	
	int tot=1;
	for(int i=1;i<n;i++){
		auto [l,r]=b[a[i]];
		auto &[x,y]=b[a[i+1]];
		//if(l==)
		//cout<<l<<" "<<r<<" "<<x<<" "<<y<<"\n";
		int f=0;
		if(x>r){
			tot++;
			f=1;
		}
		//if(l<x&&y<r)continue;
		//if(x<l&&r<y)continue;
		x=min(x,l),y=max(y,r);
		st[tot].insert(a[i+1]);
		if(f)continue;
		st[tot].insert(a[i]);
	}
	vector<int>c(tot+1);
	int ans=0;
	for(int i=1;i<=tot;i++){
		int s=0,mx=0;
		for(int v:st[i]){
			//cout<<v<<"\n";
			mx=max(mx,siz[v]);
			s+=siz[v];
		}
		//cout<<"\n";
		ans+=s-mx;
	}
	//cout<<tot<<" c\n";
	cout<<ans<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
