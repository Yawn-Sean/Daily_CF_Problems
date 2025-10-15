'''
https://codeforces.com/problemset/submission/727/314451604
'''
# greedy

sa = ['S', 'M', 'L', 'XL', 'XXL', 'XXXL'] 

def solve(a: list[int], n: int, pa: list[str]) -> list[int]:
    global sa
    ssa = [f"{u},{v}" for u, v in pairwise(sa)]
    qa = [[] for _ in range(5)]
    ans = [0] * n
    for i, s in enumerate(pa):
        onlyone = False
        for j, t in enumerate(sa):
            if s == t:
                if a[j]:
                    a[j] -= 1
                    ans[i] = j
                    onlyone = True
                    break
                else:
                    return []
        if onlyone:
            continue
        for j, t in enumerate(ssa):
            if s == t:
                qa[j].append(i)
                break
    for j in range(5):
        for i in qa[j]:
            if a[j]:
                a[j] -= 1
                ans[i] = j
            elif a[j + 1]:
                a[j + 1] -= 1
                ans[i] = j + 1
            else:
                return []
    return ans
