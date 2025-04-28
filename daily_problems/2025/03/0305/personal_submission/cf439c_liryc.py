'''
https://codeforces.com/problemset/submission/439/309015556
'''
# just count the number of odds, then if if if if ....
def solve(n: int, k: int, p: int, a: list[int]) -> list[list[int]]:
    r = k - p
    nodd = sum(x & 1 for x in a)
    neven = n - nodd
    if nodd >= r and not (nodd - r & 1) and (nodd - r >> 1) + neven >= p:
        aodd, aeven, aevenodd = [], [], []
        for x in a:
            if x & 1:
                if p and len(aodd) == r:
                    if p == len(aeven): 
                        aeven[0].append(x)
                    elif aevenodd and len(aevenodd[-1]) & 1:
                        aevenodd[-1].append(x)
                    elif len(aevenodd) + len(aeven) == p:
                        aevenodd[0].append(x)
                    else:
                        aevenodd.append([x])
                else:
                    if len(aodd) == r:
                        aodd[0].append(x)
                    else:
                        aodd.append([x])
            else:
                if p == 0: 
                    if aodd:
                        aodd[0].append(x)
                    else:
                        aodd.append([x])
                elif len(aevenodd) == p:
                    aevenodd[0].append(x)
                elif len(aeven) + len(aevenodd) == p:
                    aeven[0].append(x)
                else:
                    aeven.append([x])
        return aeven + aodd + aevenodd
    else:
        return []
