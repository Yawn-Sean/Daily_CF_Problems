/*
	有一个长为 n 数列 a，值已确定且值互不相等，但是你不知道。
	现在有个设备，你可以输入长为 k 的上升序列 p1,p2 …pk，进行询问，它会回答 
	a_p1, a_p2 … a_pk 中第 m 小的数在原数列的坐标和这个数的值。
	现在给你 n 和 k让你在最多询问n 次后回答 m 的大小。保证一定可以构造出方案。
*/
#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    map <int, int> mp;
    cin >> n >> k;
    int p = 0;
    for (int i = 1; i <= k+1; ++ i){
        cout << "? ";
        for (int j = 1; j <= k+1; ++ j)
            if (j != i) cout << j << " ";
        cout.flush();
        int x, y;
        cin >> x >> y;
        ++ mp[y];
        p = max(p, y);
    }
    cout << "! " << mp[p];
}   
 /*
	我们可以对前 k+1 个元素询问  k+1 次, 每次询问 扣掉 的数字 不同
	设第 m 小的数字是 x， 第m+1 小的数字 是 y
	如果扣掉 的数字大于 u， 对结果没有影响.
	如果扣掉 的数字小于等于 u, 那么询问的值的结果一定是 y，而且这件事发生的频率是 m
	记录 频率和y 即可得到m
*/
