// Problem: D. Winter Is Coming
// Contest: Codeforces - Codeforces Round 387 (Div. 2)
// URL: https://codeforces.com/problemset/problem/747/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long ll;
#define int long long
int a[N];
void solve(){
	int n,k;cin>>n>>k;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0)
			cnt++;
	}
	int l=0;
	ll num=0;
	vector<int>b;
	for(int i=1;i<=n;i++){
		if(a[i]<0){
			if(l){
				b.push_back(i-l-1);
			}
			l=i;
			num+=2;//一个雪天要换两次
		}
	}
	
	if(cnt>k){
		cout<<"-1\n";return;
	}
	//if(k==cnt){
		//cout<<num<<"\n";
		//return;
	//}
	
	k-=cnt;
	
	sort(b.begin(),b.end());
	//cout<<num<<"\n";
	for(auto x:b){
		//cout<<" s"<<x<<" \n";
		if(k>=x){
			
			k-=x;
			num-=2;
		}
		else{
			break;
		}
	}
	
	if(n-l<=k&&num!=0)//还可以直接换
		num--;
	cout<<num<<"\n";
	//cout<<"\n";
	
	
}


signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt=1;
	while(tt--)solve();
}


