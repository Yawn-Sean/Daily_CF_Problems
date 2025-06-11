//链接：https://codeforces.com/problemset/problem/725/D

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct peo{
	ll val;
	ll w;
	int id;
};

const int MAX=3e5+10;
peo g[MAX];

int n;

void f(){
	sort(g,g+n,[&](peo &a,peo &b){
		return a.val>b.val || (a.val==b.val && a.id<b.id);
	});
	
	priority_queue<ll,vector<ll>,greater<ll>> q;
	int r=0;
	int ans;
	ll score;
	for(int i=0;i<n;i++){
		if(g[i].id==0){
			score=g[i].val;
			r=i+1;
			ans=i;
			break;
		}
		q.push(g[i].w-g[i].val+1);
	}
	while(score>=0 && !q.empty()){
		ll x=q.top();
		q.pop();
		if(score<x) break;
		score-=x;
		while(r<n && g[r].val>score){
			q.push(g[r].w-g[r].val+1);
			r++;
		}
		ans=min(ans,(int)(q.size()));
	}
	cout<<ans+1<<"\n";
}

int main(){
	cin>>n;
	ll ball,w;
	for(int i=0;i<n;i++){
		cin>>ball>>w;
		g[i]=peo{ball,w,i};
	}
	
	f();
	return 0;
} 
