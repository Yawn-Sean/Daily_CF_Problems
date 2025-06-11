# Submission link: https://codeforces.com/contest/1257/submission/303589769
def main():
    t = II()
    outs = []

    for _ in range(t):
        n = II()
        nums = LII()

        v = [0] * (n + 1)
        m = II()
        for _ in range(m):
            p, s = MII()
            v[s] = fmax(v[s], p)
        
        for i in range(n - 1, 0, -1):
            v[i] = fmax(v[i], v[i + 1])
        
        start = 0
        cur = 0
        
        ans = 1
        for i in range(n):
            if v[1] < nums[i]:
                outs.append(-1)
                break
            
            cur = fmax(cur, nums[i])
            if v[i - start + 1] < cur:
                start = i
                cur = nums[i]
                ans += 1
        else:
            outs.append(ans)

    print('\n'.join(map(str, outs)))