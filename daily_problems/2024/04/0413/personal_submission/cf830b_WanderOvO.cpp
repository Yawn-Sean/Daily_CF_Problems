/*
找到最左边的最小的，删除它，然后继续找最小的
看每个数 a[i]右边是否有比自己小的，找到最小的那个的最左位置 pos，这会带来 a[i] 的一次移动
pos 右边的不会再造成 a[i] 的移动
之后再看 [i, pos - 1] 中最小且最左的，这也会带来一次移动
不断枚举最小的数，统计到答案中
*/

int T;
LL n, a[N];
set<LL> s[N];

void solve2() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[a[i]].insert(i);
    }
    
    sort(a + 1,a + n + 1);
    LL pos = 1, res = n;
    for (int i = 1; i <= n; i++) {
    	auto it = s[a[i]].lower_bound(pos);
    	if (it == s[a[i]].end()) {
    	    // 后面没有了，再回到前面找
    		res += n - i + 1;
    		pos = 1;
    		it = s[a[i]].lower_bound(pos);
    	}
    	pos = *it;
    	s[a[i]].erase(it);
    }
    cout << res << "\n";
}           
