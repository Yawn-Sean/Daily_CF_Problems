#include<bits/stdc++.h>
using namespace std;

#define int long long
int n;

signed main(){
	scanf("%lld",&n);
	int Now = (int)1e18;
	for( int i = 1 ; i <= n ; i ++ ){
		int a,b,c,d,e; scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e);
		int ta = a,tb = b,tc = c,td = d,te = e;
		int res1 = min( td , te ) + min( ta , tb );
		ta -= min( ta , tb ),te -= min( td , te );
		res1 += min( { ta , tc , te } );
		ta = a,tb = b,tc = c,td = d,te = e;
		int res2 = min( td , te ) + min( ta , tb );
		tb -= min( ta , tb ),td -= min( td , te );
		res2 += min( { tb , tc , td } );
		Now = min( Now , max( res1 , res2 ) );
	}
	printf("%lld\n",Now);
	return 0;
}