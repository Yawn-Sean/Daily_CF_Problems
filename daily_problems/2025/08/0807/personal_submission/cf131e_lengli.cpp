/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

struct Node{ 
    int i, j, k; 
};

void solve(){
    int n,m;
    std::cin>>n>>m;
    std::vector<Node> Q(m);
    std::vector<int> S(m),T(9);

    for(int _k=0;auto &[i,j,k]:Q){
        std::cin>>i>>j;
        k=_k++;
    }

    std::sort (Q.begin (), Q.end (), [] (auto& q1, auto& q2)
        { return q1.i < q2.i || (q1.i == q2.i && q1.j < q2.j); });

    for (int k = 0; k < m; ++k)
        S[Q[k].k] += (k && Q[k].i == Q[k - 1].i) +
            (k != m - 1 && Q[k].i == Q[k + 1].i);

    std::sort (Q.begin (), Q.end (), [] (auto& q1, auto& q2)
        { return q1.j < q2.j || (q1.j == q2.j && q1.i < q2.i); });

    for (int k = 0; k < m; ++k)
        S[Q[k].k] += (k && Q[k].j == Q[k - 1].j) +
            (k != m - 1 && Q[k].j == Q[k + 1].j);

    std::sort (Q.begin (), Q.end (), [] (auto& q1, auto& q2)
        { return q1.i - q1.j < q2.i - q2.j || (q1.i - q1.j == q2.i - q2.j && q1.i < q2.i); });

    for (int k = 0; k < m; ++k)
        S[Q[k].k] += (k && Q[k].i - Q[k].j == Q[k - 1].i - Q[k - 1].j) +
            (k != m - 1 && Q[k].i - Q[k].j == Q[k + 1].i - Q[k + 1].j);

    std::sort (Q.begin (), Q.end (), [] (auto& q1, auto& q2)
        { return q1.i + q1.j < q2.i + q2.j || (q1.i + q1.j == q2.i + q2.j && q1.i < q2.i); });

    for (int k= 0; k < m; ++k)
        S[Q[k].k] += (k && Q[k].i + Q[k].j == Q[k - 1].i + Q[k - 1].j) +
            (k != m - 1 && Q[k].i + Q[k].j == Q[k + 1].i + Q[k + 1].j);

    for (auto& s:S) ++T[s];
    for (auto& t:T) std::cout<<t<<" ";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
