#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 300, mod = 1e9 + 7, inf = 1e9;
struct fenwick {
    int n;
    vector <int> info;
    fenwick(){}
    fenwick(int n): info(n+1), n(n){}
    void add(int x, int c){
        while (x <= n) info[x] += c, x += x&-x;
    }
    int query(int x){
        int sum = 0;
        while (x) sum += info[x], x -= x&-x;
        return sum;
    }
};

void solve(){
    int n;
    cin >> n;

    vector <int> ans(n), nums(n+1), order(n+1);
    iota(order.begin(), order.end(), 0);
    for (int i = 1; i <= n; ++ i) cin >> nums[i];
    sort(order.begin()+1, order.end(), [&](int x, int y){
        return nums[x] == nums[y] ? x < y : nums[x] < nums[y];
    });

    fenwick Y(n);
    for (int i = 1; i <= n; ++ i){
        int x = order[i];
        /*
          对于每个j: 考虑 j*(order-1)+2 <= n 的order
          order <= (n-2)/j + 1
          对于每个 j, 枚举 (n-2)/j + 1 的order
          sigma {n/i}|i=1,2,3,···,n-1   个 为调和级数 log(n)
         */
        for (int j = 1; j < n; ++ j){
            int l = j*(x-1) + 2, r = j*x+1;
            if (l > n) break;
            r = min(r, n);
            ans[j] += Y.query(r) - Y.query(l-1);
        }
        Y.add(x, 1);
    }

    for (int i = 1; i < n; ++ i) cout << ans[i] << "\n "[i < n-1];
}
