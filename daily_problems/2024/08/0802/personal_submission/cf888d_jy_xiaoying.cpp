//链接：https://codeforces.com/problemset/problem/888/D  
//  2024-8-2

#include<bits/stdc++.h> 
using namespace std;

int n,k;
typedef long long ll;

const int MAX=1010;
ll comb[MAX];      //错排
ll dp[MAX][MAX];   //组合数C(i,j) i个数里选j个 

auto bbt=[](){
	comb[1]=0;
	comb[0]=comb[2]=1;
	for(int i=3;i<MAX;i++){
		comb[i]=(i-1)*(comb[i-1]+comb[i-2]);
	}
	return 0;
}();

ll dfs(int i,int j){
	if(i==j) return 1;
	if(i<j) return 0;
	if(j==0) return 1;
	if(i==0) return 0;
	ll &res=dp[i][j];
	if(res!=-1) return res;
	
	return res=dfs(i-1,j)+dfs(i-1,j-1);
}

void f(){
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j]=-1;
		}
	}
	
	ll ans=0;
	for(int i=0;i<=k;i++){
		ans+=dfs(n,i)*comb[i];
	}
	cout<<ans<<endl;
}

int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>k;
    f();
    
    return 0;
    
}
