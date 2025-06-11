//链接：https://codeforces.com/problemset/problem/731/C

#include<bits/stdc++.h>
using namespace std;

int n,m,k;
typedef vector<int> vv;
typedef unordered_map<int,int> mp;

const int MAX=2e5+10;
int col[MAX];
int fa[MAX];
int cnt[MAX];

void build(){
	for(int i=0;i<=n+5;i++){
		fa[i]=i;
		cnt[i]=1;
	}
}

int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

void unio(int a,int b){
	a=find(a);
	b=find(b);
	if(a==b) return ;
	fa[a]=b;
	cnt[b]+=cnt[a];
}

void f(){
	vector<mp> hash(n+5,mp());
	
	for(int i=1;i<=n;i++){
		int x=find(i);
		int y=col[i];
		hash[x][y]++;
	}
	
	int ans=0;
	for(int i=1;i<=n;i++){
		int x=find(i);
		if(x!=i) continue;
		
		int big=-1;
		for(auto &tp:hash[x]){
			big=max(big,tp.second);
		}
		//cout<<cnt[x]-big<<endl;
		ans+=(cnt[x]-big);
	}
	
	cout<<ans<<endl;
}

int main(){

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
		
	cin>>n>>m>>k;
	build();
	
	for(int i=1;i<=n;i++){
		cin>>col[i];
	}	
	
	int a,b;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		unio(a,b);
	}
	
	f();
	return 0;
} 
