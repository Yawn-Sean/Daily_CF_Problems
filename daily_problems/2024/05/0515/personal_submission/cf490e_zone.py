def main(ac=FastIO()):
    """
    url: 
        question:   https://codeforces.com/problemset/problem/490/E
        submission: https://codeforces.com/contest/490/submission/261070684
    time: 968 ms
    """
    lst = 0 
    n = ac.read_int()
    a = [list(ac.read_str()) for _ in range(n)]

    def check(mid):
        mid = str(mid).zfill(c)
        t = sr[:]
        j = 0
        for i in range(m):
            if t[i] == '?': 
                t[i] = mid[j]
                j += 1 
        return int(''.join(t)) > lst 

    def find():
        if m == c and len(str(lst)) == m: 
            fin = lst + 1 
            for i, x in enumerate(str(fin)):
                if i >= m: break 
                sr[i] = x
            return 
        
        l = int('1' + '0' * (c - 1)) if sr[0] == '?' else 0 
        r = int('9' * c)
        while l < r: 
            mid = l + r >> 1 
            if check(mid): r = mid
            else: l = mid + 1 
        l = str(l).zfill(c)
        i = 0 
        for j in range(m):
            if sr[j] == '?': 
                sr[j] = l[i]
                i += 1 

    for i, sr in enumerate(a):
        m = len(sr)
        c = sr.count('?') 
        if c: find()
        cur = int(''.join(sr))
        if cur <= lst or len(sr) != m: 
            print("NO")
            return 
        lst = cur 
        a[i] = ''.join(sr)
    print("YES")
    print('\n'.join(a))
