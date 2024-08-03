# Submission link: https://codeforces.com/contest/1878/submission/257238177
def main():
    n, k = MII()
    s = I()
    ls = LGMI()
    rs = LGMI()
    groups = [-1] * n
    for i in range(k):
        for j in range(ls[i], rs[i] + 1):
            groups[j] = i
    
    q = II()
    pos = LGMI()
    diff = [0] * (n + 1)
    
    for x in pos:
        y = ls[groups[x]] + rs[groups[x]] - x
        if x > y: x, y = y, x
        diff[x] ^= 1
        diff[y+1] ^= 1

    for i in range(n):
        diff[i+1] ^= diff[i]
    
    return ''.join(s[i] if diff[i] == 0 else s[ls[groups[i]] + rs[groups[i]] - i] for i in range(n))