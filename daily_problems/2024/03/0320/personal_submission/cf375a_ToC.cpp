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
const int N=1e6+10;
char s[N];
int cnt[10];
using PII = pair<int, int>;
int t;

void sol()
{
    cin >> s + 1;
    int n = strlen(s + 1);


    for (int i = 1; s[i] != '\0'; i++) {
        int t = s[i] - '0';
        cnt[t]++;   
    }

    cnt[1]--, cnt[6]--, cnt[8]--, cnt[9]--;
    
    
    int idx = 1, remainder = 0;
    for (int i = 1; i <= n - cnt[0] - 4; i++) {
        while (idx < 10 && cnt[idx] == 0)
            idx++;
        if (idx == 10) break;
        else cnt[idx]--;
        s[i] = idx + '0'; 
        remainder = (((remainder * 10 % 7) % 7 ) + (idx % 7)) % 7;
    }
    int lack = 7 - (remainder * 10000 % 7) % 7;
    if (lack == 7) lack = 0;
    vector<int> nums {1, 6, 8, 9};
    do {
        int t = 0;
        for (int i = 0; i < 4; i++) {
            t = t * 10 + nums[i];
        }
        if (t % 7 == lack) break;
    } while (next_permutation(nums.begin(), nums.end()));
    int start = n - cnt[0] - 4 + 1;
    for (int i = 0; i < 4; i++) 
        s[start + i] = nums[i] + '0';
    
    for (int i = n; i > n - cnt[0]; i--)
        s[i] = '0';
    cout << s + 1 << '\n';
}

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    t = 1;
    
    while (t--) sol();


    return 0;
}
