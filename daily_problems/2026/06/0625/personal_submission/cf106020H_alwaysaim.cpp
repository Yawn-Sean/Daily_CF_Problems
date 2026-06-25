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
			vector<int>a(n+1,0);
			vector<int>p;
			p.pb(0);
			for(int i=1;i<=n;i++){
				cin>>a[i];
				if(a[i]!=0) p.pb(i);
			}
			p.pb(n+1);
			vector<int>l(n+1,0),r(n+1,0);
			int ans=0;
			int cur=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) cur++;
				else{
					l[i]=cur;
					cur=0;
				}
			}
			cur=0;
			for(int i=n;i>=1;i--){
				if(a[i]==0) cur++;
				else{
					r[i]=cur;
					cur=0;
				}
			}
			int s=p.size();
			for(int i=1;i<s-2;i++){
				if((a[p[i]]==1&&a[p[i+1]]==1)||(a[p[i]]==1&&a[p[i+1]]==2)||(a[p[i]]==2&&a[p[i+1]]==1)){
					ans+=(p[i]-p[i-1])*(p[i+2]-p[i+1]);
					if(p[i+1]-p[i]==1) ans--;
				}
			}
			cout<<ans<<"\n";
		}
		
		
		int32_t main() {
			cin.tie(0)->sync_with_stdio(0);
			int tc = 1;
			//cin >> tc;
			while (tc--) solve();
			return 0;
			}
