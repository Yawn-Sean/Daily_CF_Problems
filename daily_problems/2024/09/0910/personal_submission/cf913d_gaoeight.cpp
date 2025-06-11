struct cmp{
    bool operator()(pii i, pii j){
        return i.fi < j.fi;
    }
};
int main(void)
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	
    int n, t;
    cin >> n >> t;
    vector<pii>a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    vector<int>b(n);
    for(int i = 0; i < n; i++)b[i] = i;
    sort(b.begin(), b.end(), [&](int i, int j){
        return a[i].fi > a[j].fi;
    });
    
    auto find = [&](int i){
        int l = 0, r = n - 1;
        if(a[b[r]].fi >= i)return r;
        int mid = (l + r) / 2;
        while(r - l > 1){
            mid = (l + r) / 2;
            if(a[b[mid]].fi < i)r = mid;
            else l = mid;
        }
        return l;
    };

    priority_queue<pii, vector<pii>, cmp>pq;
    int sum = 0;
    int cur = -1;
    for(int i = n; i >= 0; i--){
        int pos = find(i);
        if(a[b[pos]].fi < i || pos + 1 < i)continue;

        //cout << i << ' ' << pos << "\n";
        if(cur < pos){
            for(int j = cur + 1; j <= pos; j++){
                pq.push({a[b[j]].se, b[j]});
                sum += a[b[j]].se;
            }
            cur = pos;
        }

        if(pq.size() < i)continue;
        while(pq.size() > i){
            sum -= (pq.top().fi);
            pq.pop();
        }

        if(sum <= t){
            cout << i << "\n" << i << "\n";
            while(pq.size()){
                cout << pq.top().se + 1<< ' ';
                pq.pop();
            }
            return 0;
        }
    }
    cout << "0\n0";
}
