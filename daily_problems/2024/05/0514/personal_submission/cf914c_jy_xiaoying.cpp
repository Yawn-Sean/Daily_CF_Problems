//链接：https://codeforces.com/problemset/problem/914/C

#include<bits/stdc++.h>
using namespace std;

const int MAX=1010;

string s;
int k;
int n;    //字符串 s 的长度 

typedef long long ll;
const int mod=1e9+7;
 
int ops[MAX];    // 数字i 变为 1 的操作次数 
int sum[MAX];   //  数字 i 有几个 1

int dp[MAX][MAX][2];

int lowbit(int x){
	return x & (-x);
}

auto jiuhb=[](){                   //预处理 
	sum[0]=0;
	sum[1]=1;
	for(int i=2;i<MAX;i++){
		sum[i]=sum[i ^ lowbit(i)]+1;
	}
	ops[0]=0;
	ops[1]=0;
	for(int i=2;i<MAX;i++){
		ops[i]=ops[sum[i]]+1;
	}
	return 0;
}();

int dfs(int i,int c,int lit){   // 来到i位置 填了c个1 是否可以随意填 
	if(i==n){
		if(c==0) return 0;
		return (1+ops[c]==k);    //字符s 操作一次 变为了 j个1（二进制） 
	}                            // (二进制下) j个1 变为 1 的操作为： ops[j] 
	
	if(dp[i][c][lit]!=-1) return dp[i][c][lit];
	
	ll ans=0;
	if(lit==1){
		ans=(ans+dfs(i+1,c+1,lit))%mod;   // 填 1 
		ans=(ans+dfs(i+1,c,lit))%mod;     // 填 0
	}
	else{
		if(s[i]=='1'){
			ans=(ans+dfs(i+1,c+1,0))%mod;   // 填 1 
		    ans=(ans+dfs(i+1,c,1))%mod;     // 填 0
		}
		else{
		    ans=(ans+dfs(i+1,c,0))%mod;     // 填 0
		}
	}
	dp[i][c][lit]=ans;
	return ans;
} 


void build(){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j][0]=dp[i][j][1]=-1;
		}
	}
}

int main(){
	
	cin>>s;
	cin>>k;
	n=s.size();
	
	
	if(k==0){                   //这2个特判先后顺序不能乱 
		cout<<"1"<<endl;
		return 0;
	}
	
	if(s=="1"){
		cout<<"0"<<endl;
		return 0;
	}
	build();
	
	
	int res=dfs(0,0,0);
	if(k==1) res-=1;          //特判 1 不用操作 
	cout<<res<<"\n";
	
	return 0;
} 
