#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1050, mod = 1e9+7, inf = 1e9;
//长度相同，编号小的一定是最左边的
struct cmps{
    bool operator()(array<int,2> a, array<int,2> b){
        return a[1]==b[1] ? a[0] > b[0] : a[1] < b[1];
    }
};
void solve(){
    int n;
    cin >> n;
    vector <int> A(n+2);
    for (int i = 1; i <= n; ++ i){
        cin >> A[i];
    }
    priority_queue<array<int,2>, vector<array<int,2>>, cmps> pq;
    /*
       分别给块进行编号，用链表维护，并存入优先队列中
       优先队列维护是哪一个块，以及块的长度
    */
    vector <array<int,3>> blo(1);
    // 链表维护 块长，左边块的标号，右边块的编号
    vector <int> value(1,-1);

    for (int i = 1, lst = 0; i <= n; ++ i){
        while (A[i] == A[i+1]) ++ i;
        int sz = blo.size();
        pq.push({sz, i-lst});
        value.push_back({A[i]});
        blo.push_back({i-lst, sz-1, sz+1});
        lst = i;
    }

    value.push_back(-1);
    int res = 0, up = blo.size();
    vector <int> dele(up);

    while (!pq.empty()){
        auto t = pq.top();
        pq.pop();
        auto u = blo[t[0]];
        if (dele[t[0]]) continue;
        if (u[0] != t[1]){
            continue;
        }
        ++ res;
        int Lnode = u[1], Rnode = u[2];
        if (Lnode > 0 && Rnode < up && value[Lnode] == value[Rnode]){
            dele[Rnode] = true;
            int r = blo[Rnode][2];
            blo[Lnode][2] = r;
            if (r < up) blo[r][1] = Lnode;
            blo[Lnode][0] += blo[Rnode][0];
            pq.push({Lnode, blo[Lnode][0]});
        } else {
            if (Lnode > 0) blo[Lnode][2] = Rnode;
            if (Rnode < up) blo[Rnode][1] = Lnode;
        }
    }

    cout << res << "\n";
}
