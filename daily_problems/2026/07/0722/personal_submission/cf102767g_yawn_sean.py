# Submission link: https://codeforces.com/gym/102767/submission/383695757
def main():
    t = II()
    outs = []

    for _ in range(t):
        n = II()
        nums = LII()
        
        if n == 1:
            outs.append(0)
            continue
        
        ans = n + 1
        
        vis = [-2] * n
        
        cur = 1
        vis[1] = -1
        tmp = [1]
        
        for i in range(n):
            if math.gcd(n, nums[i]) > 1:
                for x in tmp:
                    vis[x] = -2
                cur = 1
                vis[1] = i
                tmp = [1]
            else:
                cur = cur * nums[i] % n
                if vis[cur] != -2: ans = fmin(ans, i - vis[cur])
                else: tmp.append(cur)
                vis[cur] = i
        
        outs.append(ans if ans <= n else 0)

    print('\n'.join(map(str, outs)))