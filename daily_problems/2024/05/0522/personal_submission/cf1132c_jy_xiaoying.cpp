//链接：https://codeforces.com/problemset/problem/1132/C

#include<bits/stdc++.h>
using namespace std;

const int MAX=5010;
int diff[MAX];
int cnts[MAX];                //区间[0...i]上 diff上有几个位置为 1  
int vis[MAX];                //区间[0...i]上 有几个位置为 非0（被粉刷过）  

int l[MAX];
int r[MAX];

int n,m;

void build(){
	for(int i=0;i<=n;i++) {
		diff[i]=cnts[i]=vis[i]=0;
	}
}

void preSum(){
	cnts[0]=diff[0]=vis[0]=0;
	for(int i=1;i<=n;i++){
		diff[i]+=diff[i-1];
		cnts[i]+=cnts[i-1];
		vis[i]+=vis[i-1];
		if(diff[i]!=0) vis[i]++;
		if(diff[i]==1) cnts[i]++;
	}
}

void f(){
	int ans=0;
	for(int i=0;i<m;i++){
		build();
		for(int j=0;j<m;j++){
			if(j==i) continue;
			diff[l[j]]++, diff[r[j]+1]--;
		}
		preSum();
		for(int j=0;j<m;j++){
			if(i==j) continue;
			int t=cnts[r[j]];
			 t-=cnts[l[j]-1];
			ans=max(ans,vis[n]-t);
		}
	}
	
	cout<<ans<<"\n";
}

int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>l[i]>>r[i];
	}
	
	f();
	return 0;
} 
