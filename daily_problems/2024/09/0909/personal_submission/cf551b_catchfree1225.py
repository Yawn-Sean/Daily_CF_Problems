import sys
input = lambda: sys.stdin.readline().strip()

def solve():
    # Key: 固定一邊，枚舉另一個->再整個取最大
    # 可以避免討論O(n^2)
    
    cnt = [[0] * 26 for _ in range(3)]
    for i in range(3):
        for x in s[i]:
            cnt[i][ord(x) - 97] += 1
    a, b, c = cnt
    
    hi = len(s[0])
    for ai, bi in zip(a, b):
        if not bi: continue
        hi = min(hi, ai // bi)
    
    m1 = m2 = -1
    for x in range(hi + 1):
        y = len(s[0])
        for ai, bi, ci in zip(a, b, c):
            if not ci: continue
            y = min(y, (ai - bi * x) // ci)
        if x + y > m1 + m2:
            m1, m2 = x, y

    ans = s[1] * m1 + s[2] * m2
    for i in range(26):
        a[i] -= b[i] * m1 + c[i] * m2
        ans += chr(i + 97) * a[i]
    print(ans)
    
                   
for _ in range(1):
    s = [input() for _ in range(3)]
    solve() 