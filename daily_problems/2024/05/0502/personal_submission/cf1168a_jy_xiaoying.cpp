//链接： https://codeforces.com/problemset/problem/1168/A

#include<bits/stdc++.h>
using namespace std;

int n,m;
const int MAX=3e5+10;
int g[MAX];

bool check(int tar){
	int pre=g[1];   //遍历到i位置，前面最大的元素 
	for(int i=1;i<=tar;i++){
		pre=min(pre,(g[1]+i)%m);
	}
    //int pre=0;
	int cnt;
	for(int i=2;i<=n;i++){
		if(g[i]<=pre){
			cnt=pre-g[i];
			if(cnt>tar) return 0;
		}
		else{
			cnt=m-g[i]+pre;
			if(cnt<=tar){
				//将g[i]变为pre 
			}
			else
				pre=g[i];  //g[i]维持原状 
			
		}
	}
	return 1;
}

void f(){
	int l=0,r=m;
	int ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}
		else
		   l=mid+1;
	}
	printf("%d",ans);
}

int main(){
    scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&g[i]);
	}	
	
	f();
	return 0;
} 

//10 1000
//981 824 688 537 969 72 39 734 929 718

