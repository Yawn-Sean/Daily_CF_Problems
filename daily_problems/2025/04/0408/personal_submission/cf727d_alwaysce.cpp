#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    vector<int> cnt(6);
    int n;
    for (int i = 0; i < 6; i++) {
        cin >> cnt[i];
    }
    cin >> n;
    
    map<string, int> mp;
    mp["S"] = 0;
    mp["M"] = 1;
    mp["L"] = 2;
    mp["XL"] = 3;
    mp["XXL"] = 4;
    mp["XXXL"] = 5;

    // 01, 12, 23, 34, 45
    // 0,1,2,3,4
    vector<int> res(n, -1);
    bool flag = true;
    vector<vector<int>> comb(5);

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.find(',') != string::npos) {
            string s1 = s.substr(0, s.find(','));
            string s2 = s.substr(s.find(',') + 1);
            comb[mp[s1]].push_back(i);
        } else {
            cnt[mp[s]]--;
            res[i] = mp[s];
            if (cnt[mp[s]] < 0) {
                flag = false;
            }
        }
    }

    if (!flag) {
        cout << "NO" << endl;
        return 0;
    }


    int l = 0, r = 5;
    // 可以match的comb类型是什么
    map<int, vector<int>> match;
    match[0] = {0};
    match[1] = {0, 1};
    match[2] = {1, 2};
    match[3] = {3, 2};
    match[4] = {4, 3};
    match[5] = {4};

    while (l < r) {
        /*
            贪心的用l和r先去尽可能多的match
         */
        for (int c : match[l]) {    
            while (cnt[l] > 0 && comb[c].size() > 0) {
                int id = comb[c].back();
                comb[c].pop_back();
                cnt[l]--;
                res[id] = l;
            }
        }

        for (int c : match[r]) {
            while (cnt[r] > 0 && comb[c].size() > 0) {
                int id = comb[c].back();
                comb[c].pop_back();
                cnt[r]--;
                res[id] = r;
            }
        }
        ++l;
        --r;
    }

    for (int i = 0; i < n; i++) {
        if (res[i] == -1) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    map<int, string> mp_rev;
    mp_rev[0] = "S";
    mp_rev[1] = "M";
    mp_rev[2] = "L";
    mp_rev[3] = "XL";
    mp_rev[4] = "XXL";
    mp_rev[5] = "XXXL";
    for (int i = 0; i < n; i++) {
        cout << mp_rev[res[i]] << endl;
    }
    
    return 0;
}
