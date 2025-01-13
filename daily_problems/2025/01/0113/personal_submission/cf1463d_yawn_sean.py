# Submission link: https://codeforces.com/contest/1463/submission/300774453
def main():
    t = II()
    outs = []

    for _ in range(t):
        n = II()
        nums = LII()
        
        vis = [0] * (2 * n + 1)
        for v in nums:
            vis[v] = 1
        
        other = []
        for i in range(1, 2 * n + 1):
            if not vis[i]:
                other.append(i)
        
        l, r = 0, n
        while l <= r:
            m = (l + r) // 2
            flg = True
            for i in range(m):
                if nums[i] > other[n - m + i]:
                    flg = False
            if flg:
                l = m + 1
            else:
                r = m - 1
        
        ma = r
        
        l, r = 0, n
        while l <= r:
            m = (l + r) // 2
            flg = True
            for i in range(m, n):
                if nums[i] < other[i - m]:
                    flg = False
            if flg:
                r = m - 1
            else:
                l = m + 1
        
        mi = l
        
        outs.append(ma - mi + 1)

    print('\n'.join(map(str, outs)))