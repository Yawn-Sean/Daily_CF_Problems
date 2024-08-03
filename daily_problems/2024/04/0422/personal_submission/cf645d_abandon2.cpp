// Problem: D. Robot Rapping Results Report
// Contest: Codeforces - CROC 2016 - Elimination Round
// URL: https://codeforces.com/problemset/problem/645/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int>e[N*2];
int in[N],u[N],v[N];
int n,m;

int topsort(){
	queue<int>q;
	vector<int>ans;
	for(int i=1;i<=n;i++){
		if(!in[i])
			q.push(i);
	}
	
	
	while(q.size()){
		if(q.size()>1)return 0;
		int t=q.front();
		q.pop();ans.push_back(t);
		for(int v:e[t]){
			if(--in[v]==0)
				q.push(v);
		}
	}
	return (int)ans.size()==n;
}

int check(int k){
	for(int i=1;i<=n;i++){
		e[i].clear();
		in[i]=0;
	}
	for(int i=1;i<=k;i++){
		e[u[i]].push_back(v[i]);
		in[v[i]]++;
	}
	
	if(topsort())return 1;
	return 0;
}


void solve(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i];
	}
	int l=0,r=m+1;
	while(l+1<r){
		int mid=l+r>>1;
		if(check(mid))r=mid;
		else l=mid;
		//cout<<l<<" "<<r<<"\n";
	}
	if(l+1>m){
		cout<<"-1\n";return;
	}
	cout<<l+1<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt=1;
	while(tt--)solve();
}


