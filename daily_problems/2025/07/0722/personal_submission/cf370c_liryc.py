'''
https://codeforces.com/problemset/submission/370/330223712
'''
# Counter + priority queue
def solve(n: int, m: int, c: list[int]) -> list[str]:
    cn = Counter(c)
    hp = []
    ans = deque()
    ans_c = 0
    for k, v in cn.items():
        heappush(hp, (-v, k))
    while hp:
        if len(hp) == 1:
            v, k = heappop(hp)
            ans.append(f"{k} {k}")
            v += 1
            if v != 0:
                heappush(hp, (v, k))
        elif len(hp) == 3 and hp[0][0] == -1:
            ans_c += 3
            _, k1 = heappop(hp)
            _, k2 = heappop(hp)
            _, k3 = heappop(hp)
            ans.append(f"{k1} {k2}")
            ans.append(f"{k2} {k3}")
            ans.append(f"{k3} {k1}")
        else:
            ans_c += 2
            v1, k1 = heappop(hp)
            v2, k2 = heappop(hp)
            ans.append(f"{k1} {k2}")
            ans.append(f"{k2} {k1}")
            v1, v2 = v1 + 1, v2 + 1
            if v1 != 0:
                heappush(hp, (v1, k1))
            if v2 != 0:
                heappush(hp, (v2, k2))
    ans.appendleft(str(ans_c))
    return list(ans)
