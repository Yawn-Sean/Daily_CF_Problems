#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/665/D

//   情况1：子集中没有1 ，满足条件只能为1个奇数和1个偶数，且两者相加为素数 
//   情况2：子集出现多个1，可最多加上一个偶数，且该偶数+1 为素数 

//日期： 2024-3-16 
//格式化： ctrl+shift+ a

const int MAX=2e6+10;
int n;
int nums[2010];
int cnt;   // 数组中1出现的次数
bool is_pri[MAX];  

vector<int> ans;

void build(){
	for(int i=2;i<MAX;i++){
		if(is_pri[i]) continue;
		for(int j=2*i;j<MAX;j+=i){
			is_pri[j]=1;
		}
	}
} 

void f(){
	if(cnt>=2){
		for(int j=0;j<cnt;j++) ans.push_back(1);
		
		for(int i=0;i<n;i++){
			if(nums[i]!=1 && !is_pri[1+nums[i]]){
				ans.push_back(nums[i]);
				return ;
			}
		}
		
		return ;
	}
	
	else{
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int tmp=nums[i]+nums[j];
				if(!is_pri[tmp]){
					ans={nums[i],nums[j]};
					return ;
				}
			}
		}
	}
	
	//否则ans中只能有一个数
	ans={nums[0]}; 
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin>>n;
    cnt=0;
    for(int i=0;i<n;i++){
    	cin>>nums[i];
    	if(nums[i]==1) cnt++;
	}
	
	build();
	f();
	
	cout<<ans.size()<<endl;
	for(int x:ans){
		cout<<x<<" ";
	}
	cout<<endl;

	return 0;
}
/*


*/

