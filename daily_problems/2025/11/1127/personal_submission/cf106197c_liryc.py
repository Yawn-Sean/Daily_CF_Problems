'''
https://codeforces.com/gym/106197/submission/350804847
'''
def solve(n: int) -> list[int]: 
    idx_of_1 = 1
    for i in range(2, n + 1):
        if query(idx_of_1, i) != idx_of_1:
            idx_of_1 = i
    d1 = [i for i in range(1, n + 1) if i != idx_of_1]
    ans = []
    while d1:
        d2 = []
        p = d1[0]
        for i in range(1, len(d1)):
            r = query(p, d1[i])
            if r == idx_of_1: 
                d2.append(d1[i])
            elif r == d1[i]: 
                p = d1[i]
        d1 = d2
        ans.append(p)
    return ans
