#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;
i64 inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ifstream input("input.txt");
    ofstream output("output.txt");
    string s, t;
    input >> s >> t;

    int n = s.size();
    vector<int> cnt_s(26), cnt_t(26);
    for (int i = 0; i < n; ++i) {
        cnt_s[s[i] - 'A']++;
        cnt_t[t[i] - 'A']++;
    }

    vector<int> smore(26), tmore(26);
    int tot = 0;
    for (int i = 0; i < 26; ++i) {
        int v = abs(cnt_s[i] - cnt_t[i]);
        if (cnt_s[i] > cnt_t[i]) {
            smore[i] = v;
        } else {
            tmore[i] = v;
        }
        tot += v;
    }

    string ans = s;
    for (int i = 0; i < n; i++) {
        int cur = s[i] - 'A';
        --cnt_s[cur];
        if (smore[cur] > 0) {
            for (int j = 0; j < 26; j++) {
                if (j >= cur && cnt_s[cur] >= smore[cur]) {
                    break;
                }

                if (tmore[j] > 0) {
                    --smore[cur];
                    --tmore[j];
                    ans[i] = 'A' + j;
                    break;
                }
            }
        }
    }
    output << tot / 2 << '\n';
    output << ans;
    return 0;
}
