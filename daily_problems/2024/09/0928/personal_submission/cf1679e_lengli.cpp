#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int maxn = 2005, mod = 998244353;
char a[maxn], b[maxn];
int f[20][1 << 17];
int n, q;

LL qpow(LL a, LL b, LL mod)
{
    LL res = 1;
    while (b)
    {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void init(){
    int k = 0;
    b[k++] = '$', b[k++] = '#';
    for(int i = 0; i < n; i++) b[k++] = a[i], b[k++] = '#';
    b[k++] = '^';
    n = k;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> a;
    int cnt = 0;
    for(int i = 0; i < n; i++) cnt += (a[i] == '?');
    for(int i = 1; i <= 17; i++)
        f[i][0] = 1LL * n * qpow(i, cnt, mod) % mod;
    init();
    for(int i = 2; i < n; i++){
        int state = 0;
        int len = 1, c = 0;
        while(1){
            if (i - len <= 1 || i + len >= n - 1) break;
            if (b[i - len] == b[i + len] && b[i - len] != '?'){
                if (b[i - len] != '#')
                    for(int t = 1; t <= 17; t++)
                        f[t][state] = (f[t][state] + qpow(t, cnt - c, mod)) % mod;
                len++;
            }
            else if (b[i - len] == b[i + len]){
                len++, c++;                
                for(int t = 1; t <= 17; t++)
                    f[t][state] = (f[t][state] + qpow(t, cnt - c, mod)) % mod;
            }
            else if (b[i - len] == '?'){
                state |= (1 << (b[i + len] - 'a'));
                len++, c++;
                for(int t = 1; t <= 17; t++)
                    f[t][state] = (f[t][state] + qpow(t, cnt - c, mod)) % mod;
                
            }
            else if (b[i + len] == '?'){
                state |= (1 << (b[i - len] - 'a'));
                len++, c++;
                for(int t = 1; t <= 17; t++)
                    f[t][state] = (f[t][state] + qpow(t, cnt - c, mod)) % mod;
            }
            else break;
        }
    }
    for(int t = 1; t <= 17; t++){
        for(int i = 0; i < 17; i++)
            for(int j = 0; j < 1 << 17; j++)
                if (j >> i & 1)
                    f[t][j] = (f[t][j] + f[t][j ^ (1 << i)]) % mod;
    }

    cin >> q;
    char op[30];
    while(q--){
        cin >> op;
        int len = strlen(op);
        int state = 0;
        for(int i = 0; op[i]; i++) state |= (1 << (op[i] - 'a'));
        cout << f[len][state] << '\n';
    }

}
