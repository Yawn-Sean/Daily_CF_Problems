# Submission link: https://codeforces.com/contest/1073/submission/282543317
def main():
    n = II()
    s = I()
    x, y = MII()

    dirs = {
        'U': (0, 1),
        'D': (0, -1),
        'L': (-1, 0),
        'R': (1, 0)
    }

    if abs(x) + abs(y) > n or (x + y - n) % 2:
        print(-1)
    else:
        acc_x = [0] * (n + 1)
        acc_y = [0] * (n + 1)
        
        for i in range(n):
            dx, dy = dirs[s[i]]
            acc_x[i + 1] = acc_x[i] + dx
            acc_y[i + 1] = acc_y[i] + dy
        
        def check():
            return abs(acc_x[l] + acc_x[n] - acc_x[r] - x) + abs(acc_y[l] + acc_y[n] - acc_y[r] - y) > r - l
        
        l, r = 0, 0
        ans = n + 1
        while l <= n:
            while r < n and check():
                r += 1
            if check(): break
            ans = fmin(ans, r - l)
            l += 1
        
        print(ans)