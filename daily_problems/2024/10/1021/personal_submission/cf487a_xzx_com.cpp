#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ld long double
#define l128 __int128
#define PII pair<int,int>
using namespace std;
const int N=2e5+10,inf=1e18;
signed main() {
    int t=1;
    //cin >> t;
    while (t--) {
    	int hp1,atk1,def1,hp2,atk2,def2;
		cin>>hp1>>atk1>>def1>>hp2>>atk2>>def2;
		int h,a,d;cin>>h>>a>>d;
		int da=max((int)0,def2-atk1+1),a1=max((int)1,atk1-def2);
		int ans=da*a;
		int d1=max((int)0,atk2-def1),ans1=d1*d;
		for(int i=0;i<=d1;i++){
			for(int j=0;j<=100;j++){
				int d2=i+def1,a2=a1+j;
				int t=(hp2+a2-1)/a2;
				int h1=max((int)0,t*(atk2-d2)+1-hp1);
				//if(i==0&&j==0)cout<<t<<' ';
				ans1=min(ans1,h1*h+j*a+i*d);	
			}
		}
		cout<<ans1+ans<<'\n';
    }
    return 0;
}
