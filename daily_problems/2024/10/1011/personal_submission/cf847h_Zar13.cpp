#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
int n;
LL a[N], ltop[N], rtop[N], ls[N], rs[N];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		ltop[i]=max(ltop[i-1]+1, a[i]);
		ls[i]=ls[i-1]+ltop[i]-a[i];
	}	
	for(int i=n;i>=1;i--){
		rtop[i]=max(rtop[i+1]+1, a[i]);
		rs[i]=rs[i+1]+rtop[i]-a[i];
	}
	LL ans=1e18, res;
	for(int i=1;i<=n;i++){
		res=ls[i]+rs[i]-(min(ltop[i], rtop[i])-a[i]);
		ans=min(ans, res);
	}
	cout<<ans;
	return 0;
}
