#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin>>n>>m;
	int u, v;
	vector<int> cnt(n+1, 0);
	while(m--){
		cin>>u>>v;
		cnt[u]++;
		cnt[v]++;
	}
	LL res=0;
	for(int i=1;i<=n;i++) res+=1LL*cnt[i]*(cnt[i]-1)+1LL*(n-1-cnt[i])*(n-1-cnt[i]-1)-1LL*cnt[i]*(n-1-cnt[i]);
	cout<<res/6;
	return 0;
}
