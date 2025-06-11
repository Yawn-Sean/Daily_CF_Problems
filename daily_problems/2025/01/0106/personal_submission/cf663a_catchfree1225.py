import sys
input = lambda: sys.stdin.readline().strip()

# WA: 6次, 用時:1.5hr, 日期:20250106
def solve(): 
    m, M = 1, n
    ops = [x for x in s if x == '+' or x == '-']
    for x in ops:
        if x == '+':
            m += 1
            M += n
        else:
            m -= n
            M -= 1
    
    if not m <= n <= M:
        print('Impossible') 
        return
    
    print('Possible')
    ops = ['+'] + ops
    adds, subs = ops.count('+'), ops.count('-') 
    tot = n + subs
    pos_per = (tot + adds - 1) // adds # 平均貪心給上高斯，一定能分完
    
    ans = []
    for x in ops:
        if x == '-':
            ans += ['-', 1]
        else:
            y = max(min(pos_per, tot), 1) # 避免為0
            tot -= y
            ans += ['+', y]
    ans += ['=', n]
    
    tot = -tot
    for i, x in enumerate(ans):
        if x == '-':
            if tot == 0:
                break
            y = min(tot, n - ans[i + 1])
            ans[i + 1] += y
            tot -= y
    
    ans = [str(x) for x in ans[1:]]
    print(' '.join(ans))
               
for _ in range(1): 
    s = input().split()
    n = int(s[-1])
    solve()