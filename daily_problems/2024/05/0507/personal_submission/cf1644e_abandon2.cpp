#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
void solve(){
	int n;cin>>n;
	string s;cin>>s;
	s=' '+s;
	LL x=0,y=0;
	int f=1;
	for(int i=1;i<s.size();i++){
		if(s[i]!=s[1]){
			f=0;
			break;
		}
	}
	if(f){
		cout<<n<<"\n";return;
	}
	LL fi=0,q=-1;
	for(int i=1;i<s.size();i++){
		if(s[i]!=s[i+1]){
			if(s[i+1]=='R')q=1;
			else q=2;
			fi=i;break;
		}
	}
	for(int i=1;i<s.size();i++){
		if(s[i]=='D')x++;
		else y++;
	}
	LL ans=0;
	ans+=fi-1;
	LL k=x+y+1-fi;
	ans+=n*(n-fi);
	if(q==1){
		y++;
		LL tmp=y*(x-fi+1);
		tmp-=k;
		ans-=tmp;
	}
	else{
		x++;
		LL tmp=x*(y-fi+1);
		tmp-=k;
		ans-=tmp;
	}
	cout<<ans+1<<"\n";
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;cin>>tt;
	while(tt--)
		solve();
	return 0;
}
