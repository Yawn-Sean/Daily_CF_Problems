'''
https://codeforces.com/gym/103102/submission/378256678
prefix sum
'''
def solve(n: int, a: list[int]) -> int:    
    vp = {}
    for p in range(3):
        for r in range(3):
            va = []
            for y in range(3):
                k = ((p - y) ** 2) % 3
                v = (r - k) % 3
                va.append((y, v))
            vp[(p, r)] = va
            
    cnt = [[0] * 3 for _ in range(3)]
    cnt[0][0] = 1
    
    cp = 0
    cr = 0
    ans = 0
    for x in a:
        v = x % 3
        cp = (cp + v) % 3
        cr = (cr + (v * v)) % 3
        for p, r in vp[(cp, cr)]:
            ans += cnt[p][r]
        cnt[cp][cr] += 1
    return ans
