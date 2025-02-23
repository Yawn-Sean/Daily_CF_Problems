# Submission link: https://codeforces.com/contest/1223/submission/298608401
def main():
    t = II()
    outs = []

    for _ in range(t):
        n = II()
        nums = [x // 100 for x in MII()]
        x, a = MII()
        y, b = MII()
        k = II()
        
        if x > y:
            x, y = y, x
            a, b = b, a
        
        nums.sort(reverse=True)
        
        l, r = 1, n
        while l <= r:
            m = (l + r) // 2
            ca, cb, cab = 0, 0, 0
            for i in range(1, m + 1):
                if i % a == 0:
                    if i % b == 0: cab += 1
                    else: ca += 1
                elif i % b == 0:
                    cb += 1
            
            cur = 0
            for i in range(ca + cb + cab):
                if cab:
                    cab -= 1
                    cur += (x + y) * nums[i]
                elif cb:
                    cb -= 1
                    cur += y * nums[i]
                else:
                    cur += x * nums[i]
            
            if cur >= k: r = m - 1
            else: l = m + 1
        
        outs.append(l if l <= n else -1)

    print('\n'.join(map(str, outs)))