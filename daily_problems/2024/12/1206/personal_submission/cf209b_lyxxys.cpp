#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector <int> A(n), deg(k);
    for (auto &x : A){
        cin >> x;
        x -= 1;
    }

    {
        int i = 0;
        while (i < n){
            int v1 = i-1 < 0 ? -1 : A[i-1];
            while (i+1 < n && A[i+1]==A[i]) i += 1;
            int v2 = i+1 >= n ? n : A[i+1];
            deg[A[i]] += v1==v2 ? 2 : 1;
            i += 1;
        }
    }
    vector <int> idx(k);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int &u, int &v){
        return deg[u]==deg[v] ? u < v : deg[u] > deg[v];
    });

    cout << idx[0]+1 << "\n";
}
