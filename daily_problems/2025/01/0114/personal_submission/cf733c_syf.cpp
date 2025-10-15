// Problem: C. Epidemic in Monstropolis
// Contest: Codeforces - Codeforces Round 378 (Div. 2)
// URL: https://codeforces.com/problemset/problem/733/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// DateTime : 2025-01-14 11:56:23
// Author : sunyafei
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n;cin>>n;
	vector<int> a(n);
	for(int&x:a)cin>>x;
	int k;cin>>k;
	vector<int> b(k);
	for(int&x:b)cin>>x;
	
	int sum=0,pre=0,j=0;
	vector<pair<int,int>> ans;
	vector<pair<int,int>> d;
	for(int i=0;i<n;i++){
		sum+=a[i];
		if(j>=k) {
			cout<<"NO";
			return;
		}
		if(sum==b[j]){
			d.push_back({pre,i});
			pre=i+1;
			sum=0;
			j++;
		}
	}
	if(sum!=0||j!=k){
		cout<<"NO";
		return;
	}
	int start=1;
	for(auto&[l,r]:d){
		// cout<<l<<" "<<r<<endl;
		if(l==r) {
			start++;
			continue;
		}
		int mx=*max_element(a.begin()+l,a.begin()+r+1);
		if(count(a.begin()+l,a.begin()+r+1,mx)==r-l+1){
			cout<<"NO";
			return;
		}
		for(int i=l;i<=r;i++){
			if(a[i]==mx){
				if(i>l&&a[i]>a[i-1]){
					for(int j=i-1;j>=l;j--){
						ans.emplace_back(start+j+1-l,0);
					}
					for(int j=i+1;j<=r;j++){
						ans.emplace_back(start,1);
					}
					break;
				}else if(i+1<=r&&a[i]>a[i+1]){
					for(int j=i+1;j<=r;j++){
						ans.emplace_back(start+i-l,1);
					}
					for(int j=i-1;j>=l;j--){
						ans.emplace_back(start+j+1-l,0);
					}
					break;
				}
			}
		}
		start++;
	}
	cout<<"YES\n";
	// cout<<ans.size()<<"\n";
	for(auto&[x,y]:ans){
		cout<<x<<" "<<(y?"R":"L")<<"\n";
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
