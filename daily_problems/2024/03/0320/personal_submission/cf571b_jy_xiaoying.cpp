#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/571/B

//  dp
//  

//日期： 2024-3-20
//格式化： ctrl+shift+ a

int n,k;
typedef long long ll;
const int MAX=3e5+10;
const ll inf=LLONG_MAX/10;

ll nums[MAX];
ll dp[5003][5003];

void f(){
	int cnt_x=n%k,cnt_y=k-cnt_x;
	int len_x=n/k+1,len_y=n/k;
	
	for(int i=0;i<=cnt_x;i++){
		for(int j=0;j<=cnt_y;j++){
			if(i==0 && j==0) dp[i][j]=0;
			else{
				if(i-1>=0){
					int E_end=i*len_x+j*len_y;
					int B_begin=(i-1)*len_x+j*len_y+1;
					dp[i][j]=min(dp[i][j],dp[i-1][j]+nums[E_end]-nums[B_begin]);
				}
				if(j-1>=0){
					int E_end=i*len_x+j*len_y;
					int B_begin=i*len_x+(j-1)*len_y+1;
					dp[i][j]=min(dp[i][j],dp[i][j-1]+nums[E_end]-nums[B_begin]);
				}
			}
		}
	}
	
	cout<<dp[cnt_x][cnt_y]<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


    cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>nums[i];
	} 
	
	sort(nums+1,nums+n+1);
	for(int i=0;i<=k;i++){
		for(int j=0;j<=k;j++){
			dp[i][j]=inf;
		}
	}
	
	f();
	
	

	return 0;
}
/*


*/

