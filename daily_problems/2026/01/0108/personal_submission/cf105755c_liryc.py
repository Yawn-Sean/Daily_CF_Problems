'''
https://codeforces.com/gym/105755/submission/356835472
'''
# BFS
def solve(n: int, a: list[int]) -> int: 
    vis = [0] * (1 << 22)
    for x in a:
        b = x.bit_length()
        y = (1 << b) - 1
        vis[y ^ x] |= 1 << b - 1
    
    for i in range(22):
        b = 1 << i
        for m in range(1 << 22):
            if m & b:
                vis[m ^ b] |= vis[m]
    
    dq = deque()
    dq.append(0)
    s = 0
    while dq:
        enc = dq.popleft()
        m, s = enc >> 5, enc & 31
        x = vis[m]
        while x:
            lb = x & -x
            dq.append((m | lb) << 5 | s + 1)
            x &= x - 1
    return s
    