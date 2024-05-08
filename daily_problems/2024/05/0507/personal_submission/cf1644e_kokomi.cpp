#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
char s[N];
int n;
void solve(){
	cin>>n>>s+1;
	ll x=1,y=1;//记录终点位置
	bool flag=1;
	for(int i=1;s[i];i++){
		if(s[i]=='R') x++;
		else y++;
		if(s[i]!=s[i-1]&&i!=1) flag=0;
	}
	if(flag==1){
		//只有一个方向
		cout<<n<<endl;
		return;
	}
	x=n-x,y=n-y;
	ll i=2,ans=1;
	while(s[i]==s[i-1]) ans++,i++;
	for(i;s[i];i++){
		ans++;
		if(s[i]=='R') ans+=y;
		else ans+=x;
		if(s[i+1]==0) ans+=(x+1)*(y+1);
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}