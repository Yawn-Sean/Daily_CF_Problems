#include<bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int> g[N];
int ans[N];
int main(){
	int n, m, s, r;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s>>r;
		g[s].push_back(r);
	}
	for(int i=1;i<=m;i++){
		sort(g[i].rbegin(), g[i].rend());
		int sa=0, len=g[i].size();
		for(int j=0;j<len;j++){
			sa+=g[i][j];
			if(sa>0) ans[j]+=sa;
			else break;
		}
	}
	sort(ans, ans+n);
	cout<<ans[n-1];
	return 0;
}
