#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/788/A

//   dp

//日期： 2024-3-14
//格式化： ctrl+shift+ a

const int MAX=1e5+10;
typedef long long ll;

ll dp[MAX][2];
ll nums[MAX];
int n;

void f() {
	dp[0][0]=nums[0],dp[0][1]=0;
	ll ans=dp[0][0];
	for(int i=1; i<n-1; i++) {
		dp[i][0]=max(nums[i],dp[i-1][1]+nums[i]);
		dp[i][1]=dp[i-1][0]-nums[i];
		ans=max({ans,dp[i][0],dp[i][1]});
	}
	
	cout<<ans<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	ll pre,tmp;
	cin>>pre;
	for(int i=0; i<n-1; i++) {
		cin>>tmp;
		nums[i]=abs(pre-tmp);
		pre=tmp;
	}

	f();


	return 0;
}
/*


*/

