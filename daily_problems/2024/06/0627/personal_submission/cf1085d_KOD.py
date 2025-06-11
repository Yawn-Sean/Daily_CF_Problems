        n , s = il()
        c = Counter()
        for i in range(n-1):
            a, b = il()
            c[a] += 1
            c[b] += 1
        res = 0
        for a, b in c.items():
            if b == 1 : res += 1
        print(s *2 / res)
