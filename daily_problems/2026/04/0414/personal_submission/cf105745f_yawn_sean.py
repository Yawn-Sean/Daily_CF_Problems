# Submission link: https://codeforces.com/gym/105745/submission/370923634
def main(): 
    def possible_positions(s):
        tmp = '*'.join(s)
        manacher = [0] * (2 * n - 1)
        idx = 0
        
        for i in range(1, 2 * n - 1):
            if idx + manacher[idx] >= i:
                manacher[i] = fmin(idx + manacher[idx] - i, manacher[2 * idx - i])
            while i - manacher[i] - 1 >= 0 and i + manacher[i] + 1 < 2 * n - 1 and tmp[i - manacher[i] - 1] == tmp[i + manacher[i] + 1]:
                manacher[i] += 1
            if i + manacher[i] > idx + manacher[idx]:
                idx = i
        
        ans = [0] * (n + 1)
        ans[0] = 1
        to_fill = 0
        
        for i in range(1, 2 * n - 1, 2):
            if i > to_fill and i - manacher[i] <= to_fill:
                ans[(2 * i - to_fill) // 2 + 1] = 1
                to_fill = 2 * i - to_fill + 2
        
        return ans
    
    s = I()
    n = len(s)
    
    pre = possible_positions(s)
    suf = possible_positions(s[::-1])
    suf.reverse()
    
    ans = 0
    cur = 0
    
    for i in range(n):
        cur += pre[i]
        ans += cur * suf[i + 1]
    
    print(ans)