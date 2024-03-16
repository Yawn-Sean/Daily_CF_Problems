#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <utility>
#include <complex>
#include <functional>
#define ff first
#define ss second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int INF=1e9+250;
LL mod=1e9+7;
const int N=2e6+10;
using PII = pair<int, int>;
int a[1010], n;

int not_primes[N];
void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (!not_primes[i]) {
            for (int j = i + i; j <= n; j += i)
                not_primes[j] = 1; 
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1) cnt++;
    }
    if (n == 1) {
        cout << 1 << '\n' << a[1] << '\n';
        return 0;
    }
    sieve((int)2e6);
    vector<int> res1;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (!not_primes[a[i] + a[j]]) {
                res1 = {a[i], a[j]};
            }
        }
    }
    vector<int> res2;
    if (cnt) {
        for (int i = 1; i <= n; i++) {
            if (a[i] != 1 && !not_primes[a[i] + 1]){
                res2.push_back(a[i]);
                break;
            }
        }
    }

    
    if (res1.size() == 0 && res2.size() == 0) { 
        cout << 1 << '\n' << a[1] << '\n';
    } else if (res2.size() + cnt > res1.size()) {   
        cout << res2.size() + cnt << '\n';
        for (int i = 0; i < cnt; i++)
            cout << 1 << " ";
        if (!res2.empty())
            cout << res2[0] << '\n';
    } else {
        cout << 2 << '\n';
        cout << res1[0] << " " << res1[1] << '\n';
    }
    return 0;
}
