#include<bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
	int n,m;
	cin>>n>>m;
	vector<int>a(n,0);
	vector<int>mm(101,0);
	for(int i=0; i<n; i++){
		cin>>a[i];
		mm[a[i]]++;
	}
	vector<int>ve;
	int mx=0;
	for(int i=1; i<=100; i++){
		if(mm[i]){
			ve.push_back(mm[i]);
			mx=max(mx,mm[i]);
		}
	}
	int sum=n;
	sort(a.begin(),a.end());
	if(mx>sum-mx){
		cout<<2*sum-2*mx<<endl;
	}else cout<<sum<<endl;
	for(int i=0; i<n; i++){
		cout<<a[i]<<' '<<a[(i+mx)%n]<<endl;
	}
	
	
}
signed main(){
	 
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
	
} 