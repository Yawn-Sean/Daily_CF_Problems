#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1005, mod=1e9+7;
int n, p[N], f[N];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=2;i<=n+1;i++){
    	f[i]=(2*f[i-1]%mod-f[p[i-1]]+2+mod)%mod;
	}
	cout<<f[n+1];
    return 0;
}
