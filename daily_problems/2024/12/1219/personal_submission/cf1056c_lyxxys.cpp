#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> A(2*n);
    for (auto &x : A) cin >> x;

    set <array<int,2>> st;
    unordered_map <int,int> mps;
    for (int i = 0; i < m; ++ i){
        int a, b;
        cin >> a >> b;
        a -= 1, b -= 1;
        if (a > b) swap(a, b);
        st.insert({a,b});
        mps[a] = b, mps[b] = a;
    }

    int opt;
    cin >> opt;
    for (int i = 0; i < n; ++ i){
        if (opt == 1){
            if (st.size()){
                auto it = *st.begin();
                st.erase(it);
                if (A[it[0]] < A[it[1]]) swap(it[0], it[1]);
                cout << it[0]+1 << "\n" << flush;
                int pos;
                cin >> pos;
                pos -= 1;
                assert(pos == it[1]);
                A[it[0]] = A[it[1]] = -1;
            } else {
                int chose = -1;
                for (int i = 0; i < 2*n; ++ i){
                    if (chose == -1 || A[i] > A[chose]){
                        chose = i;
                    }
                }
                cout << chose+1 << "\n" << flush;
                A[chose] = -1;
                int pos;
                cin >> pos;
                pos -= 1;
                assert(A[pos] != -1);
                A[pos] = -1;
            }
        } else {
            int pos;
            cin >> pos;
            pos -= 1;
            assert(A[pos] != -1);
            A[pos] = -1;

            bool jg = 1;
            if (mps.count(pos)){  // jg 判断没有强制选择
                int j = mps[pos];
                if (A[j] != -1){
                    cout << j+1 << "\n" << flush;
                    jg = 0;
                    A[j] = -1;
                    int a = pos, b = j;
                    if (a > b) swap(a, b);
                    assert(st.find({a,b}) != st.end());
                    st.erase({a, b});
                }
            }
            if (jg){
                if (st.size()){
                    auto it = *st.begin();
                    st.erase(it);
                    if (A[it[0]] < A[it[1]]) swap(it[0], it[1]);
                    cout << it[0]+1 << "\n" << flush;
                    A[it[0]] = -1;
                } else {
                    int chose = -1;
                    for (int i = 0; i < 2*n; ++ i){
                        if (chose == -1 || A[i] > A[chose]){
                            chose = i;
                        }
                    }
                    cout << chose+1 << "\n" << flush;
                    A[chose] = -1;
                }
            }
        }
    }
}
