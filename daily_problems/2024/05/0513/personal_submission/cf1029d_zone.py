def main(ac=FastIO()):
    """
    url:      https://codeforces.com/contest/1029/submission/260811659
    run time: 406 ms
    """
    for _ in range(1):
        n, k = ac.read_list_ints()
        temp = [pow(10, i, k) for i in range(1, 11)]
        a    = ac.read_list_ints()
        b    = [x % k for x in a]
        cnt  = defaultdict(Counter)
        for x, y in zip(a, b):
            cnt[len(str(x)) - 1][y] += 1
        ans  = 0
        for x in b: 
            for i, y in enumerate(temp): 
                t = (x * y) % k 
                if t == 0: 
                    ans += cnt[i][0]
                else:
                    ans += cnt[i][k - t]
        for x in a: 
            if (x * pow(10, len(str(x))) + x) % k == 0: ans -= 1 
        print(ans)
