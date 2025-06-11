def solve(testcase):
    n, m = MI()
    nums = LII()
    mp = defaultdict(list)

    for i, v in enumerate(nums):
        mp[v % m].append(i)

    st = SortedList()
    t = n // m
    for i in range(m):
        if len(mp[i]) < t:
            for _ in range(t - len(mp[i])):
                st.add(i)
    
    res = 0
    for i in range(m):
        if len(mp[i]) > t:
            for o in range(len(mp[i]) - t):
                where = st.bisect_left(i)
                if where == len(st):
                    need = (st.pop(0) - i) % m
                    nums[mp[i][o]] += need
                else:
                    need = (st.pop(where) - i) % m
                    nums[mp[i][o]] += need
                res += need
    
    print(res)
    print(*nums)
    

for testcase in range(1):
    solve(testcase)
