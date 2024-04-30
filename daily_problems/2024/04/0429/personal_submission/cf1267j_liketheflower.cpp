//https://codeforces.com/contest/1267/submission/258631838
int INF = 1e9;
int get_ret(int x, vector<int>& vals){
    int ret = 0;
    for (auto v: vals){
	if (v % x == 0){
	    ret += v / x ;
	} else {
	    int this_cnt = v / x;
	    int remain = v % x;
	    if (remain + this_cnt < x - 1){
		return INF;
	    }
	    ret += this_cnt + 1;
	}
    }
    return ret;
}
void solve(){
    int n; cin >> n;
    vector<int>a(n);
    unordered_map<int, int> cnt;
    for(int i=0; i<n; i++){
	cin >> a[i];
	cnt[a[i]]++;
    }
    vector<int> vals;
    for (auto [k, v]: cnt){
	vals.push_back(v);
    }
    auto min_val = *min_element(vals.begin(), vals.end());
    int ret = INF;
    for (int i = 1; i <= min_val + 1; i++){
	auto this_ret = get_ret(i, vals);
	ret = min(ret, this_ret);
    }
    cout << ret << endl;
}
