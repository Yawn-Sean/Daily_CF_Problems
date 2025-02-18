void solve(){
	string a, b, c;
	cin >> a >> b >> c;
	int la = a.size(), lb = b.size(), lc = c.size();
	vector<int> cnt1(26), cnt2(26), cnt3(26);
	for(int i = 0; i < la; i ++){
		cnt1[a[i] - 'a'] ++;
	}
	for(int i = 0; i < lb; i ++){
		cnt2[b[i] - 'a'] ++;
	}
	for(int i = 0; i < lc; i ++){
		cnt3[c[i] - 'a'] ++;
	}
	int mx = 0, cnt = 0;
	string ans = "";
	for(int i = 0; i <= max(la / lb, la / lc); i ++){
		bool ok = true;
		vector<int> tmp(cnt1.begin(), cnt1.end());
		for(int j = 0; j < 26; j ++){
			if(cnt2[j] * i <= tmp[j]){
				tmp[j] -= cnt2[j] * i;
			}
			else{
				ok = false;
				break;
			}
		}
		if(ok){
			int mn = 1e9;
			for(int j = 0; j < 26; j ++){
				if(cnt3[j]) mn = min(mn, tmp[j] / cnt3[j]);
			}
			if(i + mn > mx){
				mx = i + mn;
				cnt = i;
			}
		}
	}
	for(int i = 0; i < cnt; i ++) ans += b;
	for(int i = 0; i < mx - cnt; i ++) ans += c;
	for(int i = 0; i < 26; i ++){
		cnt1[i] -= cnt * cnt2[i];
		cnt1[i] -= (mx - cnt) * cnt3[i];
		if(cnt1[i]){
			for(int j = 0; j < cnt1[i]; j ++){
				ans += (char)(i + 'a');
			}
		}
	}
	cout << ans << '\n';
}
