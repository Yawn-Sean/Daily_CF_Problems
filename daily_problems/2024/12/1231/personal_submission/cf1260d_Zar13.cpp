#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int m, n, k, t, a[N];
struct node{
	int l, r, d;
	bool operator<(const node& b)const{
		return d>b.d;
	}
} trp[N];
int b[N];
bool check(int x){
	int tmp=a[x];
	memset(b, 0, sizeof b);
	for(int i=1;i<=k&& trp[i].d>tmp;i++){
		b[trp[i].l]+=1;
		b[trp[i].r+1]-=1;
	}
	int res=n+1;
	for(int i=1;i<=n;i++){
		b[i]+=b[i-1];
		if(b[i]>0) res+=2;
	}
	return res<=t;
}
int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>m>>n>>k>>t;
	for(int i=1;i<=m;i++) cin>>a[i];
	sort(a+1, a+1+m, greater<int>());
	for(int i=1;i<=k;i++){
		cin>>trp[i].l>>trp[i].r>>trp[i].d;
	}
	sort(trp+1, trp+1+k);
	int l=0, r=m+1;
	while(l+1<r){
		int mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	cout<<l;
	return 0;
}
