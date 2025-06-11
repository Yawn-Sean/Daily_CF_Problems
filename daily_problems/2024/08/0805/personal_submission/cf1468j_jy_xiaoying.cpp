//链接：https://codeforces.com/problemset/problem/1468/J
// 2024-8-8


#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vv;
const int MAX=2e5+10;
ll res[MAX];
int n,m,k; 

int t;

int fa[MAX];

void build(){
	for(int i=0;i<=n;i++) fa[i]=i;
}

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

bool unio(int x,int y){
	x=find(x),y=find(y);
	if(x==y) return 0;
	fa[x]=y;
	return 1;
}

ll f(){
	cin>>n>>m>>k;
	vector<vv> g(m);
	int u,v,c;
	int mi=INT_MAX;
	build();                     //并查集初始化 
	for(int j=0;j<m;j++){
		cin>>u>>v>>c;
		g[j]=vv{u,v,c};
		mi=min(mi,abs(c-k));
	}
	
	sort(g.begin(),g.end(),[&](const vv &a,const vv &b){
		return a[2]<b[2];
	});
	
	ll ans=0;
	int cnt=0;
	for(int j=0;j<m && cnt<n-1;j++){
		int u=g[j][0],v=g[j][1],c=g[j][2];
		if(!unio(u,v)) continue;
		cnt++;
		ans+=max(0,c-k);
	}
	
	return ans>0?ans:mi;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>t;
	for(int i=0;i<t;i++){
		res[i]=f();
	}
	
	for(int i=0;i<t;i++){
		cout<<res[i]<<endl;
	}
	
	return 0;
} 
