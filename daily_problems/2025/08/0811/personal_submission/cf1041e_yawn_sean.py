# Submission link: https://codeforces.com/contest/1041/submission/333223611
def main():
    n = II()
    cnt = [0] * (n + 1)
    max_flg = [0] * (n + 1)
    
    for _ in range(n - 1):
        u, v = MII()
        if v != n: exit(print('NO'))
        cnt[u] += 1
        max_flg[u] = 1
    
    chain = []
    cur = 1
    
    for i in range(1, n):
        if cnt[i]:
            cnt[i] -= 1
            
            chain.append(i)
            while cnt[i]:
                while max_flg[cur]:
                    cur += 1
                if cur > i:
                    exit(print('NO'))
                chain.append(cur)
                cur += 1
                cnt[i] -= 1
            
    chain.append(n)
    
    print('YES')
    print('\n'.join(f'{chain[i - 1]} {chain[i]}' for i in range(1, n)))