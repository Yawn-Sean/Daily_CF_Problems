//链接：https://codeforces.com/problemset/problem/407/B

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;
const int MAX=1e3+10;
ll f[MAX];
int p[MAX];
int n;
 
int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>p[i];
	}
	
	f[1]=0;
	for(int i=1;i<=n;i++){
		ll tmp=(f[i]+1+(f[i]-f[p[i]])+1+mod)%mod;     //+mod 防止非负 
		f[i+1]=tmp;
	}
	
	cout<<f[n+1]<<endl;
	
	return 0;
}
