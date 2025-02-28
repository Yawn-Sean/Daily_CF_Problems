'''
https://codeforces.com/problemset/submission/1082/305469177
'''
# build diameter first, then insert all nodes with degree=1
def solve(n: int, a: list[int]) -> list[str]:
    a1 = [i for i in range(n) if a[i] == 1]
    ax = [i for i in range(n) if a[i] != 1]
    if not ax:
        return ["NO"]
    max_path = len(ax) + min(len(a1), 2) - 1
    ans = [f"YES {max_path}", str(n - 1)]
    for i, j in pairwise(ax):
        ans.append(f"{i + 1} {j + 1}")
        a[i] -= 1
        a[j] -= 1
    for idx, i in enumerate(a1):
        if idx == 0:
            j = ax[0]
            ans.append(f"{i + 1} {j + 1}")
            a[i] -= 1
            a[j] -= 1
        else:
            while ax and a[ax[-1]] == 0:
                ax.pop()
            if not ax:
                return ["NO"]
            j = ax[-1]
            ans.append(f"{i + 1} {j + 1}")
            a[i] -= 1
            a[j] -= 1       
    return ans