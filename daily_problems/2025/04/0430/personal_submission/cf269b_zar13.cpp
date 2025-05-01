#include<bits/stdc++.h>
using namespace std;
const int N = 5005;
int n, m, s[N], f[N];
double x;//
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i]>>x, f[i]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(s[j]<=s[i]){
				f[i]=max(f[i], f[j]+1);
			}
		}
	}
	int res=0;
	for(int i=1;i<=n;i++) res=max(res, f[i]);
	cout<<n-res;
	return 0;
}
