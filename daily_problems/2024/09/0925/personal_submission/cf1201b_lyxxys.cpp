#include <bits/stdc++.h>
using namespace std;
const int N = 10010, inf = 1e9;

void solve(){
    int n;
    map <long long, long long> ct;
    cin >> n;
    vector <array<long long,2>> nums(n);
    bool jg = 0;
    for (auto &it : nums){
        cin >> it[0];
        ct[it[0]] += 1;
        if (ct[it[0]] > 1) jg = 1;
    }
    for (auto &it : nums) cin >> it[1];
    if (!jg) return cout << 0 << "\n", void();
    sort(nums.begin(), nums.end(), [&](array<long long,2> &A, array<long long,2> &B){
        return A[0] > B[0];
    });
    long long res = 0;
    vector <array<long long,2>> tmps;
    set <long long> st;
    for (auto &it : nums){
        if (ct[it[0]] > 1){
            res += it[1];
            if (!st.count(it[0])){
                st.insert(it[0]);
            }
        }
        else tmps.push_back(it);
    }


    // 当且仅当 是某一个人 的 子集 加入贡献
    int len = tmps.size();
    for (int i = 0; i < len; ++ i){
        bool jg = 0;
        long long y = tmps[i][0];
        for (auto &x : st){
            if ((x|y) == x){
                jg = 1;
                break;
            }
        }
        if (jg){
            res += tmps[i][1];
            st.insert(y);
        }
    }

    cout << res << "\n";
}
 
