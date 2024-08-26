/*
枚举两个点，就可以确定一条直线
用这条直线先筛去一些点，然后看剩下的点是否在一条直线上
但是好像还是不太行，复杂度 O(n^3)
考虑前三个点，其中必有至少两个点在同一条直线上，我们枚举是哪两个点即可
这样只需要先用 3 条直线分别筛一下，然后看剩下的点在不在一条直线上
两条直线平行，所以求出斜率之后，只要看能算出来多少种截距即可
*/

int T;

void solve1() {
    int n;
    cin >> n;
    vector<LL> y(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> y[i];
        
    }
    
    for (int i = 2; i <= 3; i++) {
        for (int j = 1; j < i; j++) {
            LL k = (2 * (y[i] - y[j])) / (i - j);
            set<LL> bs;
            for (int p = 1; p <= n; p++) {
                bs.insert(y[p] * 2 - p * k);
            }
            if (bs.size() == 2) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}      
