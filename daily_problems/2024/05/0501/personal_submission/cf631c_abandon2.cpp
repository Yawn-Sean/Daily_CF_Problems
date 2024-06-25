#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef pair<int,int>PII;
int a[N],q[N],ty[N],stk[N],top,ans[N];

void solve(){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>ty[i]>>q[i];
	}
	for(int i=1;i<=m;i++){
		while(top&&q[stk[top]]<=q[i])
			top--;
		stk[++top]=i;
	}
	
	int cnt=0;
	priority_queue<PII,vector<PII>,greater<PII>>pq;//小根堆
	priority_queue<PII>pqq;//大跟堆
	for(int i=1;i<=q[stk[1]];i++){
		pqq.push({a[i],i});
		pq.push({a[i],i});
	}
	stk[top+1]=0;
	for(int i=1;i<=top;i++){
		int lst=q[stk[i]];
		int now=q[stk[i+1]];
		//cout<<now<<" "<<lst<<"\n";
		if(ty[stk[i]]==1){
			for(int j=lst;j>=now+1;j--){
				ans[j]=pqq.top().first;pqq.pop();
				
			}
		}
		else{
			for(int j=lst;j>=now+1;j--){
				//cout<<pq.top().first<<" "<<j<<"\n";
				ans[j]=pq.top().first;pq.pop();
				
			}
		}
	}
	
	for(int i=1;i<=q[stk[1]];i++){
		cout<<ans[i]<<" ";
	}
	for(int i=q[stk[1]]+1;i<=n;i++)
		cout<<a[i]<<" ";

	cout<<"\n";

}

signed main(){
	int tt=1;
	while(tt--)
		solve();
	return 0;
}
