#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m;
const int N = 10007;
int v[N], res[N];
int step[N];
int main()
{
    cin >> n >> m;
    int maxa = 0;
    memset(step, 0x3f, sizeof step);
    while (m -- ){
        int a, b;
        cin >> a >> b;
        v[a] ++;
        step[a] = min(step[a], (b - a + n) % n);
    }

    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= n; j ++)
        {
            if(v[j]) res[i] = max(res[i], (v[j] - 1) * n + (j - i + n) % n + step[j]);
        }
        cout << res[i] << " "; 
    }
    return 0;
}
