# Submission link: https://codeforces.com/gym/104146/submission/399671363
def main(): 
    n, k = MII()
    cards = [[int(c) for c in I()] for _ in range(n)]
    
    ans = []
    chosen = []
    
    cnts = []
    for card in cards:
        c = 0
        for x in card:
            if x % 4 == 2:
                c += 1
        cnts.append(c)
    
    st_range = sorted(range(n), key=lambda x: -cnts[x])
    
    tmp = []
    idxs = []
    for i in st_range[:k]:
        idxs.append(i)
        for x in cards[i]:
            if x % 4 == 2:
                tmp.append(x)
    
    if len(tmp) > len(ans):
        ans = tmp
        chosen = idxs
    
    cnts = []
    for card in cards:
        c = 0
        for x in card:
            if x % 2 == 1:
                c += 1
        cnts.append(c)
    
    st_range = sorted(range(n), key=lambda x: -cnts[x])
    for i in range(k, n):
        idx = st_range[i]
        if cnts[idx] == cnts[st_range[k - 1]]:
            flg = False
            for x in cards[idx]:
                if x % 4 == 0:
                    st_range[k - 1], st_range[i] = st_range[i], st_range[k - 1]
                    flg = True
                    break
            
            if flg: break
    
    tmp = []
    idxs = []
    w = -1
    
    for i in st_range[:k]:
        idxs.append(i)
        for x in cards[i]:
            if x % 2 == 1:
                tmp.append(x)
            elif x % 4 == 0:
                w = x
    
    if w != -1 and tmp:
        tmp.append(w)
    
    if len(tmp) > len(ans):
        ans = tmp
        chosen = idxs
    
    if ans:
        print(' '.join(str(x + 1) for x in chosen))
        print(''.join(map(str, ans)))
    else:
        print(' '.join(map(str, range(1, k + 1))))
        print('empty')