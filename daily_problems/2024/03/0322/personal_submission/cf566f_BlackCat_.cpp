#include <iostream>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>
#define endl '\n'
const int maxn=1e6;
void slove(){
	int n;
	std::cin>>n;
	std::vector<int> a(n);
	for(int i=0;i<n;i++){
		std::cin>>a[i];
	}
	std::vector<int> dp(maxn+10,0);
	for(int i=0;i<n;i++){
		dp[a[i]]+=1;
		for(int j=1;j*a[i]<=1e6;j++){
			dp[j*a[i]]=std::max(dp[j*a[i]],dp[a[i]]);
		}
	}
	int ans=0;
	for(int i=1;i<=maxn;i++){
		ans=std::max(ans,dp[i]);
	}
	std::cout<<ans<<'\n';
}
int main() {
	std::cin.tie(0);
	std::cout.tie(0);
	std::ios::sync_with_stdio(false);
	int t=1;
	while(t--){
		slove();
	}
	return 0;
}
