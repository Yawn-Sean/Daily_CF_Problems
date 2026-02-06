# Submission link: https://codeforces.com/gym/103347/submission/361651056
def main(): 
    p, x, y, a = MII()
    
    mods = [1]
    
    for _ in range(p):
        mods.append(mods[-1] * x % p)
        if mods[-1] == 1:
            mods.pop()
            break
    
    k = len(mods)
    pos = [-1] * p
    
    for i in range(k):
        pos[mods[i]] = i
    
    ans = 0
    for i in range(1, p):
        v = pow(i, p - 2, p) * y % p
        if pos[v] >= 0:
            j = pos[v]
            res = ((j - i) * p + i) % (k * p)
            ans += (a - res) // (k * p) + 1
    
    print(ans)