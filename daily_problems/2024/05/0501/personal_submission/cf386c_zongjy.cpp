void solve() {
    std::string s;
    std::cin >> s;
    unordered_set<char> alp;
    for (char c : s) {
        if (!alp.count(c)) {
            alp.insert(c);
        }
    }
    
    int ds = alp.size();
    int n = s.length();
    vector<i64> ans(ds + 1, 0);
    for (int k = 1; k <= ds; k++) {
        vector<i64> rec(26, 0);
        i64 cnt = 0, l = 0, r = 0;
        while (r < n) {
            if (rec[s[r] - 'a'] == 0) {
                cnt++;
            }
            rec[s[r++] - 'a']++;
            while (l < r && cnt > k) {
                if (rec[s[l] - 'a'] == 1) {
                    cnt--;
                }
                rec[s[l] - 'a']--;
                l++;
            }
            if (cnt <= k) {
                ans[k] += r - l;
            }
        }
    }
 
    std::cout << ds << '\n';
    for (int i = 1; i <= ds; i++) {
        std::cout << ans[i] - ans[i - 1] << '\n';
    }
}