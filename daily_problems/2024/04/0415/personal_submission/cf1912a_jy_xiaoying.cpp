//链接：https://codeforces.com/problemset/problem/1912/A
 
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> pp;
ll x,k;

const int MAX=1e5+10;
vector<vv> g=vector<vv>(MAX,vv());

void f(){
	vector<pp> q;
	for(int i=0;i<k;i++){
		int len=g[i].size();
		ll mi=0,ma=0;
		ll pre=0;
		ll sum=0;
		for(int j=0;j<len;j++){
			sum+=g[i][j];
			mi=min(mi,sum);
			//ma=max(ma,sum);
			if(sum>pre){
				q.push_back(pp(mi,sum-pre));
				pre=sum;
			}
		}
	}
	sort(q.begin(),q.end(),[&](const pp &a,const pp &b){
		return a.first>b.first;
	});
	int len=q.size();
	for(int i=0;i<len;i++){
		if(q[i].first+x<0) break;
		x+=q[i].second;
	}
	printf("%lld\n",x);
}

int main(){
	
	scanf("%lld %d",&x,&k);
	int m; int tmp;
	for(int i=0;i<k;i++){
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			scanf("%d",&tmp);
			g[i].push_back(tmp);
		}
	}
	
	f();
	return 0;
}
