/*
link: https://codeforces.com/problemset/problem/747/D
time: 2024_4_30
method: 零下气温天数为cnt且必须换胎，那么我们最多需要交换 cnt * 2次。但是有没有办法减少呢
        首先我们必须有cnt天的冬季轮胎，那么剩下的天数我们可以尝试在两个零下的天之间不换胎，那么
        答案减少2，还有对于结尾的我们可以选择从最后一个零下不换胎直到结束，这只能减少1
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find(vector<int>& t, int tmp, int res)
{
    for(auto& e : t)
    {
        if(tmp >= e)
        {
            res -= 2;
            tmp -= e;
        }
        else break;
    }

    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> t; // 存储两个零下之间的天数（开区间）
    int pre = -1, cnt = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] < 0)
        {
            if(pre != -1) t.push_back(i - pre - 1);
            pre = i;
            cnt++;
        }
    }

    int res = cnt * 2;
    if(k < cnt) cout << -1 << endl;
    else if(cnt == 0) cout << 0 << endl;
    else
    {
        int tmp = k - cnt; // 可以分配的天数
        int cur = res;
        sort(t.begin(), t.end());

        if(n - pre - 1 <= tmp) // 最后一段可以选择
        {
            res = min(res, find(t, tmp - (n - pre - 1), cur - 1));
        } 
        tmp = k - cnt;
        res = min(res, find(t, tmp, cur));

        cout << res << endl;
    }

    return 0;
}
