# Submission link: https://codeforces.com/contest/291/submission/312505256
def main():
    n = II()
    path = [[] for _ in range(n)]
    strs = [''] * n

    for i in range(1, n):
        p, strs[i] = LI()
        p = int(p) - 1
        path[p].append(i)

    s = I()
    k = len(s)

    pw = random.randint(130, 200)
    mod = random.getrandbits(52)

    hash_s = 0
    for c in s:
        hash_s = (hash_s * pw + ord(c)) % mod

    pws = pow(pw, k, mod)

    stk = [0]
    hsh = [0]

    ans = 0
    while stk:
        u = stk.pop()
        if u >= 0:
            stk.append(~u)
            
            for c in strs[u]:
                hsh.append((hsh[-1] * pw + ord(c)) % mod)
                if k < len(hsh) and (hsh[-1] - hsh[-k-1] * pws) % mod == hash_s:
                    ans += 1
            
            for v in path[u]:
                stk.append(v)
        else:
            u = ~u
            
            for _ in range(len(strs[u])):
                hsh.pop()

    print(ans)