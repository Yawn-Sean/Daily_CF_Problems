#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<string> st;
        vector<string> sn(n);
        vector<int> w00, w01, w10, w11;
        for (int i = 0; i < n; i++) {
            cin >> sn[i];
            st.insert(sn[i]);
            if (sn[i][0] == '0' && sn[i].back() == '0') {
                w00.push_back(i);
            } else if (sn[i][0] == '0' && sn[i].back() == '1') {
                w01.push_back(i);
            } else if (sn[i][0] == '1' && sn[i].back() == '0') {
                w10.push_back(i);
            } else {
                w11.push_back(i);
            }
        }
        
        if (w01.size() == 0 && w10.size() == 0) {
            if (w00.size() != 0 && w11.size() != 0) {
                cout << -1 << endl;
            } else {
                cout << 0 << endl;
            }
        } else {
            // 01-10 match
            // 01 / 10 剩下1个
            int diff = w01.size() - w10.size();
            vector<int> ans;
            while (diff > 1) {
                int i = w01.back();
                w01.pop_back();

                string rs = sn[i];
                reverse(rs.begin(), rs.end());
                if (st.find(rs) == st.end()) {
                    ans.push_back(i);
                    diff -= 2;
                }
            }

            while (diff < -1) {
                int i = w10.back();
                w10.pop_back();

                string rs = sn[i];
                reverse(rs.begin(), rs.end());
                if (st.find(rs) == st.end()) {
                    ans.push_back(i);
                    diff += 2;
                }
            }

            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i] + 1 << ' ';
            }
            cout << endl;
            
        }
    }
    return 0;
}
