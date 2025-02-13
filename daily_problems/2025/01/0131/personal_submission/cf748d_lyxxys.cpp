#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
using u64 = unsigned long long;
const f64 eps = 1e-12;
const i64 inf_i64 = 4e18;
const int inf_int = 2e9;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}
template <class T> void print(vector <T> &A){
    int n = A.size();
    for (int i = 0; i < n; ++ i){
        if (i) cout << " ";
        cout << A[i];
    }
    cout << "\n";
}
int jgs(f64 x){
    return x < -eps ? -1 : x > eps;
}

void solve(){
    mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution <int> rands(1e8, 1e9);
    const int Ba = rands(mt), u = 131;

    int n, k;
    cin >> k >> n;
    vector<array<int,2>> has(k);
    vector <int> A(k), idx(k);
    iota(idx.begin(), idx.end(), 0);

    for (int i = 0; i < k; ++ i){
        string s;
        cin >> s >> A[i];
        i64 cur1 = 0, cur2 = 0;
        for (int j = 0; j < n; ++ j){
            cur1 = cur1*u + (s[j]-'a'+1);
            cur1 %= Ba;
        }
        for (int j = n-1; j >= 0; -- j){
            cur2 = cur2*u + (s[j]-'a'+1);
            cur2 %= Ba;
        }

        has[i] = {(int)cur1, (int)cur2};
    }

    sort(idx.begin(), idx.end(), [&](int &u, int &v){
        return A[u] < A[v];
    });

    unordered_map <int,vector<int>> mps;
    for (int id = 0; id < k; ++ id){
        int i = idx[id];
        int code1 = has[i][0];
        mps[code1].push_back(A[i]);
    }

    int ans = 0, ma = 0;
    for (int i = 0; i < k; ++ i){
        auto &[c1, c2] = has[idx[i]];
        if (mps[c1].empty() || mps[c2].empty()) continue;
        if (c1 != c2){
            int l = min((int)mps[c1].size(), (int)mps[c2].size());
            while (l){
                int cur = mps[c1].back()+mps[c2].back();
                if (cur >= 0){
                    l -= 1;
                    mps[c1].pop_back(), mps[c2].pop_back();
                    ans += cur;
                } else {
                    // mps[c1].clear(), mps[c2].clear();
                    break;
                }
            }
        }
    }
    vector<int> alls;
    vector<vector<int>> B;
    int sum = 0;
    for (int i = 0; i < k; ++ i){
        auto &[c1, c2] = has[idx[i]];
        if (mps[c1].empty() || mps[c2].empty()) continue;
        if (c1 == c2){
            B.push_back(mps[c1]);
            int l = mps[c1].size(), tmp = 0;
            while (l > 1){
                int j1 = mps[c1][l-1], j2 = mps[c1][l-2];
                int cur = j1+j2;
                if (cur > 0){
                    tmp += cur;
                    l -= 2;
                } else {
                    break;
                }
            }
            alls.push_back(tmp);
            sum += tmp;
            mps[c1].clear();
        }
    }

    int res = 0;
    ans += sum;
    for (int i = 0; i < B.size(); ++ i){
        int l = B[i].size();
        auto &vec = B[i];
        int tmp = ans-alls[i]+vec[l-1];
        int j = l-2;
        while (j >= 1){
            int cur = vec[j]+vec[j-1];
            if (cur <= 0) break;
            tmp += cur;
            j -= 2;
        }
        fmax(res, tmp);
    }
    
    cout << max(res, ans) << "\n";
}

