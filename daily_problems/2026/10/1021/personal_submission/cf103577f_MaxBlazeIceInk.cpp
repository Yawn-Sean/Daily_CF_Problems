#include<bits/stdc++.h>
using namespace std;

#define MAXN 5005

int que[MAXN][MAXN << 1],head[MAXN],rear[MAXN],tmp[MAXN];
int n,q,sumr[MAXN],sumc[MAXN],ans;
char s[MAXN][MAXN];

signed main(){
	scanf("%d%d",&n,&q);
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%s",s[i] + 1);
		head[i] = 5002,rear[i] = 5001;
		for( int j = 1 ; j <= n ; j ++ )
			que[i][++rear[i]] = s[i][j] - '0',sumr[i] += s[i][j] - '0',sumc[j] += s[i][j] - '0';
	}
	for( int i = 1 ; i <= n ; i ++ ) ans += sumr[i] == n,ans += sumc[i] == n;
	for( int i = 1 ; i <= q ; i ++ ){
		int op; scanf("%d",&op);
		if( op == 1 ){
			int i,j,c; scanf("%d%d%d",&i,&j,&c);
			ans -= sumr[i] == n;
			ans -= sumc[j] == n;
			sumr[i] -= que[i][head[i] + j - 1];
			sumc[j] -= que[i][head[i] + j - 1];
			que[i][head[i] + j - 1] = c;
			sumr[i] += que[i][head[i] + j - 1];
			sumc[j] += que[i][head[i] + j - 1];
			ans += sumr[i] == n;
			ans += sumc[j] == n;
		}
		else{
			int x; scanf("%d",&x);
			for( int j = 1 ; j <= n ; j ++ ) tmp[j] = sumc[j],ans -= sumr[j] == n,ans -= sumc[j] == n;
			sumc[1] = 0;
			for( int i = 1 , lst = x ; i <= n ; i ++ ){
				sumc[1] += lst;
				sumr[i] += lst;
				que[i][--head[i]] = lst;
				lst = que[i][rear[i] --];
				sumr[i] -= lst;
			}
			for( int i = n ; i > 1 ; i -- ) sumc[i] = tmp[i - 1];
			for( int i = 1 ; i <= n ; i ++ ) ans += sumr[i] == n,ans += sumc[i] == n;
		}
		printf("%d\n",ans);
	}
	return 0;
}