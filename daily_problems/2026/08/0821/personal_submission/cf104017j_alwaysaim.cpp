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
			int w,l;
			cin>>w>>l;
			int a1=gcd(w-1,l-1),a2=gcd(w-2,l),a3=gcd(w,l-2);
			set<int>ans;
			ans.insert(2);
			auto f=[&](int x)->void{
				for(int i=1;i*i<=x;i++){
					if(x%i==0) ans.insert(i),ans.insert(x/i);
				}
			};
			f(a1),f(a2),f(a3);
			cout<<ans.size()<<" ";
			for(auto x:ans) cout<<x<<" ";
			cout<<"\n";
		}
	
		int32_t main() {
			cin.tie(0)->sync_with_stdio(0);
			int tc = 1;
			cin >> tc;
			while (tc--) solve();
			return 0;
			}
