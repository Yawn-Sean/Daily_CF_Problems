//链接：https://codeforces.com/problemset/problem/900/C

#include<bits/stdc++.h>
using namespace std;

const int MAX=1e5+10;

int g[MAX];
int cnt[MAX];

int n;
void build(){
	for(int i=0;i<=n;i++) cnt[i]=0;
}

void f(){
	int a=-1,b=-1;  //最大值、次大值 
	for(int i=1;i<=n;i++){
		int u=g[i];
		if(u>a){
			cnt[u]--;
			b=a;
			a=u;
		}
		else if(u>b){
			cnt[a]++;
			b=u;
		}
	}
	int ans=0,sum=INT_MIN;
	for(int i=1;i<=n;i++){
		int u=g[i];
		if(cnt[u]>sum){           //自身是前缀最大，删掉自己必然会少一个 
			sum=cnt[u];
			ans=u;
		}
		else if(sum==cnt[u]){
			ans=min(ans,u);
		}
	}
	
	cout<<ans<<"\n";
}

int main(){
	cin>>n;
	build();
	for(int i=1;i<=n;i++){
		cin>>g[i];
	}
	if(n==1){
		cout<<g[1]<<"\n";
		return 0;
	}
	f();
	return 0;
} 
