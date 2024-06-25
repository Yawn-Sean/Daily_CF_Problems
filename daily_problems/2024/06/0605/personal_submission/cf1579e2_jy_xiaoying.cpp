//链接：https://codeforces.com/problemset/problem/1579/E2

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX=2e5+10;
ll tree[MAX];
ll arr[MAX];
ll ans[MAX];

vector<ll> g;
int t;
int n;
int len;

ll lowbit(ll x){
	return x &(-x);
}

int bs(ll tar){                  //==tar的位置 
	int l=0,r=len-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(g[mid]==tar) return mid+1;
		else if(g[mid]>tar) r=mid-1;
		else   l=mid+1;
	}
	return -1;
}

void update(int id){
	while(id<=len){
		tree[id]+=1;
		id+=lowbit(id);
	}
}

ll query(int id){
	if(id==0) return 0;
	ll ans=0;
	while(id){
		ans+=tree[id];
		id-=lowbit(id);
	}
	return ans;
}

ll f(){
	sort(g.begin(),g.end());
	g.erase(unique(g.begin(),g.end()),g.end());  //离散化，去重 
	len=g.size();
	fill(tree,tree+len+5,0);
	
	ll ans=0;
	int id;
	id=bs(arr[0]);
	update(id);
	
	for(ll i=1;i<n;i++){             //x==arr[i]:  a:数组中>x的元素个数   b:数组中<x的元素个数  
	                                  // a>=b:  x 放在双端队列尾，否则放队列头 
		id=bs(arr[i]);
		ll b=query(id-1);
		ll a=i-query(id);
		ans+=min(a,b);
		update(id);
	}
	return ans;
}

int main(){
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		g.clear();
		for(int j=0;j<n;j++){
			cin>>arr[j];
			g.push_back(arr[j]);
		}
		
		ans[i]=f();
	}
	
	for(int i=0;i<t;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
} 

