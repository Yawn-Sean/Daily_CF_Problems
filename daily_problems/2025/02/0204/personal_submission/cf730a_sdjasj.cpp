void solve() {
    int n, r;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) {
        cin >> x;
    }
    r = *min_element(arr.begin(), arr.end());
    if (n == 2) {
        if (arr[0] != arr[1]) {
            cout << 0 << endl;
            cout << max(arr[0], arr[1]) << endl;
            for (int i = 0; i < max(arr[0], arr[1]); i++) {
                cout << "11" << endl;
            }
        } else {
            cout << arr[0] << endl;
            cout << 0 << endl;
        }
        return;
    }
    for (; r >= 0; r--) {
        priority_queue<int> heap;
        for (int i = 0; i < n; i++) {
            if (arr[i] - r > 0) heap.push(arr[i] - r);
        }
        bool flag = false;
        int cnt = 0;
        while (heap.size() > 1) {
            int a = heap.top();
            heap.pop();
            int b = heap.top();
            heap.pop();
            if (heap.size() == 1 && a == 1) {
                cnt++;
                flag = true;
                break;
            }
            a--, b--;
            if(a) heap.push(a);
            if(b) heap.push(b);
            cnt++;
        }
        if (!(flag || heap.empty())) continue;
        string ans(n, '0');
        priority_queue<PII> hp;
        for (int i = 0; i < n; i++) {
            if (arr[i] - r > 0) hp.push({arr[i] - r, i});
        }
        cout << r << endl;
        cout << cnt << endl;
        while (hp.size() > 1) {
            PII a = hp.top();
            hp.pop();
            PII b = hp.top();
            hp.pop();
            if (hp.size() == 1 && a.first == 1) {
                PII c = hp.top();
                ans[a.second] = ans[b.second] = ans[c.second] = '1';
                cout << ans << endl;
                break;
            }
            ans[a.second] = ans[b.second]= '1';
            cout << ans << endl;     
            ans[a.second] = ans[b.second]= '0';   
            a.first--, b.first--;
            if(a.first) hp.push(a);
            if(b.first) hp.push(b);
        }
        return;        
    }
    int maxv = *max_element(arr.begin(), arr.end());
    cout << 0 << endl;
    cout << maxv * (n - 1) << endl;
    vector<PII> nums(n);
    for (int i = 0; i < n; i++) {
        nums[i] = {arr[i] - r, i};
    }
    sort(nums.begin(), nums.end(), [&](auto& a, auto& b) -> bool {
        return a.first < b.first;
    }); 
    string ans(n, '0');   
    for (int i = 0; i < n - 1; i++) {
        ans[nums[i].second] = ans[nums[i + 1].second] = '1';
        for (int j = 0; j < maxv; j++) {
            cout << ans << endl;
        }
        ans[nums[i].second] = '0';        
    }
    return;
}
