#include<bits/stdc++.h>
using namespace std;
const int N = 605;
int mp[N][N];
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q;
	cin>>q;
	while(q--){
		int n, m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
			}
		}
		int x=n/2;
		int s1=0, s2=0;
		for(int y=1;y<=m;y++){
			s1+=abs(mp[x][y]-mp[x+1][y]);
			s2+=abs(mp[1][y]-mp[n][y]);
		}
		if(s1>s2){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
	return 0;
}
