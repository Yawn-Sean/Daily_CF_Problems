		#include<bits/stdc++.h>
		using namespace std;
		using ll = long long;
		#define pb push_back
		#define pii pair<int,int>
		#define int long long
		#define i128 __int128
        #define ull unsigned long long
        int f(int x,int b){
            int sum=0;
            while(x){
                int s=x%b;
                sum^=s;
                x/=b;
            }
            return sum;
        }
		void solve()
		{		
			int x;
            cin>>x;
            int ans=0;
            for(int b=2;b<min(x,1000000ll);b++){
                if(f(x,b)==0) ans++;
            }
            if(x<=1000000){
                cout<<ans<<"\n";
                return;
            }
            for(int i=1;i*i<=x;i++){
                if(x%i==0){
                    if(i-1>1000000) ans++;
                    if(x/i-1>1000000&&x/i!=i) ans++;
                }
            }
            cout<<ans;
		}
		int32_t main() {
			cin.tie(0)->sync_with_stdio(0);
			int tc = 1;
			//cin >> tc;
			while (tc--) solve();
			return 0;
			}
