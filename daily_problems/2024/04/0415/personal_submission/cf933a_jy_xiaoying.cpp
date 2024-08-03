#include<bits/stdc++.h>
using namespace std;

int n;
const int MAX=2e3+10;
int nums[MAX];

void f(){
	int dp1=0,dp12=0,dp121=0,dp1212=0;
	for(int i=0;i<n;i++){
		if(nums[i]==1){
			dp1+=1;
			dp121+=1;
		}
		else{
			dp12+=1;
			dp1212+=1;
		}
		dp12=max(dp12,dp1);
		dp121=max(dp121,dp12);
		dp1212=max(dp1212,dp121);
	}
	
	int ans=max({dp1,dp12,dp121,dp1212});
	printf("%d\n",ans);
}

int main(){
	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&nums[i]);
	}
	
	f();
	return 0;
}
