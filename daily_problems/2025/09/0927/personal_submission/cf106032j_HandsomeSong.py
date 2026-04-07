import bisect

def MII():
    return map(int, input().split())
def LII():
    return list(map(int, input().split()))
def II():
    return int(input())

t = II()
for _ in range(t):
    n, m, q = MII()
    a = LII()
    cnt = [0] * (m + 1)
    for x in a:
        cnt[x] += 1
    
    odd = []
    for x in range(1, m + 1):
        if cnt[x] > 0 and cnt[x] % 2 == 1:
            odd.append(x)
            
    ops = 0 
    for _ in range(q):
        qu = LII()
        if qu[0] == 1:
            ops += 1
        else:
            idx = qu[1] - 1
            val = a[idx]
            if cnt[val] % 2 == 1:
                print(val)
                continue
            i = bisect.bisect_left(odd, val)
            target = -1
            d = float('inf')
            if i < len(odd):
                target = odd[i]
                d = target - val
            elif odd:
                target = odd[0]
                d = (m - val) + target
                
            if ops >= d:
                print(target)
            else:
                print((val + ops - 1) % m + 1)
