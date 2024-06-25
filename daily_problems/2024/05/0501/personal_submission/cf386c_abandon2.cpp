#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
typedef long long LL;
int a[N];
LL g[N],f[N];
int n;

void chi(int m){
	LL cnt=0,ans=0;
	map<int,int>mp;
	for(int l=1,r=0;r<n;){
		r++;
		if(mp[a[r]]==0)cnt++;
		mp[a[r]]++;
		while(cnt>m){
			if(mp[a[l]]==1)
				cnt--;
			mp[a[l]]--;
			l++;
		}
		if(cnt<=m)ans+=r-l+1;
	}
	g[m]=ans;
}



void solve(){
	string s;cin>>s;
	n=s.size();
	s=' '+s;
	set<int>st;
	for(int i=1;i<=n;i++){
		a[i]=s[i]-'a'+1;
		st.insert(a[i]);
	}
	int t=st.size();

	for(int i=1;i<=t;i++){
		chi(i);
	}
	for(int i=1;i<=t;i++){
		f[i]=g[i]-g[i-1];
	}
	
	cout<<t<<"\n";
	for(int i=1;i<=t;i++){
		cout<<f[i]<<"\n";
	}
}

signed main(){
	int tt=1;
	while(tt--)
		solve();
	return 0;
}
