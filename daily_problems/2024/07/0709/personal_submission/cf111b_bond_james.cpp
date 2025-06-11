/*
    ੴ ਸਤਿ ਨਾਮੁ ਕਰਤਾ ਪੁਰਖੁ ਨਿਰਭਉ ਨਿਰਵੈਰੁ ਅਕਾਲ ਮੂਰਤਿ ਅਜੂਨੀ ਸੈਭੰ ਗੁਰ ਪ੍ਰਸਾਦਿ
*/
#include <iostream>
#include<bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define int long long
using namespace std;
using ll=long long;
using lld = long double;
#define mod 10000000007
#define INF 1e18
#define pi 3.141592653589793238462
#define pb push_back
#define ppb pop_back
#define mp make_pair

const int N = 100005; // Define the maximum value for N

vector<int> eg[N]; // Store divisors for each number
vector<int> la(N, 0); 

void solve(){
int numQueries;
    cin >> numQueries;

    for(int i = 1; i <= numQueries; ++i) {
        int x, y;
        cin >> x >> y;

        int result = 0;
        for(int divisor : eg[x]) {
            // Check if this divisor should be counted
            if (la[divisor] == 0 || la[divisor] < i - y) {
                result++;
            }
            la[divisor] = i; // Update last occurrence of this divisor
        }

        cout << result << "\n";
    }
}

int32_t main()
{
    for(int i = 1; i < N; ++i) {
        for(int j = i; j < N; j += i) {
            eg[j].push_back(i);
        }
    }
    int tc=1;
    // cin>>tc;
    while(tc--)
    {
    solve();
    }
    return 0;
}