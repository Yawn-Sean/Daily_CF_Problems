#include<bits/stdc++.h>
using namespace std;

#define MAXN 1505

int n,a[MAXN][MAXN],posi[MAXN * MAXN],posj[MAXN * MAXN];
int A[MAXN][MAXN],B[MAXN][MAXN],C[MAXN][MAXN],D[MAXN][MAXN],cnti[MAXN],cntj[MAXN];

signed main(){
	scanf("%d",&n);
	for( int i = 1 ; i <= n ; i ++ )
		for( int j = 1 ; j <= n ; j ++ ){
			scanf("%d",&a[i][j]);
			posi[a[i][j]] = i,posj[a[i][j]] = j;
		}
	long long Ans = 0;
	for( int v = 1 ; v <= n * n ; v ++ ){
		int i = posi[v],j = posj[v];
		A[i][j] = cnti[i],B[i][j] = n - cnti[i] - 1;
		C[i][j] = cntj[j],D[i][j] = n - cntj[j] - 1;
		cnti[i] ++,cntj[j] ++;
		Ans += 1ll * A[i][j] * D[i][j] + 1ll * B[i][j] * C[i][j];
	}
	printf("%lld\n",Ans / 2);
	return 0;
}