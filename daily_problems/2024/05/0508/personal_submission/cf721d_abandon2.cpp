#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long LL;
LL a[N];

struct node{
	int p;
	bool operator<(const node&v)const{
		return abs(a[p])>abs(a[v.p]);
	}
};

void solve(){
	int n,k,x;cin>>n>>k>>x;
	for(int i=1;i<=n;i++)cin>>a[i];
	int cnt=0;//当前有多少个数字小于0,要保持在奇数个
	priority_queue<node>q;
	for(int i=1;i<=n;i++){
		q.push((node)i);
		if(a[i]<0)cnt++;
	}
	while(k--&&q.size()){
		int t=q.top().p;q.pop();
		if(a[t]<0){//当前最小的数字小于0
			if(cnt%2==0){//如果当前有偶数个小于0的，那么积为正数，让其变小
				a[t]+=x;
				if(a[t]>=0)
					cnt--;
			}
			else{//如果现在是奇数个，已经是负数了，让其减小即可
				a[t]-=x;
			}
		}
		else{
			if(cnt%2==0){
				a[t]-=x;
				if(a[t]<0)
					cnt++;
			}
			else{
				a[t]+=x;
			}
		}
		q.push((node)t);
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}

}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
