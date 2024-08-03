#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,md=998244353;
typedef long long LL;
int a[N];

LL ksm(LL a,LL b){
	LL res=1;
	while(b){
		if(b&1)res=res*a%md;
		a=a*a%md;
		b>>=1;
	}
	return res;
}

void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	map<int,int>mx,mn;
	for(int i=1;i<=n;i++){
		mx[a[i]]=max(mx[a[i]],i);
		mn[a[i]]=N;
	}
	for(int i=1;i<=n;i++)
		mn[a[i]]=min(mn[a[i]],i);
	
	int u=1,lst=1,cnt=0;//位置
	while(u<=n){
		for(;u<=lst&&u<=n;u++){
			lst=max(lst,mx[a[u]]);
		}
		cnt++;
		//cout<<u<<" "<<lst<<"\n";
		lst++;
		if(u>n)break;
	}
	cout<<ksm(2,cnt-1)%md<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
