/*
9 1989
0 1990
1 1991
8 1998
10 个数

99 1999
00 2000
01 2001
02 2002
08 2008
09 2009
10 2010
11 2011
98 2098
1000 个数

099 2099
100 2100
101 2101
998 2998
999 2999
000 3000
001 3001
098 3098
1000 个数

3099 3099
3100 3100
9999 9999
0000 10000
3098 13098
10000 个数

13099 13099
99999 99999
00000 100000
13098 113098
100000 个数

最短表示长度为 len 的数有 10^len 个，并且是连续出现的
每段的第一个数可以预处理出来，从而知道咋分段
*/

int n;
string s;

void meibao() {
    cin >> n;
    while (n--) {
        cin >> s;
        string t = s.substr(4);
        int len = t.size();
        LL st = 1989;
        LL base = 10;
        for (int i = 1; i < len; i++) {
            st += base;
            base *= 10;
        }
        // cout << st << "\n";
        auto less = [&] () -> bool {
            LL val = st;
            vector<int> nums;
            while (val > 0 && nums.size() < len) {
                nums.push_back(val % 10);
                val /= 10;
            }
            reverse(nums.begin(), nums.end());
            bool is_less = false;
            for (int i = 0; i < nums.size(); i++) {
                int d = t[i] - '0';
                if (nums[i] < d) {
                    is_less = false;
                    break;
                } else if (nums[i] > d) {
                    is_less = true;
                    break;
                }
            }
            return is_less;
        };
        
        // less 说明应该在 0 之后，否则在 0 之前
        if (less()) {
            st += base;
        } 
        vector<int> nums;
        while (st > 0) {
            nums.push_back(st % 10);
            st /= 10;
        }
        reverse(nums.begin(), nums.end());
        for (int i = 0; i + len < nums.size(); i++) {
            cout << nums[i];
        }
        cout << t << "\n";

    }
}   
