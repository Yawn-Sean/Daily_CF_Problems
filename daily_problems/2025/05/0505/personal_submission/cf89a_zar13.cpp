#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e4 + 5;
LL n, m, k, a[N];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	LL res=1e5;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i%2) res=min(res, a[i]);
	}
	int c=(n+1)/2;
	if(n%2==0|| m<c) cout<<0;
	else{
		LL cnt=m/c*k;
		cout<<min(cnt, res);
	}
	return 0;
}
