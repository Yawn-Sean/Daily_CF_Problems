//链接：https://codeforces.com/problemset/problem/1954/D

#include<bits/stdc++.h>
using namespace std;

const int MAX=5005;
int dp[MAX][MAX];
typedef long long ll;
const int mod=998244353;

int n;
int g[MAX];
int total;

void f(){
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	sort(g,g+n);
	
	vector<int> sum(total+1,0);
	sum[0]=1;
	ll ans=0;
	for(int i=0;i<n;i++){
		int x=g[i];
		//ans=0;
		for(int j=total;j>=x;j--){
			//if(sum[j-x]==0) continue;
			
			dp[i][j]=(dp[i][j]+sum[j-x])%mod;
			ans=(ans+dp[i][j]*(ll)(max((j+1)/2,x)))%mod;
			sum[j]=(sum[j]+dp[i][j])%mod;
		}
	}
	
	cout<<ans<<"\n";	
}

int main(){
	cin>>n;
	total=0;
	for(int i=0;i<n;i++) {
		cin>>g[i];
		total+=g[i];
	}
	f();
	
	return 0;
} 

//设 
//dp[i][j][k]:选到第i种小球  选了j个球，出现最多的球的数量为 k 的方案数
// 排序后可以省去 k 
