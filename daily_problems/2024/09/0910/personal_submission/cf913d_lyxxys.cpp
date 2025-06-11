#include <bits/stdc++.h>
using namespace std;
struct Node {
    int a, t, id;
    bool operator > (const Node &A) const{
        return a > A.a;
    }
};

void solve(){
    int n, T;
    cin >> n >> T;
    vector <Node> p(n);
    for (int i = 0; i < n; ++ i){
        auto &it = p[i];
        cin >> it.a >> it.t;
        it.id = i;
    }
    vector <int> ps(n);
    iota(ps.begin(), ps.end(), 0);
    sort(ps.begin(), ps.end(), [&](int x, int y){
        return p[x].t < p[y].t;
    });
    priority_queue <Node, vector<Node>, greater<Node>> pq;
    int sum = 0;
    for (int i = 0; i < n; ++ i){
        auto &it = p[ps[i]];
        if (sum+it.t > T) break;
        if (sum+it.t <= T && it.a > pq.size() && (pq.empty() || pq.top().a > pq.size())){
            pq.push(it);
            sum += it.t;
        } else if (!pq.empty()){
            // 反悔操作
            if (pq.top().a == pq.size() && it.a > pq.top().a && sum+it.t-pq.top().t <= T){
                sum += it.t-pq.top().t;
                pq.pop();
                pq.push(it);
            }
        }
    }

    cout << pq.size() << "\n" << pq.size() << "\n";
    while (!pq.empty()){
        auto it = pq.top();
        pq.pop();
        cout << it.id+1 << " ";
    }
    cout << "\n";
}
