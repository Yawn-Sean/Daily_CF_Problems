# Submission link: https://codeforces.com/gym/105789/submission/353783710
def main(): 
    n, p, h = MII()
    
    muls = []
    adds = []
    
    cnt = 0
    
    for _ in range(n):
        tmp = LI()
        
        if tmp[0] == '*':
            if int(tmp[1]) > 1:
                muls.append(int(tmp[1]))
        elif tmp[0] == '+':
            adds.append(int(tmp[1]))
        else:
            cnt += 1
    
    muls.sort(reverse=True)
    adds.sort(reverse=True)
    
    if cnt == 0: print('*')
    elif len(muls) == 0 and len(adds) == 0:
        if p == 0: print('*')
        else:
            h = (h - 1) // p + 1
            rounds = (h - 1) // cnt
            print(rounds * n + h - rounds * cnt)
    else:
        inf = 10 ** 9
        ans = 0
        while True:
            cur = p
            for x in adds:
                cur = fmin(cur + x, inf)
            for x in muls:
                cur = fmin(cur * x, inf)
    
            if cur * cnt < h:
                h -= cur * cnt
                ans += n
                p = cur
            else:
                res = n
                
                cur_add = p
                for i in range(len(adds) + 1):
                    if i: cur_add = fmin(cur_add + adds[i - 1], inf)
                    cur_mul = cur_add
                    
                    for j in range(len(muls) + 1):
                        if j: cur_mul = fmin(cur_mul * muls[j - 1], inf)
                        
                        for k in range(cnt + 1):
                            if cur_mul * k >= h:
                                res = fmin(res, i + j + k)
                
                ans += res
                break
        
        print(ans)