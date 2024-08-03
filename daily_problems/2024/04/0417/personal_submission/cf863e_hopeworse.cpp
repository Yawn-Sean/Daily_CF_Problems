void solve() {
    map<int, int> mp;
    int n;
    cin >> n;
    vector<PII> arr(n + 1);
    set<int> st;
    st.insert(-1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].first >> arr[i].second;
        st.insert(arr[i].first);
        st.insert(arr[i].first+1);
        st.insert(arr[i].second);
        st.insert(arr[i].second+1);
    }
//    sort(arr.begin() + 1, arr.end(), [](PII a, PII b) {
//        return (a.second - a.first) < (b.second - b.first);
//    });
    debug(arr);
    vector<int> vec(st.begin(), st.end());
    for (int i = 0; i < vec.size(); i++) {
        mp[vec[i]] = i;
    }
    SegmentTree tree(vec.size());
    for (int i = 1; i <= n; i++) {
        tree.modify(mp[arr[i].first], mp[arr[i].second], 1);
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        int mins = tree.query(mp[arr[i].first], mp[arr[i].second]);
        debug(mins);
        if (mins > 1) {
            ans = i;
            break;

        }
    }
    cout << ans << endl;
}
