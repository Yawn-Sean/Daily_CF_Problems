#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/822/C

//   二分 + 排序 + 离散处理 
//      
//日期：  2024-4-6
//格式化： ctrl+shift+ a



const int MAX=2e5+10;
typedef long long ll;
typedef pair<int,int> ppi; 
const ll inf=INT_MAX*(ll)(10);
int n,k;

struct vouch{
	int l,r;
	ll cost;
	 vouch() = default;                    // 默认构造
	 
	vouch(int a,int b,ll val){
		l=a;
		r=b;
		cost=val;
	}
};

vouch p[MAX];
ppi is_ok[MAX];
ll bullet[MAX];

int bs(int l,int r,int x){
	int ans=n;
	while(l<=r){
		int mid=(l+r)/2;
		int cur=p[mid].l;
		if(cur>x){
			ans=mid;
			r=mid-1;
		}
		else{
			l=mid+1;
		}
	}
	return ans;
}

void f(){
	for(int i=0;i<n;i++){
		int r=p[i].r;
		int l=p[i].l;
		if(r-l+1>=k) {            // //去除无用 
			is_ok[i]=ppi(i,n);
			continue;
		}
		
		int id=bs(i+1,n-1,r);
		is_ok[i]=ppi(i,id);
	}
	sort(is_ok,is_ok+n,[&](const ppi &a,const ppi &b){
		return a.second>b.second;
	});
	
	ll res=inf;
	for(int i=0;i<MAX;i++) bullet[i]=inf;
	int id=0;
	while(id<n && is_ok[id].second==n){      //去除无用 
		id++; 
	}
	
	for(int i=n-1;i>=0;i--){
		int len=p[i].r-p[i].l+1;
		ll cost=p[i].cost;
		bullet[len]=min(bullet[len],cost);
		while(id<n && is_ok[id].second==i){
			int j=is_ok[id].first;
			ll cost1=p[j].cost;
			int len1=p[j].r-p[j].l+1;
			ll cost2=bullet[k-len1];
			res=min(res,cost1+cost2);
			id++;
		}
	}
	
	if(res>=inf) res=-1;
	cout<<res<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	
	ll l,r,cost;
	for(int i=0;i<n;i++){
		cin>>l>>r>>cost;
		p[i]=vouch(min(l,r),max(l,r),cost);
	}
	
	sort(p,p+n,[&](const vouch &a,const vouch &b){
		return a.l<b.l;
	});
	
	f();

	return 0;
}
/*


*/

