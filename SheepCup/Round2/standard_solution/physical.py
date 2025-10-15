 
def main():
    def search1(x):
        for v in nums:
            if 0 <= v - x <= l and v - x in vis:
                return 0
        return 1
     
    def search2(x, y):
        d = x + y
        for v in nums:
            if v - d >= 0 and v - d in vis:
                return 1
         
        if x > y: x, y = y, x
        d = y - x
         
        for v in nums:
            if v - d >= 0 and v - d in vis and (v - y >= 0 or v + x <= l):
                return 1
        return 2
 
    def search3(idx, cnt, tmp):
        nonlocal ans
        if idx == 3:
            ans = fmin(ans, cnt)
            return
         
        for cur in tmp:
            for i in range(3):
                if used[i] == 0:
                    used[i] = 1
                    if cur + lst[i] <= l:
                        tmp.append(cur + lst[i])
                        search3(idx + 1, cnt + (cur + lst[i] not in vis), tmp)
                        tmp.pop()
                    if cur - lst[i] >= 0:
                        tmp.append(cur - lst[i])
                        search3(idx + 1, cnt + (cur - lst[i] not in vis), tmp)
                        tmp.pop()
                    used[i] = 0
 
    t = II()
    outs = []
 
    for _ in range(t):
        n, a, b, c, l = MII()
        nums = LII()
        ans = 3
        vis = set(nums)
         
        lst = [a, b, c]
         
        used = [0] * 3
        for v in nums:
            search3(0, 0, [v])
         
        ans = fmin(ans, search1(a) + search1(b) + search1(c))
        ans = fmin(ans, search1(a) + search2(b, c))
        ans = fmin(ans, search1(b) + search2(a, c))
        ans = fmin(ans, search1(c) + search2(a, b))
         
        outs.append(ans)
 
    print('\n'.join(map(str, outs)))