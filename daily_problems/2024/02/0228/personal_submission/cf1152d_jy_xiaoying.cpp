 #include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1152/D
//日期：2024-2-28
//格式化： ctrl+shift+ a


typedef long long ll;
ll mod=1e9+7;

const int MAX=1010;
ll dp[MAX][MAX];
int n;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin>>n;
    
    ll ans=0;   
	 
    dp[1][1]=1;
    for(int i=2;i<=n+1;i++){   // n+1 !!!      
    	for(int j=1;j<=i;j++){
    		if(i>=j)
    		dp[i][j]=(dp[i-1][j]*(i-1>=j?1:0)+dp[i][j-1])%mod;
    		

    		//dp[i][j]: 合法子树：i个左括号>=j个右括号 
    		//贪心的只选深度 为奇数的子树 
    		if((i+j)%2) ans=(ans+dp[i][j])%mod;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}
