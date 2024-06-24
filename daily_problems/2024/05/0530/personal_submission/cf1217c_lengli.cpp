#include <bits/stdc++.h>

using namespace std;

void solve(){
	string s;
	cin>>s;
	int n=s.size();
	vector<int> ne(n+2);
	for(int i=n;i>=1;i--){
		if(s[i-1]=='0') ne[i]=ne[i+1];
		else ne[i]=i;
	}
	int res=0;
	for(int i=1;i<=n;i++){
		int k=0;
		for(int j=ne[i];j<=min(20,ne[i]+20);j++){
			k=k*2+s[j-1]-'0';
			if(k==j-i+1) res++;
		}
	}
	cout<<res<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int T;
	cin>>T;
	while(T--) solve();
	
	return 0;
}
