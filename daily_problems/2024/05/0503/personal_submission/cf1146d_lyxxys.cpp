using namespace std;
using ll = long long;
const int N = 300050, p = 998244353, INF = 2e9;
bitset <N> vit;
ll m, a, b;

int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}

void solve(){
    cin >> m >> a >> b;
    ll res = 0;
    priority_queue <array<ll, 2>, vector<array<ll,2>>, greater<array<ll,2>>> heap;
    ll n = min(a+b, m);
    heap.push({0, 0});
    vector <ll> low(N, INF);  //low[i]表示在i这个位置时前a-b有多少个到不了的数

    while (heap.size()){
        auto top = heap.top();
        heap.pop();
        ll x = top[0], cnt = top[1];
        low[x] = min(low[x], cnt);
        if (vit[x]) continue;
        vit[x] = true;
        if (x+a <= n) heap.push({x+a, max(x+a, low[x])});
        if (x-b >= 0) heap.push({x-b, low[x]});
    }

    for (int i = 0; i <= n; ++ i)
        if (vit[i]) res += (m-low[i]+1);  //计算每一个数对答案的贡献
    for (int i = 0; i <= n; ++ i)
        if (vit[i]) cout <<  "i: " << i << " low[i]: " << low[i] << "\n";
    cout << "\n";
    if (m > a+b){
        ll d = gcd(a, b);  //f[i] = i/gcd(a,b)+1
        ll st = (n/d+1)*d, ed = (m/d)*d;  //将剩下的贡献分块计算，因为 f[i] = 1的贡献已经计算过了，不用管，st走到下一块，ed在最后一块
        ll k = (ed-st)/d + 1;
        ll l = m-st+1, r = m-ed+1;
        cout << l << " " << r << "\n";
        res += k*(l+r)/2;  //它们的贡献是公差为1的等差数列
    }

    cout << res << "\n";
}
 
