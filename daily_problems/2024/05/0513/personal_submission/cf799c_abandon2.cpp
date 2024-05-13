#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int w,c;
}a[N],b[N];
int C[N];
int n,x,y;

int lowbit(int x){
	return x&(-x);
}

void add(int k,int x){
	for(int i=k;i<=N;i+=lowbit(i)){
		C[i]=max(C[i],x);
	}
}

int maxw(int k){
	int res=0;
	for(int i=k;i>=1;i-=lowbit(i)){
		res=max(res,C[i]);
	}
	return res;
}

void solve(){
	cin>>n>>x>>y;
	int mx1=-1,mx2=-1;
	int ans=0;
	int p=0,q=0;
	for(int i=1;i<=n;i++){
		int w,c;char t;cin>>w>>c>>t;
		if(t=='C'){
			a[++p]={w,c};
			if(c<=x){
				mx1=max(mx1,w);
			}
		}
		else{
			b[++q]={w,c};
			if(c<=y){
				mx2=max(mx2,w);
			}
		}
	}

	//cout<<mx1<<" "<<mx2<<"\n";
	if(mx1!=-1&&mx2!=-1)
		ans=mx1+mx2;//两个都能买

	for(int i=1;i<=p;i++){
		int t=maxw(x-a[i].c);//当前可以买的最大价值物品
		if(t>0)
			ans=max(ans,t+a[i].w);
		add(a[i].c,a[i].w);
	}
	memset(C,0,sizeof C);
	for(int i=1;i<=q;i++){
		int t=maxw(y-b[i].c);//当前可以买的最大价值物品
		if(t>0)
			ans=max(ans,t+b[i].w);
		add(b[i].c,b[i].w);
	}
	cout<<ans<<"\n";
}	

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
