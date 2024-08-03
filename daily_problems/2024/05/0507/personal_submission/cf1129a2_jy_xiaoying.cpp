//链接：https://codeforces.com/problemset/problem/1129/A2

#include<bits/stdc++.h>
using namespace std;

const int MAX_N=5010;
const int MAX_M=20010;

int ans[MAX_N];
int cnt[MAX_N];
int small[MAX_N];   //最小步长 
int n,m;

void bulid(){
	for(int i=0;i<=n;i++){
		small[i]=n+10;
		cnt[i]=0;
		ans[i]=0;
	}
}

void f(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			int t=(i+j);
			if(t>n) t-=n;
			if(cnt[t]==0) continue;
			int tmp=(t-i+n)%n+(cnt[t]-1)*n+small[t];
			ans[i]=max(ans[i],tmp);
		}
	}

	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
}
int main(){
	scanf("%d %d",&n,&m);
	bulid();
	
	int l,r;
	for(int i=0;i<m;i++){
		scanf("%d %d",&l,&r);
		cnt[l]++;
		small[l]=min(small[l],(r-l+n)%n);
	}
	
	f();
	return 0;
} 
