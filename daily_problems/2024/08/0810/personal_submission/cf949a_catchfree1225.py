import sys
input = lambda: sys.stdin.readline().strip()

def solve():
    ans = [[] for _ in range(len(s))]
    tmp0, tmp1 = [], [] # stack: 結尾為0,1
    cnt = 0 # 以哪個0為起點
    for i, x in enumerate(s):
        if x == '0':
            if not tmp1:
                tmp0.append(cnt)
                ans[cnt].append(i + 1)
                cnt += 1
            else:
                tmp0.append(tmp1.pop()) 
                ans[tmp0[-1]].append(i + 1)
        else:
            if not tmp0:
                print(-1)
                return
            else:
                tmp1.append(tmp0.pop())
                ans[tmp1[-1]].append(i + 1)
    ans = [ai for ai in ans if ai]
    
    if not tmp1:
        print(len(ans))
        for ai in ans:
            print(len(ai), *ai)
    else:
        print(-1)
        
                    
for _ in range(1):
    s = input()
    solve()