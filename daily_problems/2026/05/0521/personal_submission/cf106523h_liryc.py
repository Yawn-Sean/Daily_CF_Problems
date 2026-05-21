'''
https://codeforces.com/gym/106523/submission/375412623
prime factors
'''

cn = Counter()
xs = set()

def query1(x: int):
    if x <= 1:
        return
    global cn, xs
    for p, c in prime_elements(x):
        cn[p] += c
        if p < LIMIT:
            if cn[p] == c:
                xs.add(p)
            if p in xs and cn[p] > 20:
                xs.discard(p)

def query2(x: int):
    if x <= 1:
        return
    global cn, xs
    for y in list(xs):
        cn[y] *= x
        if cn[y] > 20:
            cn[y] = 21
            xs.discard(y)

def query3(x: int) -> bool:
    if x <= 1:
        return True
    for p, c in prime_elements(x):
        if cn[p] < c:
            return False
    return True
