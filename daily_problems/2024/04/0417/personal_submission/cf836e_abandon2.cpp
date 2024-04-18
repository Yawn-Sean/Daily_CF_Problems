// Problem: Turn Off The TV
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF863E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int f[N][22];
int l[N],r[N],c[N];
int n,cnt;

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i]>>r[i];
		c[++cnt]=l[i];c[++cnt]=r[i];
		c[++cnt]=r[i]+1;//3 4 6 8不加入一个隔点就会连起来了
	}
	sort(c+1,c+1+cnt);
	cnt=unique(c+1,c+1+cnt)-(c+1);
	for(int i=1;i<=n;i++){
		l[i]=lower_bound(c+1,c+1+cnt,l[i])-c;
		r[i]=lower_bound(c+1,c+1+cnt,r[i])-c;
		//cout<<l[i]<<" "<<r[i]<<"\n";
		f[l[i]][0]++,f[r[i]+1][0]--;
	}
	
	for(int i=1;i<=cnt;i++)
		f[i][0]+=f[i-1][0];
	
	for(int j=1;(1<<j)<=cnt;j++){
		for(int i=1;i+(1<<j)-1<=cnt;i++){
			f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
		}
	}
	for(int i=1;i<=n;i++){
		int x=l[i],d=r[i]-l[i]+1;
		int k=log2(d);
		int t=min(f[x][k],f[r[i]-(1<<k)+1][k]);
		if(t>=2){
			cout<<i<<"\n";return;
		}
	}
	cout<<"-1";
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt=1;
	while(tt--)solve();
}


