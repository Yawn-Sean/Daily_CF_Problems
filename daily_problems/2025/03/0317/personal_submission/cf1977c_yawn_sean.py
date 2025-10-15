# Submission link: https://codeforces.com/contest/1977/submission/310963915
def main():
    t = II()
    outs = []

    for _ in range(t):
        n = II()
        nums = LII()
        
        v = max(nums)
        flg = False
        
        for x in nums:
            if v % x:
                flg = True
        
        if flg: outs.append(n)
        else:
            ans = 0
            
            def f(x):
                cur, cnt = 1, 0
                for v in nums:
                    if v == x: return 0
                    if x % v == 0:
                        cur = math.lcm(cur, v)
                        cnt += 1
                return cnt if cur == x else 0
            
            for i in range(2, v):
                if i * i > v: break
                elif v % i == 0:
                    ans = fmax(ans, f(i))
                    ans = fmax(ans, f(v // i))
            
            outs.append(ans)

    print('\n'.join(map(str, outs)))