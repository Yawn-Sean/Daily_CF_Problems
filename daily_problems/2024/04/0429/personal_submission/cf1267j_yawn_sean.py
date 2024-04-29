# Submission link: https://codeforces.com/contest/1267/submission/258627912
def main():
    t = II()
    outs = []

    for _ in range(t):
        n = II()
        cnt = [0] * n
        for x in GMI():
            cnt[x] += 1
        
        tmp = [x for x in cnt if x]
        res = n
        
        for i in range(1, min(tmp) + 1):
            cnt = 0
            for v in tmp:
                cur = (v - 1) // (i + 1) + 1
                cnt += cur
                if i * cur > v: break
            else:
                if cnt < res:
                    res = cnt
        
        outs.append(res)

    print('\n'.join(map(str, outs)))