// Problem: J. Just Arrange the Icons
// Contest: Codeforces - 2019-2020 ICPC, NERC, Northern Eurasia Finals (Unrated, Online Mirror, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/problemset/problem/1267/J
// Memory Limit: 512 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;cin>>n;
	vector<int>a(n+1);
	int mn=1e9;
	map<int,int>mp;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	for(auto[x,y]:mp){
		mn=min(y,mn);//最少的一个有多大用于枚举
	}
	int ans=1e9;
	for(int i=mn+1;i>1;i--){
		int ok=1,res=0;
		for(auto [x,y]:mp){//枚举每一种数量
			int t=(y-1)/i+1;//当前有多少分出多少屏幕给他
			if(t*(i-1)<=y){
				res+=t;//可以分给他
			}
			else{
				ok=0;
				break;
			}
		}	
		if(ok){
			ans=min(ans,res);
		}
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt;cin>>tt;
	while(tt--)solve();
}


