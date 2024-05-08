// Problem: C. Trailing Loves (or L'oeufs?)
// Contest: Codeforces - Codeforces Round 538 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1114/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>PII;
void solve(){
	int n,b;cin>>n>>b;	
	vector<PII>res;
	for(int i=2;i*i<=b;i++){//b分解质因数
		if(b%i==0){
			int cnt=0;
			while(b%i==0){
				b/=i;cnt++;
			}
			res.push_back({i,cnt});
		}
	}
	if(b>1)
		res.push_back({b,1});
	int ans=1e18;
	for(auto[p,t]:res){//枚举质数依次他的次数
		int u=n;//计算这个质数为n的贡献
		int c=0;
		while(u){
			c+=u/p;//拆除p的几次方
			u/=p;
		}
		ans=min(ans,c/t);
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt=1;
	while(tt--)solve();
}


