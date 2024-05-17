#include<bits/stdc++.h>
using namespace std;

void solve(){
	string s;cin>>s;
	s=s+s;
	int t=1,ans=1;
	for(int i=1;i<s.size();i++){
		if(s[i-1]==s[i])
			t=1;
		else{
			t++;
			ans=max(ans,t);
		}
	}
	cout<<min(ans,(int)s.size()/2)<<"\n";
	
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
