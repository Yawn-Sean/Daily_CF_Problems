#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/855/E
//日期： 2024-3-7
//格式化： ctrl+shift+ a

typedef long long ll;
ll dp[11][65][1030];  //i进制下，枚举到了第j个数位，状态为status
int dig[65];
int len; 

int q;
int b;
ll l,r;

//  来到第j个数位， 状态为status ，是否为前导0，填数是否有限制 
ll dfs(int j,int status,int is_ok,int limits){
	if(j==-1) return  status==0 ?1:0;
	
	if(!is_ok &&!limits && dp[b][j][status]!=-1) return dp[b][j][status];
	
	ll ans=0;
	if(limits==0){  //可以自由填数字 
		for(int i=0;i<b;i++){
			ans+=dfs(j-1, (is_ok==1 && i==0)?0:status^(1<<i), (is_ok==1 && i==0)?1:0, 0);
		}
	}
	else{    //不可以自由填数字 
		for(int i=0;i<dig[j];i++){
			ans+=dfs(j-1, (is_ok==1 && i==0)?0:status^(1<<i), (is_ok==1 && i==0)?1:0, 0);
		}
		ans+=dfs(j-1,status^(1<<dig[j]),0,1);
	}
	
	if(!is_ok && !limits) 
	dp[b][j][status]=ans;
	return ans;
}

ll f(ll x){
	len=0;
	while(x){
		dig[len++]=x%b;
		x/=b;
	}
	return dfs(len-1,0,1,1);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    memset(dp,-1,sizeof(dp));   //初始化一遍即可 
    cin>>q;
    while(q--){
    	cin>>b>>l>>r;
    	ll ans=f(r)-f(l-1);
    	cout<<ans<<endl;
	}

	return 0;
}


