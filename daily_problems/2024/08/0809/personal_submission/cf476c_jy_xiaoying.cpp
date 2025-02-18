//链接：https://codeforces.com/problemset/problem/476/C
// 2024-8-11

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a,b; 

const ll mod=1e9+7;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>a>>b;
	ll t1=b*(b-1)/2%mod;
	ll t2=(a+(a*(a+1)/2%mod*b%mod))%mod;
	
	cout<<t1*t2%mod<<endl;

	return 0;
} 
