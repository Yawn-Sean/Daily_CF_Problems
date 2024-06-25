//链接：https://codeforces.com/problemset/problem/1163/B2

#include<bits/stdc++.h>
using namespace std;

typedef unordered_map<int,int> mp;
const int MAX=1e5+10;
int g[MAX];

int n;

void f(){
    mp num;  //g[i]出现的次数 
	mp cnt;   //词频出现为i的数的个数 
	cnt[1]++;
	num[g[1]]++;
	int big=1;        //最大出现的词频
	int ans=1;	
	for(int i=2;i<=n;i++){
		int p=num[g[i]];      //g[i]出现的次数 
		cnt[p]--;
		num[g[i]]++;
		cnt[p+1]++;
		big=max(big,num[g[i]]);
		if(big==1                 || 
	    	big*cnt[big]==(i-1)   || 
		    (cnt[big-1]+1)*(big-1)==(i-1) )    ans=i;
		
	}
//	for(int i=1;i<=4;i++){
//			printf("%d ",cnt[i]);
//	}
	printf("%d",ans);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&g[i]);
	}
	f();
	
	return 0;
} 
