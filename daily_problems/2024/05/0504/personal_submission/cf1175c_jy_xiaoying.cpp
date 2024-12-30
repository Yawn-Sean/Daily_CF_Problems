//链接：https://codeforces.com/problemset/problem/1175/C

#include<bits/stdc++.h>
using namespace std;

int T;
const int MAX=2e5+10;
int g[MAX];
typedef long long ll;
int n,k;

void f(){
	ll big=LLONG_MAX;
	ll ans;
	for(int i=1;i<=n-k;i++){
		if(g[i+k]-g[i]<big){
			big=g[i+k]-g[i];
			ans=(g[i+k]+g[i])/2;
		}
	}
	printf("%lld\n",ans);
}

int main(){
	scanf("%d",&T);
	
	while(T--){
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++){
			scanf("%d",&g[i]);
		}
		f();
	}
	return 0;
}
 
