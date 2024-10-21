#include <bits/stdc++.h>
//#define int long long
#define fi first
#define se second
#define ld long double
#define l128 __int128
#define PII pair<int,int>
using namespace std;
const int N=1e3+10;
int a[N][N],l[N],r[N];
signed main() {
    int t=1;
    //cin >> t;
    while (t--) {
       	int n,ans=0;scanf("%d",&n);
       	for(int i=1;i<=n;i++){
       		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				ans+=a[i][j]*a[j][i];
			}
		}
		int q;scanf("%d",&q);
		while(q--){
			int x;scanf("%d",&x);
			if(x==1){
				int y;scanf("%d",&y);
				if((a[y][y]+l[y]+r[y])%2==1)ans=(ans-1)%2;
				else ans=(ans+1)%2;
                l[y]++;
			}else if(x==2){
				int y;scanf("%d",&y);
				if((a[y][y]+l[y]+r[y])%2==1)ans=(ans-1)%2;
				else ans=(ans+1)%2;
                r[y]++;
			}else {
				printf("%d",(ans%2+2)%2);	
			}
		}
    }
    return 0;
}
