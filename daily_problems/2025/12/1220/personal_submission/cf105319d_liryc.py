'''
https://codeforces.com/gym/105319/submission/354319762
'''
def solve(n: int, a: list[int]) -> int: 
    i, ans = 0, 1
    ba = [deque() for _ in range(30)]
    for j in range(1, n):
        x = a[j] ^ a[j - 1]
        c = a[j - 1] > a[j]
        if x:
            b = x.bit_length() - 1
            ba[b].append(j << 1 | c)
            has_i_moved = False
            while ba[b] and (ba[b][0] & 1) != c:
                p = ba[b].popleft() >> 1
                i = p 
                has_i_moved = True
            if has_i_moved:
                for dq in ba:
                    while dq and (dq[0] >> 1) <= i: 
                        dq.popleft()
        ans += j - i + 1
    return ans
