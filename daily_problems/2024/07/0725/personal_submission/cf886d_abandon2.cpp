#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;cin>>n;
	vector<string>s(n+1);
	vector<int>c(100),pre(100),suf(100);
	
	for(int i=1;i<=n;i++){
		cin>>s[i];	
	}
	for(int i=1;i<=n;i++){
		vector<int>v(100);
		for(auto x:s[i]){
			c[x-'a'+1]++;
			if(v[x-'a'+1]){
				cout<<"NO\n";return;
			}
			v[x-'a'+1]=1;
		}	
	}
	
	for(int i=1;i<=n;i++){
		int m=s[i].size();
		for(int j=0;j<m;j++){
			if(j!=0){
				if(pre[s[i][j]-'a'+1]&&pre[s[i][j]-'a'+1]!=s[i][j-1]-'a'+1){
					cout<<"NO\n";return;
				}
				pre[s[i][j]-'a'+1]=s[i][j-1]-'a'+1;
			}
			
			if(j!=m-1){
				if(suf[s[i][j]-'a'+1]&&suf[s[i][j]-'a'+1]!=s[i][j+1]-'a'+1){
					cout<<"NO\n";return;
				}
				suf[s[i][j]-'a'+1]=s[i][j+1]-'a'+1;
			}
			
		}
	}
	
	int k=0;
	vector<string>ss(100);
	vector<int>v(66);
	for(int i=0;i<=60;i++){
		if(c[i]&&!pre[i]){
			int now=i;
			++k;
			//cout<<(char)(now-1+'a')<<" dddd\n";
			while(now){
				v[now]=1;
				ss[k]+=char(now+'a'-1);
				now=suf[now];
			}
		}
	}
	for(int i=0;i<=55;i++){
		if(c[i]&&!v[i]){
			cout<<"NO\n";return;
		}
	}
	
	sort(ss.begin()+1,ss.begin()+k);
	for(int i=1;i<=k;i++){
		cout<<ss[i];
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
