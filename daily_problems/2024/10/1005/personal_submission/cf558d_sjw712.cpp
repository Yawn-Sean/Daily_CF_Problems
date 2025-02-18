cf558d_yawn_sean.cppconst int INF = 1e18;
void solve(){
	int n, q;
	cin >> n >> q;
	vector<pii> good, bad;
	while(q --){
		int d, l, r, ans;
		cin >> d >> l >> r >> ans;
		int L = l * (1ll << (n - d));
		int R = r * (1ll << (n - d)) + (1ll << (n - d)) - 1;
		if(ans == 1) good.push_back({L, R});
		else bad.push_back({L, R});
	}
	auto merge = [](pii &a, pii b)->bool{
		int x1 = a.x, y1 = a.y;
		int x2 = b.x, y2 = b.y;
		if(y2 < x1 || x2 > y1) return false;
		if(x2 <= x1) y1 = min(y1, y2);
		if(y2 >= y1) x1 = max(x1, x2);
		if(y2 < y1 && x2 > x1) x1 = x2, y1 = y2;
		pii res = {x1, y1};
		a = res;
		return true;
	};
	while(good.size() > 1){
		auto a = good.back();
		good.pop_back();
		auto b = good.back();
		good.pop_back();
		if(merge(a, b)) good.push_back(a);
		else{
			return cout << "Game cheated!" << '\n', void();
		}
	}
	if(!good.size()) good.push_back({1ll << (n - 1), (1ll << n) - 1});
	auto merge_seg = [](vector<pii> &segs)->void{
	    vector<pii> res;
	    sort(segs.begin(), segs.end());
	    int st = -INF, ed = -INF;
	    for (auto seg : segs)
	        if (ed + 1 < seg.first){
	            if (st != -INF) res.push_back({st, ed});
	            st = seg.first, ed = seg.second;
	        }
	        else ed = max(ed, seg.second);
	    if (st != -INF) res.push_back({st, ed});
	    segs = res;
	};	
	auto check = [](pii &a, pii b)->int{
		int x1 = a.x, y1 = a.y;
		int x2 = b.x, y2 = b.y;
		if(x1 >= x2 && y1 <= y2) return -1;
		if(y2 < x1 || x2 > y1) return 1;
		if(x2 > x1 && y2 < y1) return 0;
		if(x2 > x1) y1 = x2 - 1;
		if(y2 < y1) x1 = y2 + 1;
		pii res = {x1, y1};
		a = res;
		return 1;
	};
	merge_seg(bad);
	for(auto i : bad){
		int res = check(good[0], i);
		if(res == 0){
			return cout << "Data not sufficient!" << '\n', void();
		}
		else if(res == -1){
			return cout << "Game cheated!" << '\n', void();
		}
	}
	int x = good[0].x, y = good[0].y;
	if(x == y) cout << x << '\n';
	else if(x < y) cout << "Data not sufficient!" << '\n';
	else cout << "Game cheated!" << '\n';
}
