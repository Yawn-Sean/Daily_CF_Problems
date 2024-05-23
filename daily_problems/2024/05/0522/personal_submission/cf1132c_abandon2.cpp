#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10;
int l[N],r[N];
int c[N],s[N];

void solve(){
	int n,q;cin>>n>>q;
	for(int i=1;i<=q;i++){
		cin>>l[i]>>r[i];
		for(int j=l[i];j<=r[i];j++)
			c[j]++;
	}	
	int mn=1e9;
	for(int i=1;i<=q;i++){
		for(int j=l[i];j<=r[i];j++)
			c[j]--;
		int x=0;
		for(int j=1;j<=n;j++){
			s[j]=s[j-1];
			if(c[j]==1)s[j]++;
			if(c[j]==0)x++;//表示此时已经空出来了
		}

		for(int j=1;j<=q;j++){
			if(i==j)continue;
			mn=min(mn,s[r[j]]-s[l[j]-1]+x);
		}

		for(int j=l[i];j<=r[i];j++)
			c[j]++;

	}
	cout<<n-mn<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
