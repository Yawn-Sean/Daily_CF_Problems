#include<bits/stdc++.h>

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>


#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}


//////////////////////////////////////////////////

int gcd(int a, int b)  // 欧几里得算法
{
    return b ? gcd(b, a % b) : a;
}


void solve() 
{
    int r, b, k;
    cin >> r >> b >> k;
    
    if (r == b) {
        cout << "OBEY" << endl;
        return;
    }
    
    if (r > b) swap(r, b);
    
    int x = gcd(r, b);
    
    
    
    if (x + (k-1)*r < b) {
        cout << "REBEL" << endl;
    } else {
        cout << "OBEY" << endl;
    }
} 


signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    cin >> T;
    while (T --) {
        solve();
    }
    
}
