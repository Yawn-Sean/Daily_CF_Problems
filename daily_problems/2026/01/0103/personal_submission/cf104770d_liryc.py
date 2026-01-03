'''
https://codeforces.com/gym/104770/submission/356230589
'''
def solve(n: int, m: int, k: int, em: list[list[int]], ek: list[list[int]]) -> list[list[int]]:
    ind = [0] * (n + 1)
    ans = []
    for u, v in chain(em, ek):
        ind[u] ^= 1
        ind[v] ^= 1
        if u != 1 != v:
            ans.append([1, u, v])
    return [[-1]] if any(d > 0 for d in ind) else ans
