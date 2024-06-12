// Problem: C. Serval and Parenthesis Sequence
// Contest: Codeforces - Codeforces Round 551 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1153/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

const int N=100010;

void solve(){
	int n;
	std::string s;
	std::cin>>n>>s;
	int cnt=0;
	for(auto x:s){
		cnt+=(x=='(');
	}
	std::string res="";
	for(auto x:s){
		if(x=='?'){
			if(cnt<n/2) cnt++,res+='(';
			else res+=')';
		}else res+=x;
	}
	bool flag=1;
	int sum=0;
	for(int i=0;i<n;i++){
		char x=res[i];
		if(x=='(') sum++;
		else sum--;
		if(sum<0) flag=0;
		if(sum==0 and i<n-1) flag=0;
	}
	if(flag and !sum) std::cout<<res;
	else std::cout<<":(";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
