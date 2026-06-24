		#include<bits/stdc++.h>
		using namespace std;
		using ll = long long;
		#define pb push_back
		#define pii pair<int,int>
		#define int long long
		#define i128 __int128
    #define ull unsigned long long
    const int MAXN=1000005;
		vector<int>fac[MAXN];
        void sieve(){
            for(int i=1;i<MAXN;i++){
                for(int j=i;j<MAXN;j+=i)
                fac[j].pb(i);
            }
        }
		void solve()
		{		
			int n,q;
            cin>>n>>q;
            vector<int>a(n+1,0);
            map<int,int>m;
            for(int i=1;i<=n;i++){
                cin>>a[i];
                m[a[i]]++;
            }
            map<int,int>mp;
            for(auto x:m)
            mp[x.second]++;
            vector<int>ans(MAXN,0);
            for(int i=1;i<MAXN;i++){
                for(int k=1;k*i<=n;k++){
                    int w=k*i;
                    ans[i]+=mp[w];
                }
            }
            for(int i=0;i<q;i++){
                int s;
                cin>>s;
                if(s==1){
                    int w,y;
                    cin>>w>>y;
                    int e=m[a[w]];
                    for(auto x:fac[e]) ans[x]--;
                    for(auto x:fac[e-1]) ans[x]++;
                    m[a[w]]--;
                    a[w]=y;
                    int r=m[y];
                    for(auto x:fac[r]) ans[x]--;
                    for(auto x:fac[r+1]) ans[x]++;
                    m[y]++;
                }
                else{
                    int x;
                    cin>>x;
                    cout<<ans[x]<<"\n";
                }
            }
		}
		int32_t main() {
			cin.tie(0)->sync_with_stdio(0);
			int tc = 1;
			//cin >> tc;
      sieve();
			while (tc--) solve();
			return 0;
			}
