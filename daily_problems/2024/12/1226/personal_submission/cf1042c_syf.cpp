// Problem: C. Array Product
// Contest: Codeforces - Codeforces Round 510 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1042/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// DateTime : 2024-12-26 11:01:55
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n;cin>>n;
	vector<int> a(n);
	vector<int> pos,zero,neg;
	int mn=INT_MIN,mnId=-1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>0) pos.push_back(i);
		else if(a[i]==0) zero.push_back(i);
		else {
			neg.push_back(i);
			if(a[i]>mn){
				mn=a[i];
				mnId=i;
			}
		}
	}
	if(zero.size()>0){
		for(int i=1;i<zero.size();i++){
			cout<<"1 "<<zero[i]+1<<" "<<zero[0]+1<<"\n";
		}
		for(int i=1;i<pos.size();i++){
			cout<<"1 "<<pos[i]+1<<" "<<pos[0]+1<<"\n";
		}
		if(neg.size()>0){
			if(neg.size()%2==0){
				for(int i=1;i<neg.size();i++){
					cout<<"1 "<<neg[i]+1<<" "<<neg[0]+1<<"\n";
				}
				if(pos.size()>0){
					cout<<"1 "<<neg[0]+1<<" "<<pos[0]+1<<"\n";
				}
				cout<<"2 "<<zero[0]+1<<"\n";
			}else{
				if(neg[0]!=mnId){
					for(int i=1;i<neg.size();i++){
						if(neg[i]==mnId){
							cout<<"1 "<<neg[i]+1<<" "<<zero[0]+1<<"\n";
						}else{
							cout<<"1 "<<neg[i]+1<<" "<<neg[0]+1<<"\n";
						}
					}
					if(pos.size()>0){
						cout<<"1 "<<neg[0]+1<<" "<<pos[0]+1<<"\n";
					}
					cout<<"2 "<<zero[0]+1<<"\n";
				}else if(neg.size()==1){
					cout<<"1 "<<neg[0]+1<<" "<<zero[0]+1<<"\n";
					if(pos.size()>0)
						cout<<"2 "<<zero[0]+1<<"\n";
				}else{
					cout<<"1 "<<neg[0]+1<<" "<<zero[0]+1<<"\n";
					for(int i=2;i<neg.size();i++){
						cout<<"1 "<<neg[i]+1<<" "<<neg[1]+1<<"\n";
					}
					if(pos.size()>0){
						cout<<"1 "<<neg[1]+1<<" "<<pos[0]+1<<"\n";
					}
					cout<<"2 "<<zero[0]+1<<"\n";
				}
			}
		}else{
			if(pos.size()>0)
				cout<<"2 "<<zero[0]+1<<"\n";
		}

	}else{
		if(neg.size()%2==1){
			for(int i=1;i<pos.size();i++){
				cout<<"1 "<<pos[i]+1<<" "<<pos[0]+1<<"\n";
			}
			if(neg[0]!=mnId){
				for(int i=1;i<neg.size();i++){
					if(neg[i]==mnId){
						cout<<"2 "<<neg[i]+1<<"\n";
					}else{
						cout<<"1 "<<neg[i]+1<<" "<<neg[0]+1<<"\n";
					}
				}
				if(pos.size()>0)
					cout<<"1 "<<neg[0]+1<<" "<<pos[0]+1<<"\n";
			}else if(neg.size()==1){
				cout<<"2 "<<neg[0]+1<<"\n";
			}else{
				cout<<"2 "<<neg[0]+1<<"\n";
				for(int i=2;i<neg.size();i++){
					cout<<"1 "<<neg[i]+1<<" "<<neg[1]+1<<"\n";
				}
				if(pos.size()>0)
					cout<<"1 "<<neg[1]+1<<" "<<pos[0]+1<<"\n";
			}
		}else{
			for(int i=1;i<pos.size();i++){
				cout<<"1 "<<pos[i]+1<<" "<<pos[0]+1<<"\n";
			}
			if(neg.size()>0){
				for(int i=1;i<neg.size();i++){
					cout<<"1 "<<neg[i]+1<<" "<<neg[0]+1<<"\n";
				}
				if(pos.size()>0)
					cout<<"1 "<<neg[0]+1<<" "<<pos[0]+1<<"\n";
			}
		}
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
