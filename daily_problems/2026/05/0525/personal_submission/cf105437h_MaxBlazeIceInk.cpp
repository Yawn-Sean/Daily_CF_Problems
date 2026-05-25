#include<bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define int long long

int n,pre[MAXN],suf[MAXN];
char s[MAXN];

inline void solve(){
	scanf("%lld%s",&n,s + 1);
	if( n == 2 ){
		if( s[1] == s[2] ) puts("4");
		else puts("2");
		return;
	}
	int ans = 0;
	for( int i = 1 ; i <= n ; i ++ ){
		if( s[i] == s[i - 1] ) pre[i] = pre[i - 1] + 1;
		else pre[i] = 1,ans += pre[i - 1] * pre[i - 1];
	}
	ans += pre[n] * pre[n];
	for( int i = n ; i >= 1 ; i -- ){
		if( s[i] == s[i + 1] ) suf[i] = suf[i + 1] + 1;
		else suf[i] = 1;
	}
	int res = 0;
	for( int i = 1 ; i < n ; i ++ ){
		//swap s[i] and a[i + 1]
		if( s[i] == s[i + 1] ) continue;
		else{
			if( s[i - 1] == s[i] ){
				if( s[i + 2] == s[i + 1] ){
					int tmp = ans;
					tmp -= pre[i] * pre[i],tmp += ( pre[i] - 1 ) * ( pre[i] - 1 );
					tmp -= suf[i + 1] * suf[i + 1],tmp += ( suf[i + 1] - 1 ) * ( suf[i + 1] - 1 );
					tmp += 2;
					res = max( res , tmp );
				}
				else if( s[i + 2] == s[i] ){
					int tmp = ans;
					tmp -= pre[i] * pre[i],tmp += ( pre[i] - 1 ) * ( pre[i] - 1 );
					tmp -= suf[i + 2] * suf[i + 2],tmp += ( suf[i + 2] + 1 ) * ( suf[i + 2] + 1 );
					res = max( res , tmp );
				}
				else{
					int tmp = ans;
					tmp -= pre[i] * pre[i],tmp += ( pre[i] - 1 ) * ( pre[i] - 1 );
					tmp ++;
					res = max( res , tmp );
				}
			}
			else{
				if( s[i + 1] == s[i + 2] ){
					if( s[i - 1] == s[i + 2] ){
						int tmp = ans;
						tmp -= pre[i - 1] * pre[i - 1],tmp += ( pre[i - 1] + 1 ) * ( pre[i - 1] + 1 );
						tmp -= suf[i + 1] * suf[i + 1],tmp += ( suf[i + 1] - 1 ) * ( suf[i + 1] - 1 );
						res = max( res , tmp );
					}
					else{
						int tmp = ans;
						tmp -= suf[i + 1] * suf[i + 1],tmp += ( suf[i + 1] - 1 ) * ( suf[i + 1] - 1 );
						tmp ++;
						res = max( res , tmp );
					}
				}
				else{
					if( s[i - 1] == s[i + 1] && s[i] == s[i + 2] ){
						int tmp = ans;
						tmp -= pre[i - 1] * pre[i - 1],tmp += ( pre[i - 1] + 1 ) * ( pre[i - 1] + 1 );
						tmp -= suf[i + 2] * suf[i + 2],tmp += ( suf[i + 2] + 1 ) * ( suf[i + 2] + 1 );
						tmp -= 2;
						res = max( res , tmp );
					}
					else if( s[i] == s[i + 2] ){
						int tmp = ans;
						// tmp -= pre[i - 1] * pre[i - 1],tmp += ( pre[i - 1] + 1 ) * ( pre[i - 1] + 1 );
						tmp -= suf[i + 2] * suf[i + 2],tmp += ( suf[i + 2] + 1 ) * ( suf[i + 2] + 1 );
						// tmp -= 2;
						res = max( res , tmp - 1 );
					}
					else res = max( res , ans );
				}
			}
		}
	}
	printf("%lld\n",res);
}

signed main(){
	int t = 1;
	while( t -- ) solve();
	return 0;
}