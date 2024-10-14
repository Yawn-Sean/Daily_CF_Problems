//链接：https://codeforces.com/problemset/problem/257/C

#include<bits/stdc++.h>
using namespace std;

typedef long double ld;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;
	int x,y;
	vector<ld> g(n);
	for(int i=0; i<n; i++) {
		cin>>x>>y;
		g[i]=atan2l(y,x);
	}

	sort(g.begin(),g.end());
	ld pi=atan2l(0,-1);
	ld ans=0;   
	for(int i=1; i<n; i++) {
		ans=max(ans,g[i]-g[i-1]);
	}
	ans=min(2*pi-ans,g[n-1]-g[0])/pi*180.0;
	cout<< setprecision(20) <<ans<<endl;

	return 0;
}
