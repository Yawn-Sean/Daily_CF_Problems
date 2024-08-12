#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 500, mod = 1e9 + 7, inf = 1e9;
struct bloks {
    int p1 = -1, p2 = -1;
};
int L[N], R[N];

void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> nums(n+1), bin(n+1);
    for (int i = 1; i <= n; ++ i) cin >> nums[i];
    int len = sqrt(n);
    vector <bloks> blo(len+2);
    for (int i = 1; i <= len; ++ i){
        L[i] = (i-1)*len + 1, R[i] = i*len;
    }
    if (R[len] < n) ++ len, L[len] = R[len-1]+1, R[len] = n;
    for (int i = 1; i <= len; ++ i){
        for (int j = L[i]; j <= R[i]; ++ j){
            bin[j] = i;
            if (blo[i].p1 == -1) blo[i].p1 = j;
            else if (blo[i].p2 == -1 && nums[blo[i].p1] != nums[j]){
                blo[i].p2 = j;
            }
        }
    }

    auto query = [&](int l, int r, int x)->int{
        int p = bin[l], q = bin[r];
        if (q-p <= 1){
            for (int i = l; i <= r; ++ i)
                if (nums[i] != x) return i;
            return -1;
        }
        for (int i = p+1; i <= q-1; ++ i){
            int p1 = blo[i].p1, p2 = blo[i].p2;
            if (p1 != -1 && nums[p1] != x) return p1;
            if (p2 != -1 && nums[p2] != x) return p2;
        }
        for (int i = l; i <= R[p]; ++ i){
            if (nums[i] != x) return i;
        }
        for (int i = L[q]; i <= r; ++ i){
            if (nums[i] != x) return i;
        }
        return -1;
    };

    while (m--){
        int l, r, x;
        cin >> l >> r >> x;
        cout << query(l, r, x) << "\n";
    }
}
