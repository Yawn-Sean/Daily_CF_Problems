//链接：https://codeforces.com/problemset/problem/424/C

#include<bits/stdc++.h>
using namespace std;

int n;
typedef long long ll;
const int MAX=1e6+10;
ll arr[MAX];
ll pre[MAX];


void build(){       //预处理 1^2^3^...^n; 
	pre[0]=0;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]^i;
	}
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	build();
	
	ll ans=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		ans^=arr[i];
	}
	
	
	for(int i=1;i<=n;i++){
		int x=n%(2*i);
		ll tmp;
		if(x>=i) tmp=pre[x-i]^pre[i-1];
		else tmp=pre[x];
		
		ans^=tmp;
	}
	
	cout<<ans<<endl;
	
	return 0;
} 
