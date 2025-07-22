#include<bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
	int n;
	cin>>n;
	vector<int>a(2*n+1,0);
	for(int i=1; i<=2*n; i++){
		cin>>a[i];
	}
	vector<int>ve,dp(n+1,-1);
	int l=1;
	for(int i=2; i<=2*n; i++){
		if(a[i]>a[l]){
			ve.push_back(i-l);
			l=i;
		}
	}
	ve.push_back(2*n-l+1);
	dp[0]=0;
	int cnt=0;
	for(auto v:ve){
		//cout<<v<<endl;
		cnt++;
		for(int j=n; j>=v; j--){
			if(dp[j-v]!=-1 && dp[j]==-1)dp[j]=cnt;
		}

	}
	//for(int i=0; i<=n; i++)cout<<dp[i]<<" \n"[i==n];
	vector<bool>vis(ve.size()+1,0);
	if(dp[n]==-1){
		cout<<-1<<endl;
	}else{
		int p=n;
		while(p){
		//	cout<<p<<endl;
			vis[dp[p]]=true;
			p=p-ve[dp[p]-1];
		}
		int l=1;
		for(int i=0; i<ve.size(); i++){
				if(vis[i+1]==true){
					for(int j=l; j<l+ve[i]; j++){
						cout<<a[j]<<' ';
					}
				}
				l+=ve[i];
		}cout<<endl;
		l=1;
		for(int i=0; i<ve.size(); i++){
			if(vis[i+1]==false){
					for(int j=l; j<l+ve[i]; j++){
						cout<<a[j]<<' ';
					}
			}
			l+=ve[i];
		}cout<<endl;
	}
	
}
signed main(){
	 
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
	
} 