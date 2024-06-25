//链接：https://codeforces.com/problemset/problem/1461/D

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX=1e5+10;
int g[MAX];
ll sum[MAX];
int q[MAX*10];
bool ans[MAX*10];

int t;
int n,m;

set<ll> st; 

int bs(int l,int r,ll tar){
	int ans=l;
	while(l<=r){
		int mid=(l+r)>>1;
		if(g[mid]<=tar){
			ans=mid;
			l=mid+1;
		}
		else
		   r=mid-1;
	}
	return ans;
}

void build(int l,int r){
	
	st.insert(sum[r+1]-sum[l]);
	
	if(l>=r){
		return ;
	}
	
	ll mid=(g[r]+g[l])/2;
	if(g[r]<=mid) return ;                //防止死循环  
	int id=bs(l,r,mid);                   // <=mid

	build(l,id);
	build(id+1,r);
}

void f(){
	 st.clear();
	 sort(g,g+n);
	sum[0]=0;
	for(int i=0;i<n;i++) sum[i+1]=sum[i]+g[i];
	build(0,n-1);
}

int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;i++)
		   cin>>g[i];
		f();
		ll x;
		for(int i=0;i<m;i++){
			cin>>x;
			if(st.count(x))   cout<<"Yes"<<"\n";
			else               cout<<"No"<<"\n";      
		}      
	}
	
	return 0;
} 
