// Problem: D. Three Logos
// Contest: Codeforces - Codeforces Round 322 (Div. 2)
// URL: https://codeforces.com/problemset/problem/581/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// DateTime : 2025-01-02 14:33:07
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	array<array<int,2>,3> a;
	int area=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<2;j++)cin>>a[i][j];
		if(a[i][0]<a[i][1]) swap(a[i][0],a[i][1]);
		area+=a[i][0]*a[i][1];
	}
	
	int rt=sqrt(area);
	if(rt*rt!=area){
		cout<<-1;
		return;
	}
	if(a[0][0]==rt&&a[1][0]==rt&&a[2][0]==rt&&a[0][1]+a[1][1]+a[2][1]==rt){
		cout<<rt<<"\n";
		for(int i=0;i<a[0][1];i++){
			for(int j=0;j<rt;j++){
				cout<<"A";
			}
			cout<<"\n";
		}
		for(int i=0;i<a[1][1];i++){
			for(int j=0;j<rt;j++){
				cout<<"B";
			}
			cout<<"\n";
		}
		for(int i=0;i<a[2][1];i++){
			for(int j=0;j<rt;j++){
				cout<<"C";
			}
			cout<<"\n";
		}
		return;
	}
	bool flg=false;
	for(int i=0;i<3;i++){
		if(a[i][0]==rt){
			if(a[(i+2)%3][0]+a[(i+1)%3][0]==rt&&a[(i+2)%3][1]==a[(i+1)%3][1]&&a[(i+2)%3][1]+a[i][1]==rt){
				flg=true;
				cout<<rt<<"\n";
				for(int ii=0;ii<a[i][1];ii++){
					for(int j=0;j<rt;j++){
						cout<<char('A'+i);
					}
					cout<<"\n";
				}
				for(int ii=0;ii<a[(i+2)%3][1];ii++){
					for(int j=0;j<a[(i+2)%3][0];j++){
						cout<<char('A'+((i+2)%3));
					}
					for(int j=a[(i+2)%3][0];j<rt;j++){
						cout<<char('A'+((i+1)%3));
					}
					cout<<"\n";
				}
			}else if(a[(i+2)%3][0]+a[(i+1)%3][1]==rt&&a[(i+2)%3][1]==a[(i+1)%3][0]&&a[(i+2)%3][1]+a[i][1]==rt){
				flg=true;
				cout<<rt<<"\n";
				for(int ii=0;ii<a[i][1];ii++){
					for(int j=0;j<rt;j++){
						cout<<char('A'+i);
					}
					cout<<"\n";
				}
				for(int ii=0;ii<a[(i+2)%3][1];ii++){
					for(int j=0;j<a[(i+2)%3][0];j++){
						cout<<char('A'+((i+2)%3));
					}
					for(int j=a[(i+2)%3][0];j<rt;j++){
						cout<<char('A'+((i+1)%3));
					}
					cout<<"\n";
				}
			}else if(a[(i+2)%3][1]+a[(i+1)%3][0]==rt&&a[(i+2)%3][0]==a[(i+1)%3][1]&&a[(i+2)%3][0]+a[i][1]==rt){
				flg=true;
				cout<<rt<<"\n";
				for(int ii=0;ii<a[i][1];ii++){
					for(int j=0;j<rt;j++){
						cout<<char('A'+i);
					}
					cout<<"\n";
				}
				for(int ii=0;ii<a[(i+2)%3][0];ii++){
					for(int j=0;j<a[(i+2)%3][1];j++){
						cout<<char('A'+((i+2)%3));
					}
					for(int j=a[(i+2)%3][1];j<rt;j++){
						cout<<char('A'+((i+1)%3));
					}
					cout<<"\n";
				}
			}else if(a[(i+2)%3][1]+a[(i+1)%3][1]==rt&&a[(i+2)%3][0]==a[(i+1)%3][0]&&a[(i+2)%3][0]+a[i][1]==rt){
				flg=true;
				cout<<rt<<"\n";
				for(int ii=0;ii<a[i][1];ii++){
					for(int j=0;j<rt;j++){
						cout<<char('A'+i);
					}
					cout<<"\n";
				}
				for(int ii=0;ii<a[(i+2)%3][0];ii++){
					for(int j=0;j<a[(i+2)%3][1];j++){
						cout<<char('A'+((i+2)%3));
					}
					for(int j=a[(i+2)%3][1];j<rt;j++){
						cout<<char('A'+((i+1)%3));
					}
					cout<<"\n";
				}
			}
			if(flg) return;
		}
		
	}
	cout<<-1;
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
