import sys

input = lambda: sys.stdin.readline().strip()

n = int(input())
k = int(input())

l = 1
r = int(1e18)

def check(ans, op):
    cnt = 0
    
    st = ans
    ed = ans + n - 1
    
    bit_cnt = 0
    val = st
    
    while val > 0:
        val //= 10
        bit_cnt += 1
    
    val = 1
    for i in range(bit_cnt):
        val *= 10
    
    val -= 1
    if val <= ed:
        cnt += (val - st + 1) * bit_cnt
        val += 1
        bit_cnt += 1
        while True:
            if val * 10 - 1 <= ed:
                cnt += (val * 10 - val) * bit_cnt
                val *= 10
                bit_cnt += 1
            else:
                cnt += (ed - val + 1) * bit_cnt
                break
    else:
        cnt += (ed - st + 1) * bit_cnt
    
    if op == 0:
        return cnt == k
    return cnt >= k


while l + 1 < r:
    mid = (l + r) // 2
    if check(mid, 1):
        r = mid
    else:
        l = mid


if check(l, 0):
    print(l)
elif check(r, 0):
    print(r)
else:
    print(-1)
