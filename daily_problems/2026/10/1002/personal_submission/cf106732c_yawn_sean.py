# Submission link: https://codeforces.com/gym/106732/submission/392782306
def main():
    n, m = MII()
    
    types = []
    score = []
    
    for _ in range(m):
        t, x = LI()
        types.append(1 if t == 'S' else 0)
        score.append(int(x))
    
    def solve():
        cnt = 0
        cur = 0
        for i in sorted(range(m), key=lambda x: score[x]):
            cnt += 1
            if types[i]: cur += score[i]
            else: cur = fmin(cur + n, fmax(cur + 1, score[i] * cnt))
        return cur / cnt
    
    mx = solve()
    
    for i in range(m):
        score[i] = n + 1 - score[i]
    
    mn = n + 1 - solve()
    
    print(f'{mn:.15f} {mx:.15f}')