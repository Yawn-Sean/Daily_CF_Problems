#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1102/F

//       状压dp + 枚举 
//思路：

//日期： 2024-4-10
//格式化： ctrl+shift+ a


const int MAX_N=16;
const int MAX_M=1e4+10;
typedef long long ll;

const ll NA=INT_MIN;
ll nums[MAX_N][MAX_M];
ll dp[(1<<MAX_N)+5][MAX_N][MAX_N];

ll small[MAX_N][MAX_N];
ll small_2[MAX_N][MAX_N];   //i做首行 j做末尾行 错位元素之间的差值 的min 

int n,m;

void init() {
	for(int i=0;i<((1<<n)+2);i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				dp[i][j][k]=-1;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ll tmp=INT_MAX;
			for(int k=0;k<m;k++){
				tmp=min(tmp,abs(nums[i][k]-nums[j][k]));
			}
			ll tmp_2=INT_MAX;
			for(int k=0;k<m-1;k++){
				tmp_2=min(tmp_2,abs(nums[i][k+1]-nums[j][k]));
			}
			small[i][j]=tmp;
			small_2[i][j]=tmp_2;
		}
	}
}

ll f(int status,int i,int j){
	if(status==(1<<n)-1){
		return small_2[i][j];
	}
	
	if(dp[status][i][j]!=-1){
		return dp[status][i][j];
	}
	
	ll ans=NA;
	for(int k=0;k<n;k++){
		if((status>>k) & 1) continue;
		
		ll tmp_y=small[j][k];
		
		int ops=status | (1<<k);
		ll tmp_res=f(ops,i,k);
		ans=max(ans,min(tmp_y,tmp_res));
	}
	
	dp[status][i][j]=ans;
	return ans;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>nums[i][j];
		}
	} 
	init();
    
    if(n==1){                 //特判 只有 1 行的情况 
    	ll ans=INT_MAX;
    	for(int j=0;j<m-1;j++){
    		ans=min(ans,abs(nums[0][j]-nums[0][j+1]));
		}
		cout<<ans<<endl;
		return 0;
	}
	
    ll k=NA;
    for(int i=0;i<n;i++){      //  第一行 
    	for(int j=0;j<n;j++){  //  最后一行 
    		if(i==j) continue;
    		int status=(1<<i) | (1<<j);
    		ll tmp=f(status,i,j);
    		tmp=min(tmp,small[i][j]);
    		
    		k=max(k,tmp);
		}
	}
	
	cout<<k<<endl;

	return 0;
}
/*

1 2
11 21


*/

