if 1:
    import sys  
    #sys.stdout.flush()   print('.....', flush = True)
    import random #random.shuffle()
    from itertools import *
    from heapq import *
    from bisect import bisect_left, bisect_right
    from collections import Counter, deque, defaultdict
    input = lambda: sys.stdin.readline().strip()
    import math
    inf = math.inf
    rdm = random.getrandbits(30)
    #sys.set_int_max_str_digits(6000)
    def I():
        return input()
    def II():
        return int(input())
    def MII():
        return map(int, input().split())
    def LI():
        return list(input())
    def LII():
        return list(map(int, input().split()))
    def LFI():
        return list(map(float, input().split()))
    def LSI():
        return list(map(str, input().split()))
    mod = int(1e9 + 7) 
n = II()
a = LII()
a.sort()
a = a[::-1]
b = list(map(str, a))

if a[-1] != 0:
    print("-1")
else:
    if sum(a) % 3 == 0:
        if len(b) == 0:
            print(-1)
        elif b[0] == '0':
            print(0)
        else:
            print(''.join(b))
    else:
        cnt = Counter()
        for i in a:
            if cnt[i % 3]:
                cnt[i % 3].append(i)
            else:
                cnt[i % 3] = []
                cnt[i % 3].append(i)

        need = sum(a) % 3
        if cnt[need]:
            tar = min(cnt[need])
            for i in range(n - 1, -1, -1):
                if a[i] == tar:
                    a.pop(i)
                    break
            b = list(map(str, a))
            if len(b) == 0:
                print(-1)
            elif b[0] == '0':
                print(0)
            else:
                print(''.join(b))
        elif len(cnt[((need - 1) ^ 1) + 1]) >= 2:
            cnt[((need - 1) ^ 1) + 1].sort()
            s = [cnt[((need - 1) ^ 1) + 1][-1]] + [cnt[((need - 1) ^ 1) + 1][-2]]
            s.sort()
            s = s[::-1]
            
            for i in range(n - 1, -1, -1):
                if a[i] in s:
                    a.pop(i)
                    s.pop()
            b = list(map(str, a))

            if len(b) == 0:
                print(-1)
            elif b[0] == '0':
                print(0)
            else:
                print(''.join(b))
        else:
            print(-1)

