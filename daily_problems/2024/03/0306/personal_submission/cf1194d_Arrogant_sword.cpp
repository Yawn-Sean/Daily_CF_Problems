    // 如果去掉k的话，就是经典的博弈问题。结论是n是三的倍数先手必败，否则先手必胜。
    // 因为0是必败态，1，2是必胜态，3是必败态 …… .
    // 加上k后，若k不是3的倍数则结果不变。因为此时3的倍数只能转化为非3的倍数，所以也是必败态。
    // 考虑k为3的倍数，此时k+1可以到达1、k、k-1都是必胜态，所以k+1是必败态。于是k+2,k+3,k+1+k是必胜态 …….
    // 结论就是如果(n % (k+1) ) % 3 == 0即n = k+1 + m*3(m为正整数) && (n % (k+1)) % k != 0为必败态。

    #include<bits/stdc++.h>
    #define int long long 
    #define all(a) a.begin(), a.end()
    #define endl '\n'
    #define pb push_back
    using namespace std;
    void print(vector<int> vi)
    {
        for (auto t : vi) cout << t << ' ';
        cout << endl;
    }
    //////////////////////////////////////////////////

    void solve() 
    {
        int n, k;
        cin >> n >> k;

        if (k % 3) {
            if (n % 3) cout << "Alice" << endl;
            else cout << "Bob" << endl;
        } else {
            int x = n % (k+1);
            if (x % 3 == 0 && x != k ) cout << "Bob" << endl;
            else cout << "Alice" << endl;
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