#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
#define int long long
int siz[N];
char c[N];
int n;
void solve(){
	string s;cin>>s;
	int n=s.size();s=' '+s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]==c[cnt])siz[cnt]++;
		else c[++cnt]=s[i],siz[cnt]=1;
	}
	int ans=0;
	while(cnt>1){
		for(int i=1;i<=cnt;i++){
			if(i==cnt||i==1)siz[i]--;
			else siz[i]-=2;
		}
		// for(int i=1;i<=cnt;i++){
			// cout<<siz[i]<<" "<<c[i]<<"\n";
		// }
		int cur=0;
		for(int i=1;i<=cnt;i++){
			if(siz[i]<=0)continue;
			
			//cout<<cur<<" "<<i<<"\n";
			if(c[i]==c[cur])siz[cur]+=siz[i];
			else c[++cur]=c[i],siz[cur]=siz[i];
			//cout<<cnt<<" "<<siz[cnt]<<"pp\n";
		}
		//cout<<cur<<"\n";
		cnt=cur;
		ans++;
	}
	cout<<ans<<"\n";

}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
