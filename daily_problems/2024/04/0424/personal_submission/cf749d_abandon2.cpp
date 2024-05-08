// Problem: D. Leaving Auction
// Contest: Codeforces - Codeforces Round 388 (Div. 2)
// URL: https://codeforces.com/problemset/problem/749/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
const ll inf=1e18;
struct node{
	int id,val;
	bool operator<(const node&v)const{
		return val>v.val;
	}
};
node p[N];
vector<int>a[N];

void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int id,val;cin>>id>>val;
		p[id]={id,val};
		a[id].push_back(val);
		
	}
	
	
	
	sort(p+1,p+1+n);
	int q;cin>>q;
	while(q--){
		int k;cin>>k;
		map<int,int>mp;//标记退出的人
		for(int i=1;i<=k;i++){
			int x;cin>>x;
			mp[x]=1;
		}
		int ok=0;
		for(int i=1;i<=n;i++){
			if(p[i].id==0)break;
			if(mp.count(p[i].id)==0){
				int top=p[i].id;
				int second=0;
				for(int j=i+1;j<=n;j++){
					if(mp.count(p[j].id)==0){
						second=p[j].id;
						break;
					}
				}
				//cout<<top<<"\n";
				//cout<<second<<"\n";
				//cout<<a[second].back()<<"\n";
				if(second==0){
					cout<<top<<" "<<a[top].front()<<"\n";
					//return;
				}
				else{
			cout<<top<<" "<<*upper_bound(a[top].begin(),a[top].end(),a[second].back());
					cout<<"\n";
					//return;
				}
				ok=1;
				break;
			}
		}
		if(!ok){
			cout<<"0 0\n";
		}
		
	}
	
}

signed main()
{
	ios::sync_with_stdio(0),cin.tie(0);
	int tt=1;
	while(tt--)solve();
}


