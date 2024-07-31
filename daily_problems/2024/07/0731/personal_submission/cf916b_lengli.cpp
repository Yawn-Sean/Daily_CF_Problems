#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
//#include <memory.h>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <stack>
#include <string>
#include <assert.h>
#include <iomanip>
#define MINF 0x3f3f3f3f
using namespace std;
typedef long long LL;

LL n, m;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    multiset<int> st;
    for (int i = 63;i >= 0;i--)
    {
        if ((1ULL<<i) <= n)
        {
            st.insert(i);
            n -= (1LL<<i);
        }
    }
    if (st.size() > m)
        puts("No");
    else
    {
        while (st.size() < m)
        {
            if (st.size() == 1)
            {
                int t = *st.rbegin();
                st.erase(*st.rbegin());
                st.insert(t-1);
                st.insert(t-1);
            }
            else
            {
                int cnt = st.count(*st.rbegin());
                if (m-st.size() >= cnt)
                {
                    int t = *st.rbegin();
                    st.erase(t);
                    for (int i = 1;i <= cnt*2;i++)
                        st.insert(t-1);
                }
                else
                {
                    int t = *st.begin();
                    t--;
                    st.erase(st.begin());
                    while (st.size()+2 < m)
                    {
                        st.insert(t);
                        t--;
                    }
                    st.insert(t);
                    st.insert(t);
                }
            }
        }
        cout << "Yes" << endl;
        for (multiset<int>::reverse_iterator it = st.rbegin();it != st.rend();++it)
            cout << *it << ' ';
        cout << endl;
    }

    return 0;
}
