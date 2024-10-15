//链接：https://codeforces.com/problemset/problem/578/B
// 2024-8-8



//枚举每个数，将其乘以 x^k 再求其与数组其他元素的或和即可
//太秀了--膜拜 

#include<bits/stdc++.h>
using namespace std;

const int MAX=2e5+10;
typedef long long ll;

ll g[MAX];
ll pre[MAX];             //前缀or数组 
ll suf[MAX];             //后缀or数组 
int n,k,x;

void f(){
	ll xo=0;
	for(int i=0;i<n;i++){
		pre[i]=xo;
		xo|=g[i];
	}	
	xo=0;
	for(int i=n-1;i>=0;i--){
		suf[i]=xo;
		xo|=g[i];
	}
	
	ll tmp=1;
	for(int i=0;i<k;i++){
		tmp*=x;
	}
	
	ll ans=0;
	for(int i=0;i<n;i++){
		ll t=suf[i]|pre[i]|(g[i]*tmp);
		ans=max(ans,t);
	}
	
	cout<<ans<<endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k>>x;
	for(int i=0;i<n;i++){
		cin>>g[i];
	}
	
	f();
	return 0;
} 
