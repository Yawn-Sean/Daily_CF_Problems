#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; long long L; cin >> n >> L; ++L;
    bitset<16> b;
    while(n--){ int x; cin >> x; if(0<=x && x<16) b.set(x); }

    vector<int> mults; mults.reserve(14);
    for(int i=2;i<16;++i) if(b.test(i)) mults.push_back(i+1);

    unordered_set<long long> vis; vis.reserve(1<<12);
    vector<long long> st = {1};
    vis.insert(1);

    while(!st.empty()){
        long long cur = st.back(); st.pop_back();
        for(int m: mults){
            long long nxt = cur * 1LL * m;
            if(nxt <= L && !vis.count(nxt)){
                vis.insert(nxt);
                st.push_back(nxt);
            }
        }
    }
    cout << (long long)vis.size() - 1 << '\n';
}
