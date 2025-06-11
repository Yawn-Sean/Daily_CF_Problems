    #include <bits/stdc++.h>
    using namespace std;
    #define rep(i, a, b) for(int i = a; i < (b); ++i)
    #define all(x) begin(x), end(x)
    #define sz(x) (int)(x).size()
     
    using ull = unsigned long long;
    using ll = long long;
    using pii = pair<int, int>;
     
    const int N = 1e5 + 1;
    char cmd[N];
     
    int main()
    {
        ll n;
        int q;
        scanf("%I64d%d", &n, &q);
        while (q--) {
            ll id, L = 1LL, R = n + 1;
            scanf("%I64d", &id);
            scanf("%s", cmd);
            int len = strlen(cmd);
            stack<ll> stk;
            while (true) {
                ll root = L + (R - L) / 2LL;
                if (root == id) break;
                stk.push(root);
                if (id > root) {
                    L = root + 1LL;
                } else {
                    R = root;
                }
            }    
            for (int i = 0; i < len; i++) {
                if (cmd[i] == 'U' && !stk.empty()) {
                    ll prev = stk.top();
                    stk.pop();
                    if (prev > id) {
                        R = R + (R - L) + 1LL;
                    } else {
                        L = L - (R - L) - 1LL;
                    }
                    id = prev;
                } else if (cmd[i] == 'L' && R - L > 1) {
                    stk.push(id);
                    R = id;
                    id = L + (R - L) / 2LL;
                } else if (cmd[i] == 'R' && R - L > 1) {
                    stk.push(id);
                    L = id + 1LL;
                    id = L + (R - L) / 2LL;
                }
            }
            printf("%I64d\n", id);
        }
    }
