#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n; vector<int> t;
    BIT(int n=0): n(n), t(n+1,0) {}
    void add(int i,int v){ for(; i<=n; i+=i&-i) t[i]+=v; }
    int sum(int i){ int s=0; for(; i>0; i-=i&-i) s+=t[i]; return s; }
    int kth(int k){
        int idx = 0, bit = 1 << (31 - __builtin_clz(n));
        for (; bit; bit >>= 1){
            int nxt = idx + bit;
            if (nxt <= n && t[nxt] <= k){
                k -= t[nxt];
                idx = nxt;
            }
        }
        return idx + 1;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    if(!(cin >> N)) return 0;
    vector<int> p(N);
    for(int i=0;i<N;i++) cin >> p[i];

    BIT bit(N);
    for(int i=1;i<=N;i++) bit.add(i,1);
    vector<int> d(N);
    for(int i=0;i<N;i++){
        d[i] = bit.sum(p[i]-1);
        bit.add(p[i], -1);
    }

    vector<long long> h(N, 0);
    long long k = N / 2;
    h[0] = k;
    if (N % 2 == 1 && N >= 2) h[1] = k;

    long long carry = 0;
    for(int i=N-1; i>=0; --i){
        long long s = d[i] + h[i] + carry;
        int base = N - i;         
        d[i] = (int)(s % base);
        carry = s / base;
    }

    BIT avail(N);
    for(int i=1;i<=N;i++) avail.add(i,1);
    vector<int> q(N);
    for(int i=0;i<N;i++){
        int val = avail.kth(d[i]);
        q[i] = val;
        avail.add(val, -1);
    }

    for(int i=0;i<N;i++){
        if(i) cout << ' ';
        cout << q[i];
    }
    cout << '\n';
    return 0;
}
