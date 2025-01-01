// Problem: D. Divisible by Twenty-Five
// Contest: Codeforces - COMPFEST 13 - Finals Online Mirror (Unrated, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/problemset/problem/1575/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// DateTime : 2024-12-31 10:52:23
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	string s;cin>>s;
	int n=s.length();
	if(n>1&&s[0]=='0'){
		cout<<0;
		return;
	}
	if(n>2){
		int cnt=count(s.begin(),s.end(),'X');
		if(cnt==0){
			int c=count(s.begin(),s.begin()+n-2,'_');
			int ans=0;
			for(auto x:{"00","25","50","75"}){
				if((s[n-2]=='_'||s[n-2]==x[0])&&(s[n-1]=='_'||s[n-1]==x[1])){
					ans+=(10-(s[0]=='_'))*pow(10,c-1);
				}
			}
			cout<<ans;
			
		}else{
			int ans=0;
			for(char j=(s[0]=='X')?'1':'0';j<='9';j++){
				auto t=s;
				for(char&ch:t){
					if(ch=='X')ch=j;
				}
				int c=count(t.begin(),t.begin()+n-2,'_');
				for(auto x:{"00","25","50","75"}){
					if((t[n-2]=='_'||t[n-2]==x[0])&&(t[n-1]=='_'||t[n-1]==x[1])){
						ans+=(10-(t[0]=='_'))*pow(10,c-1);
					}
				}
			}
			cout<<ans;
		}
	}else if(n==2){
		if(s=="XX"){
			cout<<0;
			return;
		}
		int ans=0;
		for(auto x:{"25","50","75"}){
			if((s[0]=='X'||s[0]=='_'||s[0]==x[0])&&(s[1]=='X'||s[1]=='_'||s[1]==x[1])){
				ans++;
			}
		}
		cout<<ans;
	}else{
		if(s=="0"||s=="_"||s=="X"){
			cout<<1;
		}else{
			cout<<0;
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
