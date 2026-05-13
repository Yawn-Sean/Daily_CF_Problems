'''
https://codeforces.com/gym/106164/submission/374343672
'''
def solve(x: int):
    n = pmax(1, int((2 * abs(x))**0.5) - 2)
    while True:
        s = n * (n + 1) // 2
        if (s - x) % 2 == 0:
            m = (s - x) // 2
            if 0 <= m <= s - 1 and m != 1 and m != s - 2:
                break
        n += 1
        
    neg = set()
    rem = m
    for v in range(n, 1, -1):
        if rem == v:
            neg.add(v)
            rem = 0
            break
        elif rem > v and rem - v != 1:
            neg.add(v)
            rem -= v

    ans = ["1"]
    for i in range(2, n + 1):
        if i in neg:
            ans.append(f"-{i}")
        else:
            ans.append(f"+{i}")
            
    return n, ''.join(ans)
