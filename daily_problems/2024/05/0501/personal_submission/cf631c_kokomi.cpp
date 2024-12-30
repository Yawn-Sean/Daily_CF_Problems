#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int a[N],idx[N],typ[N],ans[N];
int n,m;

//注意到后面来的更大范围的排序一定会覆盖小范围的
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int mx=0;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		idx[y]=i;
		typ[y]=x;
		mx=max(mx,y);
	}
	sort(a+1,a+1+mx);
	int flag,now=0,hh=1,tt=mx;
	for(int i=mx;i;i--){
		if(now<idx[i]){
			now=idx[i];
			flag=typ[i];
		}
		if(flag==1){
			ans[i]=a[tt--];
		}
		else ans[i]=a[hh++];
	}
	for(int i=1;i<=mx;i++){
		cout<<ans[i]<<" ";
		
	}
	for(int i=mx+1;i<=n;i++){
		cout<<a[i]<<" ";
	}
}

int main(){
	int t;
	t=1;
	while(t--){
		solve();
	}
}