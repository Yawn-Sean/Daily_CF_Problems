// Problem: A. Vitaly and Strings
// Contest: Codeforces - Codeforces Round 293 (Div. 2)
// URL: https://codeforces.com/problemset/problem/518/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// DateTime : 2025-01-25 11:08:33
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	string s,t;cin>>s>>t;
	int n=s.length();
	string ans;
	for(int i=0;i<n;i++){
		if(i<n-1){
			if(s[i]==t[i]) ans+=s[i];
			else if(t[i]-s[i]==1){
				ans+=s[i];
				bool flag=true;
				for(int j=i+1;j<n;j++){
					ans+='z';
					if(s[j]!='z') flag=false;
				}
				if(!flag)cout<<ans;
				else{
					ans[i]=s[i]+1;
					flag=true;
					for(int j=i+1;j<n;j++){
						ans[j]='a';
						if(t[j]!='a') flag=false;
					}
					if(!flag) cout<<ans;
					else{
						cout<<"No such string";
						return;
					}
				}
				return;
			}else{
				ans+=s[i]+1;
				for(int j=i+1;j<n;j++){
					ans+='a';
				}
				cout<<ans;
				return;
			}
		}else{
			if(t[i]-s[i]<=1) {
				cout<<"No such string";
				return;
			}else{
				ans+=s[i]+1;
				for(int j=i+1;j<n;j++){
					ans+='a';
				}
				cout<<ans;
				return;
			}
		}
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	// cin>>t;
	while(t--){
		solve();
		if(t)cout<<"\n";
	}
	return 0;
}
