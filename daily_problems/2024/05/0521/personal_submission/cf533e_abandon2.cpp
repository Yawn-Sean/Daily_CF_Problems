#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;cin>>n;
	string a,b;cin>>a>>b;
	a=' '+a;b=' '+b;
	int l=n,r=1;
	for(int i=1;i<=n;i++){
		if(a[i]!=b[i]){
			l=min(l,i);
			r=max(r,i);
		}
	}	

	if(r==l){
		cout<<2<<"\n";return;
	}
	int f1=1,f2=1;
	for(int i=l+1;i<=r;i++){
		if(a[i]!=b[i-1]){
			f1=0;
		}
		if(a[i-1]!=b[i]){
			f2=0;
		}
	}

	cout<<max(0,f1+f2)<<"\n";
}

signed main(){
	solve();
	return 0;
}
