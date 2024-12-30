//链接：https://codeforces.com/problemset/problem/1019/A

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vv;
typedef pair<int,int> pp;   //<政党，花费>

int n,m;                //n个投票人  m个政党 
const int MAX=3010;
vector<pp> cost(MAX);



void f(){
	sort(cost.begin(),cost.begin()+n,[&](const pp &a,const pp &b){
		return a.second>b.second;
	});
	ll ans=LLONG_MAX;   //票：ticket 
	int id,p;
	for(int t=1;t<=n;t++){     //其他党的票数 <t !!!    (1号党 >=t) 
		vector<bool> vis(n+5,0);
		vector<int> cnt(m+5,0);
		ll tmp=0;
		for(int j=0;j<n;j++){
			id=cost[j].first,p=cost[j].second;
			cnt[id]++;
			if(id!=1 && cnt[id]>=t){
				tmp+=p;
				vis[j]=1;
				cnt[1]+=1;
			}
		}
		for(int j=n-1;j>=0 && cnt[1]<t;j--){
			if(cost[j].first==1 || vis[j]) continue;
			tmp+=cost[j].second;
			cnt[1]+=1;
		}
		ans=min(ans,tmp);
	}
	
	ans=ans==LLONG_MAX?0:ans;
	printf("%lld",ans);
}

int main(){
	
	scanf("%d %d",&n,&m);

	int id,p;
	for(int i=0;i<n;i++){
		scanf("%d %d",&id,&p);
		cost[i]=pp(id,p);
	}
	
	f();
	return 0;
} 
