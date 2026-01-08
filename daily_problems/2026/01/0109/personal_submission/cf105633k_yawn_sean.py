# Submission link: https://codeforces.com/gym/105633/submission/356912701
def main(): 
    n, m = MII()
    vals = [-100] * (1 << m)
    idxs = [0] * (1 << m)
    
    msks = []
    
    for i in range(n):
        s = I()
        msk = 0
        for j in range(m):
            if s[j] == 'Y':
                msk |= 1 << j
        
        msks.append(msk)
        
        if vals[msk] < 0:
            vals[msk] = 0
            idxs[msk] = i
    
    if vals[-1] == 0:
        chosen = -1
        for i in range(n):
            if i != idxs[-1] and (chosen == -1 or msks[chosen].bit_count() < msks[i].bit_count()):
                chosen = i
        
        x, y = chosen, idxs[-1]
        if x > y: x, y = y, x
        print(x + 1, y + 1)
    
    else:
        for i in range(m):
            for j in range(1 << m):
                if j >> i & 1:
                    nj = j ^ (1 << i)
                    
                    if vals[j] + 1 > vals[nj] or (vals[j] + 1 == vals[nj] and idxs[j] < idxs[nj]):
                        vals[nj] = vals[j] + 1
                        idxs[nj] = idxs[j]
    
        cur = -1
        x, y = -1, -1
        for i in range(n):
            v = (1 << m) - 1 - msks[i]
            if vals[v] > cur:
                cur = vals[v]
                x, y = i, idxs[v]
        
        if cur >= 0: print(x + 1, y + 1)
        else: print('No')