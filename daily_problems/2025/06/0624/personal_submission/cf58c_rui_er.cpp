//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int n, a[N], buc[N], ans;

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		scanf("%d", &a[i]);
		a[i] -= min(i, n-i+1);
		if(a[i] >= 0) ans = max(ans, ++buc[a[i]]);
	}
	printf("%d\n", n-ans);
	return 0;
}
