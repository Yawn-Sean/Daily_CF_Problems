int n, k, val, mx;
map<int, int> cnt;
int main() {
	scanf("%d%d", &n, &k);
	rep(i, 1, k+1) {
		printf("?");
		rep(j, 1, k+1) if(i != j) printf(" %d", j);
		puts("");
		fflush(stdout);
		scanf("%*d%d", &val);
		++cnt[val];
		chkmax(mx, val);
	}
	printf("! %d\n", cnt[mx]);
	fflush(stdout);
	return 0;
}
