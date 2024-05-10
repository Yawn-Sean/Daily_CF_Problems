//链接：https://codeforces.com/problemset/problem/1609/D

#include<bits/stdc++.h>
using namespace std;

const int MAX=2e3+10;

int fa[MAX];
int siz[MAX];

int cnt[MAX];

int ans[MAX];
int n,m;

void build(){
	for(int i=0;i<=n;i++){
		fa[i]=i;
		siz[i]=1;
	}
	cnt[1]=n;
}

int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

void unio(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return ;
	fa[x]=y;
	cnt[siz[x]]-=1;
	cnt[siz[y]]-=1;
	cnt[siz[x]+siz[y]]+=1;
	siz[y]+=siz[x];
}

void f(){
	int a,b;
	int most=1;
	int res;
	for(int i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		res=0;
		if(find(a)==find(b)){
			most+=1;
		}
		else{
			unio(a,b);
		}
		int tmp=most;
		for(int j=n;j>=1 && tmp>0 ;j--){
			if(cnt[j]==0) continue;
			res+=min(tmp,cnt[j])*j;
			tmp-=cnt[j];
		}
		ans[i]=res-1;
	}
	
	for(int i=0;i<m;i++){
		printf("%d\n",ans[i]);
	}
}

int main(){
	
	scanf("%d %d",&n,&m);
	build();
	f();
	return 0;
} 
