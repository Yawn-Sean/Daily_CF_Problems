#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 5050, mod = 1e9 + 7;
const double inf = 1e9;
double eps = 1e-10;
/*
    最大值最小同时字典序尽可能大
*/
void solve(){
    ll n, k;
    cin >> n >> k;
    deque<int> Q;
    for (int i = 0; i < 63; ++ i){
        if (n>>i & 1){
            Q.push_front(i);
        }
    }

    // 队头大， 队尾小
    while (Q.size() < k){
        int x = -1, cnt = 0;
        int delta = k-Q.size();
        // 还差delta个 数组就满, 最大值有cnt个
        for (auto &y : Q){
            if (x==-1) x = y;
            if (x!=-1 && y!=x) break;
            ++ cnt;
        }
        // 讨论插队头还是插队尾
        if (cnt > delta){
            while (Q.size() < k){
                auto t = Q.back();
                Q.pop_back();
                Q.push_back(t-1), Q.push_back(t-1);
            }
        } else {
            auto t = Q.front();
            for (int i = 1; i <= cnt; ++ i) Q.pop_front();
            for (int i = 1; i <= cnt; ++ i) Q.push_front(t-1), Q.push_front(t-1);
        }
    }

    if (Q.size() != k){
        cout << "No\n";
    } else {
        cout << "Yes\n";
        for (auto &x : Q) cout << x << " ";
        cout << "\n";
    }
}
