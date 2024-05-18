#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
string s[N];
int v[N],c[N],p[10];

void solve(){
	int n;cin>>n;
	p[0]=1;
	for(int i=1;i<=8;i++)
		p[i]=p[i-1]*10;//10的i次方
	for(int i=1;i<=n;i++){
		cin>>s[i];
		int m=s[i].size(),cnt=0,t=0;
		s[i]=' '+s[i];
		for(int j=1;j<=m;j++){
			if(s[i][j]=='?')
				cnt++;
			else
				t+=(s[i][j]-'0')*p[m-j];
		}
		v[i]=t;
		//cout<<t<<" "<<cnt<<"\n";
		c[i]=cnt;
	}

	int lst=0,now=0;
	for(int i=1;i<=n;i++){
		int now=v[i];
		int m=s[i].size()-1;
		if(!c[i]&&lst>now){
			cout<<"NO\n";return;
		}
		
		int l=-1,r=p[c[i]];
		if(s[i][1]=='?')
			l=p[c[i]-1]-1;
		//cout<<i<<" "<<l<<" "<<r<<"\n";
		int tmp=0,ans=0;
		while(l+1<r){
			int mid=l+r>>1;
			tmp=mid;ans=now;
			for(int j=m;j>=1;j--){
				if(s[i][j]=='?'){
					ans+=(tmp%10)*p[m-j];
					tmp/=10;
				}
			}	
			//cout<<mid<<" "<<now<<"xx\n";
			if(ans>lst)r=mid;
			else l=mid;
			//cout<<l<<" "<<r<<"ccc\n";
		}
		if(r==p[c[i]]){
			cout<<"NO\n";return;
		}
		for(int j=m;j>=1;j--){
			if(s[i][j]=='?'){
				s[i][j]=r%10+'0';
				now+=(r%10)*p[m-j];
				r/=10;
			}
		}	
		//cout<<now<<" "<<lst<<"xx\n";
		lst=now;
		//cout<<"\n";
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++){
		for(int j=1;j<s[i].size();j++)
			cout<<s[i][j];
		cout<<"\n";
	}

}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}
