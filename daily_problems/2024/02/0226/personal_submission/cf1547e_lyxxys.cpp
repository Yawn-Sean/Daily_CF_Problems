#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
const int INF = 2e9;

void solve(){
    int n, k;
    cin >> n >> k;
    vector <int> dis(n+1, INF), pos(k+1);
    priority_queue <Pii, vector<Pii>, greater<Pii>> heap;
    for (int i = 1; i <= k; ++ i)
        cin >> pos[i];

    for (int i  = 1; i <= k; ++ i){
        int wei;
        cin >> wei;
        heap.push({wei, pos[i]}), dis[pos[i]] = wei;
    }

    while (heap.size()){  //贪心小根堆求最低温度
        auto top = heap.top();
        heap.pop();
        int p = top.second;
        if (p-1 >= 1 && dis[p-1] > dis[p]+1)
            dis[p-1] = dis[p]+1, heap.push({dis[p-1], p-1});
        if (p+1 <= n && dis[p+1] > dis[p]+1)
            dis[p+1] = dis[p]+1, heap.push({dis[p+1], p+1});
    }

    for (int i = 1; i <= n; ++ i) cout << dis[i] << " ";
    cout << "\n";
}
