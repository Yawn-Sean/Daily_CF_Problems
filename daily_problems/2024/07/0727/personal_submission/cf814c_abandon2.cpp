#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;cin>>n;
	string s;cin>>s;
	s=' '+s;
	vector<array<int,26>>v(n+1);
	for(int c=0;c<26;c++){
	  for(int len=1;len<=n;len++){
		int num=0;
		for(int i=1,j=1;i<=n;){
			while(j<=n&&(num+(s[j]-'a'!=c))<=len){
				num+=(s[j]-'a'!=c);
				j++;
			}
			
			// if(c+'a'=='o')
			// cout<<char(c+'a')<<" "<<len<<" "<<num<<"\n";
				
			v[len][c]=max(v[len][c],j-i);	
			int ok=s[i]-'a'!=c;
			num-=ok;
			//if(c+'a'=='o')
			//cout<<i<<" "<<j<<"\n";
			i++;
		}
	  }
	}
	
	int q;cin>>q;
	while(q--){
		int a;char x;cin>>a>>x;
		cout<<v[a][x-'a']<<"\n";
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
