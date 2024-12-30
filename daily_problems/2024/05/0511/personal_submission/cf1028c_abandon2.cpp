#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],b[N],x[N],y[N];
int qa[N],qb[N],qx[N],qy[N];
int ha[N],hb[N],hx[N],hy[N];

void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>x[i]>>y[i];	
	qa[0]=qb[0]=-2e9;
	qx[0]=qy[0]=2e9;
	for(int i=1;i<=n;i++){
		qa[i]=max(qa[i-1],a[i]);
		qb[i]=max(qb[i-1],b[i]);
		qx[i]=min(qx[i-1],x[i]);
		qy[i]=min(qy[i-1],y[i]);
		//cout<<qa[i]<<" "<<qb[i]<<" "<<qx[i]<<" "<<qy[i]<<"\n";
	}
	ha[n+1]=hb[n+1]=-2e9;
	hx[n+1]=hy[n+1]=2e9;
	for(int i=n;i>=1;i--){
		ha[i]=max(ha[i+1],a[i]);
		hb[i]=max(hb[i+1],b[i]);
		hx[i]=min(hx[i+1],x[i]);
		hy[i]=min(hy[i+1],y[i]);
	}
	for(int i=1;i<=n;i++){
		int A=max(qa[i-1],ha[i+1]);
		int B=max(qb[i-1],hb[i+1]);
		int C=min(qx[i-1],hx[i+1]);
		int D=min(qy[i-1],hy[i+1]);
		//cout<<A<<" "<<B<<" "<<C<<" "<<D<<"\n";
		if(A<=C&&B<=D){
			cout<<A<<" "<<B<<"\n";
			return;
		}
	}

}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
