#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
using i64 = long long;
const int N = 2e5 + 10, inf = 0x3f3f3f3f;
int n, k, p[N];
bool used[N];
void solve(){
    cin >> n >> k;
    int cnt = 0;
    vector<int>tmp;
    stack<int>st;
    for(int i = 1; i <= k; i++){
        cin >> p[i];
        used[p[i]] = true;
        if(!st.empty() && p[i] > st.top()){
            cout << -1 << '\n';
            return;
        }
        st.push(p[i]);
        while(!st.empty() && st.top() == cnt + 1){
            cnt++;
            st.pop();
        }
    }
    st.push(cnt);
    for(int i = 1; i <= k; i++)cout << p[i] << " ";
    while(st.size() > 1){
        int end = st.top();
        st.pop();
        int stt = st.top();
        for(int j = stt - 1; j >= end + 1; j--){
            used[j] = true;
            cout << j << " ";
        }
    }
    for(int i = n; i > st.top(); i--){
        if(!used[i])cout << i << " ";
    }
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    T = 1;
    // cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
