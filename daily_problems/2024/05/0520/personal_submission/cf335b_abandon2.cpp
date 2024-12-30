#include<bits/stdc++.h>
using namespace std;
const int N=5e4+10;
int dp[2700][2700],mp[26];
char ans[120];
void solve(){
	string s;cin>>s;int n=s.size();
	s=' '+s;
	if(n>=2600){
		for(int i=1;i<=n;i++){
			mp[s[i]-'a']++;
		}
		for(char i=0;i<=25;i++){
			if(mp[i]>=100){
				for(int j=1;j<=100;j++){
					cout<<char(i+'a');
				}
				return ;
			}
		}	
	}
	for(int i=n;i>=1;i--){
		dp[i][i]=1;
		for(int j=i+1;j<=n;j++){
			if(s[i]==s[j]){
				dp[i][j]=dp[i+1][j-1]+2;
			}
			else{
				dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
			}
		}
	}
	int tot=0;
	int x=1,y=n;
	int cnt=min(dp[1][n],100);
	while(x<=y){
		if(s[x]==s[y]){
			ans[++tot]=s[x];
			//cout<<x<<" "<<y<<"\n";
			x++,y--;
		}
		else if(dp[x+1][y]>dp[x][y-1])
			x++;
		else 
			y--;
	}
	//cout<<tot<<"\n";
	for(int i=1;i<=min(tot,50);i++)
		cout<<ans[i];
	if(cnt%2==0){
		cout<<ans[min(tot,50)];
	}
	for(int i=min(tot-1,49);i>=1;i--)
		cout<<ans[i];
}
signed main(){
	solve();
	return 0;
}
