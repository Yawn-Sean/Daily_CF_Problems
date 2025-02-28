//读完题：这不cv等什么呢？晚点补一发（大概率

#include<bits/stdc++.h>
#define maxn 1000005
#define ll long long
using namespace std;
int Q[1005],t,n,m,x,y,a,b,fa[maxn][20],Dep[maxn],lnk[maxn],nxt[maxn],son[maxn],tot;
ll Ans,s[maxn],si[maxn],S[maxn];
inline int read(){
	int ret=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch<='9'&&ch>='0') ret=ret*10+ch-'0',ch=getchar();
	return ret;
}
inline void add(int x,int y){nxt[++tot]=lnk[x];lnk[x]=tot;son[tot]=y;}
inline void Dfs1(int x){
	si[x]=1;
	for (int i=1;i<20;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for (int i=lnk[x];i;i=nxt[i])
	  if (son[i]!=fa[x][0]) Dep[son[i]]=Dep[x]+1,fa[son[i]][0]=x,Dfs1(son[i]),si[x]+=si[son[i]],S[x]+=S[son[i]]+si[son[i]];
}
inline void Dfs2(int x){
	for (int i=lnk[x];i;i=nxt[i])
	  if (son[i]!=fa[x][0]) s[son[i]]=s[x]-2*si[son[i]]+n,Dfs2(son[i]);
}
inline int LCA(int x,int y){
	if (Dep[x]<Dep[y]) swap(x,y);
	int fx=x,fy=y;
	for (int i=19;i>=0;i--) if (Dep[fa[fx][i]]>=Dep[fy]) fx=fa[fx][i];
	if (fx==fy) return fx;
	for (int i=19;i>=0;i--) if (fa[fx][i]^fa[fy][i]) fx=fa[fx][i],fy=fa[fy][i];
	return fa[fx][0];
}
inline int Get(int x){
	for (int i=19;i>=0;i--) if (Dep[fa[x][i]]>Dep[y]) x=fa[x][i];
	return x;
}
int main(){
	n=read(),m=read();
	for (int i=1;i<n;i++) x=read(),y=read(),add(x,y),add(y,x);
	Dep[1]=1;Dfs1(1);for (int i=2;i<=n;i++) s[1]+=Dep[i]-1;Dfs2(1);
	for (int i=1;i<=m;i++){
		x=read(),y=read();
		if (x==y){printf("0.00000000\n");continue;}
		int top=LCA(x,y);Ans=0;
	    if (top^x&&top^y){
	    	ll len=1+Dep[x]+Dep[y]-2*Dep[top];
	    	Ans+=(ll)len*si[x]*si[y];
	    	Ans+=(ll)S[x]*si[y]+(ll)(S[y]*si[x]);
         	printf("%.8lf\n",(double)Ans/(si[x]*si[y]));
		}
		else{
			if (Dep[x]<Dep[y]) swap(x,y);
			top=Get(x);
			ll len=1+Dep[x]-Dep[y];
			Ans+=(ll)len*si[x]*(n-si[top]);
			Ans+=(ll)(s[y]-S[top]-si[top])*si[x]+(ll)S[x]*(n-si[top]);
         	printf("%.8lf\n",(double)Ans/(si[x]*(n-si[top])));
		}
	}
	return 0;
}
