class Solution:
    """
    problem   : https://codeforces.com/problemset/problem/1073/C
    submission: https://codeforces.com/contest/1073/submission/282577034
    """
    @staticmethod
    def main(ac=FastIO()):
        n = ac.read_int()
        s = ac.read_str()
        x, y = ac.read_list_ints()
        
        if abs(x) + abs(y) > n or (x + y - n) % 2: 
            ac.st(-1)
            return 
        dirs = {
            'U': (0, 1),
            'D': (0, -1), 
            'L': (-1, 0), 
            'R': (1, 0)
        }
        acc_x, acc_y = [0] * (n + 1), [0] * (n + 1)  
        for i, op in enumerate(s): 
            dx, dy = dirs[op] 
            acc_x[i + 1] = acc_x[i] + dx 
            acc_y[i + 1] = acc_y[i] + dy
        
        def ok(l, r):
            return abs(acc_x[l] + acc_x[-1] - acc_x[r] - x) + abs(acc_y[l] + acc_y[-1] - acc_y[r] - y) <= r - l
        
        ans = n
        l = r = 0 
        while l <= n: 
            while r < n and not ok(l, r): 
                r += 1 
            if not ok(l, r): break
            ans = ac.min(ans, r - l)
            l += 1 
        ac.st(ans)
