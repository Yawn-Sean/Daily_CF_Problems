// Problem: A. Rebus
// Contest: Codeforces - Codeforces Round 347 (Div. 1)
// URL: https://codeforces.com/problemset/problem/663/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// DateTime : 2025-01-06 14:30:19
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	vector<int> a{1};
	string x;cin>>x;
	string op;
	int n;
	int pos=1,neg=0;
	while(cin>>op>>x){
		if(op=="-") a.push_back(-1),neg++;
		else if(op=="+") a.push_back(1),pos++;
		else if(op=="="){
			n=stoll(x);
		}
	}
	if(n<pos-n*neg||n>pos*n-neg){
		cout<<"Impossible";
	}else{
		cout<<"Possible\n";
		int m=a.size();
		int sum=0;
		for(int i=0;i<m;i++){
			if(a[i]==1) sum+=1;
			else sum-=n;
		}
		sum=n-sum;
		for(int i=0;i<m;i++){
			if(sum>0){
				if(sum>=n-1){
					if(a[i]==1){
						if(i!=0)cout<<" + ";
						cout<<n;
						sum-=n-1;
					}else{
						cout<<" - "<<1;
						sum-=n-1;
					}
				}else{
					if(a[i]==1){
						if(i!=0)cout<<" + ";
						cout<<1+sum;
						sum=0;
					}else{
						cout<<" - "<<abs(sum-n);
						sum=0;
					}
				}
			}else{
				if(a[i]==1){
					if(i!=0)cout<<" + ";
					cout<<1;
				}else{
					cout<<" - "<<n;
				}
			}
			
		}
		cout<<" = "<<n;
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
