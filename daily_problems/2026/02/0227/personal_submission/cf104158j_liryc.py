'''
https://codeforces.com/gym/104158/submission/364617866
'''
# priority queue
def solve(n: int, m: int, k: int, a: list[int], qa: list[list[int]]) -> list[int]: 
    a.sort()
    da = [0] * k 
    hp = []
    ans = []
    for l, r, x in qa:
        l, r = l - 2, r - 1
        if l >= 0:
            da[l] += x
            if da[l] > 0:
                heappush(hp, ~(da[l] << 18 | l))
        da[r] -= x
        if da[r] > 0:
            heappush(hp, ~(da[r] << 18 | r))
        maxheight = -1
        while hp:
            c = ~hp[0]
            h, i = c >> 18, c & (1 << 18) - 1
            if h == da[i]:
                maxheight = h
                break
            else:
                heappop(hp)
        ans.append(n - bisect_left(a, maxheight))
    return ans
