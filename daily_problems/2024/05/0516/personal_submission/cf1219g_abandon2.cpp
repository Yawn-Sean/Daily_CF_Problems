#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long LL;
LL h[N],l[N];
#define int long long
int n,m;
void solve(){
	cin>>n>>m;
	LL ans=0;
	priority_queue<LL>q;
	vector<vector<int> >a(n+1,vector<int>(m+1));
	for(int i =1;i<=n;i++){
		int t=0;
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			t+=a[i][j];
		}
		h[i]=t;
		q.push(h[i]);
	}
	LL t=0,x=0;
	while(q.size()){
		t++;
		if(t<=4){
			x+=q.top();q.pop();
		}	
		else q.pop();
	}
	ans=max(ans,x);
	//cout<<ans<<"\n";
	for(int j=1;j<=m;j++){
		int t=0;
		for(int i=1;i<=n;i++){
			t+=a[i][j];
		}
		l[j]=t;
		q.push(l[j]);
	}
	t=0,x=0;
	while(q.size()){
		t++;
		if(t<=4){
			x+=q.top();q.pop();
		}	
		else q.pop();
	}
	ans=max(ans,x);
//	cout<<ans<<"\n";
	// for(int i=1;i<=n;i++){
	// 	cout<<h[i]<<"\n";
	// }
	priority_queue<LL>qx[n+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			qx[i].push(l[j]-a[i][j]);
		}
	}

	for(int i=1;i<=n;i++){
		LL x=0,t=0;
		while(qx[i].size()&&t<3){
			t++;
			x+=qx[i].top();qx[i].pop();
		}
		ans=max(ans,h[i]+x);
		//cout<<h[i]+x<<" ";
	}
	priority_queue<LL>qy[m+1];
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			qy[j].push(h[i]-a[i][j]);
		}
	}
	for(int j=1;j<=m;j++){
		LL x=0,t=0;
		while(qy[j].size()&&t<3){
			t++;
			x+=qy[j].top();qy[j].pop();
		}
		ans=max(ans,l[j]+x);
	}

	if(n<=m){
		priority_queue<LL>qxx[n+1][n+1];

		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=1;k<=m;k++){
					qxx[i][j].push(l[k]-a[i][k]-a[j][k]);
				}
			}
		}

		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				LL x=0,t=0;
				while(qxx[i][j].size()&&t<2){
					t++;
					x+=qxx[i][j].top();qxx[i][j].pop();
				}
				//cout<<i<<" "<<j<<" "<<x<<"x\n";
				ans=max(ans,h[i]+h[j]+x);
			}
		}
	}
	else{

		priority_queue<LL>qxx[m+1][m+1];

		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				for(int k=1;k<=n;k++){
					qxx[i][j].push(h[k]-a[k][i]-a[k][j]);
				}
			}
		}

		for(int i=1;i<=m;i++){
			for(int j=i+1;j<=m;j++){
				LL x=0,t=0;
				while(qxx[i][j].size()&&t<2){
					t++;
					//cout<<qxx[i][j].top()<<" "<<"xx\n";
					x+=qxx[i][j].top();qxx[i][j].pop();
				}
				//cout<<i<<" "<<j<<" "<<x<<"pp\n";
				ans=max(ans,l[i]+h[j]+x);
			}
		}

	}

	cout<<ans<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
