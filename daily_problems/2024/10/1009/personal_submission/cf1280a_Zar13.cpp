#include<bits/stdc++.h>
using namespace std;
const int N=1000005, mod=1e9+7;
int a[N];
int main(){
	int T;
	cin>>T;
	while(T--){
		int x;
		string s;
		cin>>x>>s;
		int len=s.size();
		for(int i=1;i<=len;i++) a[i]=s[i-1]-'0';
		int res=len;
		int st=0, et=len;
		while(st<x){
			st++;
			int qres=res;
			res=(res+(res-st+mod)%mod*(a[st]-1)%mod)%mod;
			int c=a[st]-1;
			while(c--&& et<x){
				for(int i=st+1;i<=qres&& et<x;i++) a[++et]=a[i];
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
