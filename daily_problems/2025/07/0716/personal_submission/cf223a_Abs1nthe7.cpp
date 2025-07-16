#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define u64 unsigned long long
#define debug(x) cout<<x<<endl;
#define endl "\n"
//1.找的是字串
//先考虑用stack找出所有的合法组
//然后去遍历所有的合法组即可
void sol()
{
    string s;
    cin >> s;
    int n = s.size();
    stack<int> st;
    vector<int> match(n, 0);
    for (int i = 0; i < n; ++i) 
    {
        if (s[i] == '(' || s[i] == '[') 
        {
            st.push(i);
        } 
        else 
        {
            if (!st.empty()) 
            {
                int top = st.top();
                if ((s[top] == '(' && s[i] == ')') || (s[top] == '[' && s[i] == ']')) 
                {
                    match[top] = 1;
                    match[i] =1;
                    st.pop();
                } 
                else 
                {
                    while (!st.empty()) 
                    {
                        st.pop();
                    }
                }
            }
        }
    }
    // for(int i=0;i<n;++i)cout<<match[i]<<' ';
    // cout<<endl;
    int ans = 0, start = -1, curr = 0, sq = 0, ans_sq = 0, temp_start = 0;
 
    for (int j = 0; j < n; ++j) {
        if (match[j]) {
            if (curr == 0) temp_start = j;
            curr++;
            if (s[j] == '[') sq++;
            if ((sq > ans_sq) || (sq == ans_sq && curr > ans)) {
                ans = curr;
                ans_sq = sq;
                start = temp_start;
            }
        } else {
            curr = 0;
            sq = 0;
        }
    }
    cout << ans_sq << endl;
    if (start != -1) {
        for (int j = start; j < start + ans; ++j) {
            cout << s[j];
        }
        cout << endl;
    }
    return;
}
signed main()
{
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    //cin>>_;
    while(_--)sol();
    return 0;
}
