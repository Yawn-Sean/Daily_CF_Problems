#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int siz[N],f[N],cnt;

int find(int x){
	if(x==f[x])return x;
	return f[x]=find(f[x]);
}

void merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y){
		cnt++;
		return;
	}
	f[y]=x;
	siz[x]+=siz[y];
}

void solve(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)siz[i]=1,f[i]=i;

	
	while(m--){
		int a,b;cin>>a>>b; 
		merge(a,b);
		vector<int>v;
		for(int i=1;i<=n;i++){
			if(find(i)==i)
				v.push_back(siz[i]);
		}
		//cout<<v.size()<<"\n";
		sort(v.begin(),v.end(),greater<int>());
		int ans=0;
		for(int i=0;i<=cnt;i++)
			ans+=v[i];
		cout<<ans-1<<"\n";
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
