// Problem: C. Hidden Word
// Contest: Codeforces - Canada Cup 2016
// URL: https://codeforces.com/problemset/problem/725/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// DateTime : 2025-01-03 12:22:31
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long


void solve(){
	string s;cin>>s;
	vector<int> pos(26,-1);
	int dis=0;
	char alp;
	for(int i=0;i<s.length();i++){
		if(pos[s[i]-'A']==-1){
			pos[s[i]-'A']=i;
		}else{
			if(i-pos[s[i]-'A']<=1){
				cout<<"Impossible";
				return;
			}else{
				dis=i-pos[s[i]-'A'];
				alp=s[i];
			}
		}
	}
	dis=(dis+1)/2;
	int bias=13-pos[alp-'A']-dis;
	string t=s;
	t.erase(t.find_last_of(alp),1);
	t+=t;
	int start=(-bias+26)%26;
	for(int i=0;i<13;i++){
		cout<<t[i+start];
	}
	cout<<"\n";
	for(int i=0;i<13;i++){
		cout<<t[start+26-i-1];
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
		if(t)cout<<"\n";
	}
	return 0;
}
