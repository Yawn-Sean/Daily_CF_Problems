#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/566/F

//   数论 + dp
//   

//日期： 2024-3-22 
//格式化： ctrl+shift+ a

const int MAX=1e6+10;
typedef long long ll;
int cnt[MAX];
int dp[MAX];

int n;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin>>n;
    int tmp; int big=-1;
    for(int i=0;i<n;i++){
    	cin>>tmp;
    	big=max(big,tmp);
    	cnt[tmp]++;
	}
	
	int ans=0;
	for(int i=1;i<=big;i++){      //从1开始 
		dp[i]+=cnt[i];
		ans=max(ans,dp[i]);
		for(int j=2*i;j<=big;j+=i){
			dp[j]=max(dp[j],dp[i]);   //根据因子传递最大的集合 
		}
	}
	
	cout<<ans<<endl;
 
	return 0;
}
/*


*/

