		#include<bits/stdc++.h>
		using namespace std;
		using ll = long long;
		#define pb push_back
		#define pii pair<int,int>
		#define int long long
		#define i128 __int128
        #define ull unsigned long long
        
		void solve()
		{		
			int n;
			cin>>n;
			vector<vector<int>>a(n+1,vector<int>()),b(n+1,vector<int>());
			map<int,int>ma,mb;
			int sa=0,sb=0;
			for(int i=1;i<=n;i++){
				int l;
				cin>>l;
				for(int j=0;j<l;j++){
					int w;
					cin>>w;
					a[i].pb(w);
					ma[w]++;
				}
				sa+=l;
			}
			for(int i=1;i<=n;i++){
				int l;
				cin>>l;
				for(int j=0;j<l;j++){
					int w;
					cin>>w;
					b[i].pb(w);
					mb[w]++;
				}
				sb+=l;
			}
			if(sa!=sb){
				cout<<'N'<<"\n";
				return;
			}
			for(auto x:ma){
				if(x.second!=mb[x.first]){
					cout<<'N'<<"\n";
					return;
				}
			}
			if(n==1){
				cout<<"S"<<"\n";
				return;
			}
			if(n>=3){
				cout<<"S"<<"\n";
				return;
			}
			int d=b[1].size()-a[1].size();
			if(d==0){
				for(int i=0;i<a[1].size();i++){
					if(a[1][i]!=b[1][i]){
						cout<<'N'<<"\n";
						return;
					}
				}
				for(int i=0;i<a[2].size();i++){
					if(a[2][i]!=b[2][i]){
						cout<<'N'<<"\n";
						return;
					}
				}
				cout<<'S'<<"\n";
			}
			else if(d>0){
				while(d--){
					a[1].pb(a[2].back());
					a[2].pop_back();
				}
				for(int i=0;i<a[1].size();i++){
					if(a[1][i]!=b[1][i]){
						cout<<'N'<<"\n";
						return;
					}
				}
				for(int i=0;i<a[2].size();i++){
					if(a[2][i]!=b[2][i]){
						cout<<'N'<<"\n";
						return;
					}
				}
				cout<<'S'<<"\n";
			}
			else if(d<0){
				d=-d;
				while(d--){
					a[2].pb(a[1].back());
					a[1].pop_back();
				}
				for(int i=0;i<a[1].size();i++){
					if(a[1][i]!=b[1][i]){
						cout<<'N'<<"\n";
						return;
					}
				}
				for(int i=0;i<a[2].size();i++){
					if(a[2][i]!=b[2][i]){
						cout<<'N'<<"\n";
						return;
					}
				}
				cout<<'S'<<"\n";
			}
		}
		int32_t main() {
			cin.tie(0)->sync_with_stdio(0);
			int tc = 1;
			//cin >> tc;
			while (tc--) solve();
			return 0;
			}
