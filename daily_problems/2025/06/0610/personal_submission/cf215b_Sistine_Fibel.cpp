int n;
bool check(vector<int> a, vector<int> b){
    for(int i = 1; i <= n; i ++)
        if(a[i] != b[i])
            return false;
    return true;
}

signed main (){
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  //atc默认关闭，cf按需开启
	while(t --)
		solve();
}

void solve(){
    int k;
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1), d(n + 1), c(n + 1);
    for(int i = 1; i <= n; i ++)
	    c[i]=i;
	for(int i = 1; i <= n; i ++)
	    cin >> a[i];
	for(int i = 1; i <= n; i ++)
	    cin >> b[i];
    int s = 0, t = 0; //没初始化 WA 一发呜呜
	for(int i = 1; i <= k; i ++){
		for(int j = 1; j <= n; j ++)
		    d[j]=c[a[j]];
		for(int j = 1; j <= n; j ++)
		    c[j]=d[j];
		if(check(c, b)) {
			s=i;
			break;
		}
	}
	for(int i = 1; i <= n; i ++)
	    c[i]=i;
	for(int i = 1; i <= k; i ++) {
		for(int j = 1; j <= n; j ++)
		    d[a[j]]=c[j];
		for(int j = 1; j <= n; j ++)
		    c[j]=d[j];
		if(check(c, b)) {
			t=i;
			break;
		}
	}
	for(int i = 1; i <= n; i ++)
	    c[i]=i;
	if(check(c, b))
	    printf("NO");
	else if(s == 1 && t == 1 && k > 1)
	    printf("NO");
	else if((k - s) % 2 == 0 && s)
	    printf("YES");
	else if((k - t) % 2 == 0 && t)
	    printf("YES");
	else
	    printf("NO");
}
// ٩ (◕‿◕�?) ۶

