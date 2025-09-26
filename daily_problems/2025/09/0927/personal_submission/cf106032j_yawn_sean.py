# Submission link: https://codeforces.com/gym/106032/submission/340354871
def main():
    t = II()
    outs = []
    
    inf = 10 ** 9
    
    for _ in range(t):
        n, m, q = MII()
        nums = LII()
        cnt = [0] * (m + 1)
        
        for x in nums:
            cnt[x] ^= 1
        
        next_odd = [inf] * (m + 1)
        
        for i in range(m + 1):
            if cnt[i]:
                next_odd[i] = 0
        
        for i in range(m, 0, -1):
            next_odd[i - 1] = fmin(next_odd[i - 1], next_odd[i] + 1)
        
        next_odd[m] = fmin(next_odd[m], next_odd[0])
        for i in range(m, 0, -1):
            next_odd[i - 1] = fmin(next_odd[i - 1], next_odd[i] + 1)
        
        cnt = 0
        for _ in range(q):
            query = LII()
            if query[0] == 1: cnt += 1
            else:
                x = nums[query[1] - 1]
                step = fmin(cnt, next_odd[x])
                outs.append((x + step - 1) % m + 1)
    
    print('\n'.join(map(str, outs)))