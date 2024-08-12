#include<bits/stdc++.h>
using namespace std;
using LL=long long;

LL lowbit(LL x){
	return x&(-x);
}

void solve(){
	LL n;int q;
	cin>>n>>q;
	
	LL root=(n+1)/2;
	while(q--){
		LL m;cin>>m;	
		string s;cin>>s;
		for(auto x:s){
			if(x=='U'){
				if(m==root)continue;
				LL c=m-lowbit(m);
				LL d=m+lowbit(m);
				//cout<<c<<" "<<d<<" q\n";
				if(d<=n && lowbit(d)/2==lowbit(m)){
					m=d;
				}
				else if(lowbit(c)/2==lowbit(m)){
					m=c;
				}
				
			}
			else if(x=='R'){
				m+=lowbit(m)/2;
			}
			else if(x=='L'){
				m-=lowbit(m)/2;
			}
			//cout<<m<<"ddd\n";
		}
		cout<<m<<"\n";
	}	
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt=1;
	while(tt--)
		solve();
	return 0;
}
