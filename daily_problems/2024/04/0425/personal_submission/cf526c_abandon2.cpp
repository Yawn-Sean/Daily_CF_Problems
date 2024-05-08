// Problem: C. Om Nom and Candies
// Contest: Codeforces - ZeptoLab Code Rush 2015
// URL: https://codeforces.com/problemset/problem/526/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int c,hr,hb,wr,wb;
	cin>>c>>hr>>hb>>wr>>wb;
	int ans=0;
	for(int i=0;i*i<=c;i++){
		if(i*wr<=c){
			ans=max(ans,i*hr+(c-i*wr)/wb*hb);
		}
		if(i*wb<=c){
			ans=max(ans,i*hb+(c-i*wb)/wr*hr);
		}
	}
	cout<<ans<<"\n";
	
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt=1;
	while(tt--)solve();
}


