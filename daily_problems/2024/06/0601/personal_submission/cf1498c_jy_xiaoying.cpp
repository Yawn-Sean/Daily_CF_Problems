//链接：https://codeforces.com/problemset/problem/1498/C

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int t;
int n,k;

const int MAX=1005;
int dp[MAX][MAX];
const int mod=1e9+7;
int ans[MAX];

int f(){
	for(int j=0;j<=k;j++){
		dp[0][j]=1;
	}
	
	for(int i=0;i<=n;i++){
		dp[i][0]=0;                         //不可能出现寿命为0 的粒子 
	}
	//dp[0][0]=0;
	for(int j=1;j<=k;j++){
		for(int i=1;i<=n;i++){
			dp[i][j]=(dp[i-1][j]+dp[n-i][j-1])%mod;
		}
	}
	return dp[n][k];
}

int main(){
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k;
		ans[i]=f();
	}
	
	for(int i=0;i<t;i++){
		cout<<ans[i]<<"\n";
	}
	return 0;
} 
