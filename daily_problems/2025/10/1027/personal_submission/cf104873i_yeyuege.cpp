#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve(){
    int n;
    cin >> n;
    if (n == 1){
        queue<int>q;
        cout << "? 1 1" << endl;
        cout.flush();
        int len;
        cin >> len;
        for (int i = 0; i < len; i++) {
            int num;
            cin >> num;
            q.push(num);
        } 
        cout << "! " << q.size() << " ";
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        return;
    }
    vector<vector<int> >nums(n);
    int cnt = 1;
    int pos = -1;
    while (cnt <= n) {
        int temp = 0;
        deque<int>dq;
        while (temp + 2 <= n && cnt <= n) {
            dq.push_back(cnt);
            dq.push_back(cnt);
            cnt++;
            temp += 2;
        }
        cout << "? " << dq.size() << " ";
        while (!dq.empty()) {
            cout << dq.front() << " ";
            dq.pop_front();
        }
        cout << endl;
        cout.flush();
        int len;
        cin >> len;
        vector<int> vis(1005, 0);
        int f = 1;
        for (int i = 0; i < len; i++) {
            int num;
            cin >> num;
            if (vis[num]) {
                vis[num]--;
                f = 1;
                continue;
            }
            if (f) {
                pos++;
            }
            f = 0;
            nums[pos].push_back(num);
            vis[num]++;
        }
    }

    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << nums[i].size() << " ";
        for (int x : nums[i]) {
            cout << x << " ";
        }
    }
}

int main(){
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
