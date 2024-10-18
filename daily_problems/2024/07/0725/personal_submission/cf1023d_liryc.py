'''
https://codeforces.com/contest/1023/submission/272564875
1023D
2024/7/25 Y1
1700
constructive, stack
'''

if __name__ == '__main__':
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    lastpos = [-1] * (q + 1)
    hasq = False
    for i, x in enumerate(a):
        lastpos[x] = i
        if not hasq and x == q:
            hasq = True
    
    ans = [x for x in a]
    stk = [(1, n)]
    lastpos[1] = n
    for i, x in enumerate(a):
        y = stk[-1][0]
        if x == 0:
            if not hasq:
                ans[i] = q
                hasq = True
            else:
                ans[i] = y
        elif x != y:
            if x > y:
                if lastpos[x] > i:
                    stk.append((x, lastpos[x]))
            else:
                ans = []
                break
        elif i == lastpos[y]:
            stk.pop()
    
    if ans and hasq: # WA: forgot hasq...
        print("YES")
        print(*ans)
    else:
        print("NO")



