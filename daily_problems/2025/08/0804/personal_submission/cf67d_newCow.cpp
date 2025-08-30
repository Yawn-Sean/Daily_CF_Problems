#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
const int N = 1000010;
const ll inf = 1LL << 60;


ll n,a[N],b[N];
pii v[N];

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin >> n;
    int x,y;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        a[x] = i;
    }

    for (int i = 1;i <= n; i++) {
        cin >> y;
        b[y] = i;
    }
    
    for (int i = 1; i <= n; i++) {
        v[i].first = a[i];
        v[i].second = b[i];
    }

    sort(v + 1,v + n + 1);
    
//    for (int i = 1; i <= n; i++) {
//    	cout << v[i].first << " " << v[i].second << "\n";
//	}

    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        int p = v[i].second;

        if (vec.empty()) {
            vec.push_back(p);
            continue;
        }

        ll l = 0,r = vec.size() - 1,mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (vec[mid] < p) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if (l != vec.size() - 1) {
            vec[l] = p;
        } else {
            if (vec[l] > p) {
                vec.push_back(p);
            } else {
                vec[l] = p;
            }
        }
    }

    ll ans = vec.size();
    cout << ans << "\n";

    return 0;
}
