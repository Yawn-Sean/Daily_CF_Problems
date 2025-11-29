'''
https://codeforces.com/gym/106017/submission/351110555
'''
# lazy segment tree

n, ti = 0, 0
ta, tb = [], []
MOD = 10**9 + 7

def st_init(q: int):
    global n, ta, tb
    n = q
    tsize = 2 << n.bit_length() # n << 2
    ta, tb = [1] * tsize, [0] * tsize

def st_update(a: int, b: int, begin: int, end: int, i = 0, l = 0, r = -1):
    global n, ta, tb, MOD
    if r < 0:
        r = n - 1
    if begin <= l <= r <= end:
        ta[i], tb[i] = (ta[i] * a) % MOD, (tb[i] * a + b) % MOD
        return
    for j in range(i << 1 | 1, i + 1 << 1 | 1):
        ta[j] = (ta[j] * ta[i]) % MOD
        tb[j] = (tb[j] * ta[i] + tb[i]) % MOD
    ta[i], tb[i] = 1, 0
    m = l + r >> 1
    if begin <= m:
        st_update(a, b, begin, end, i << 1 | 1, l, m)
    if end > m:
        st_update(a, b, begin, end, i + 1 << 1, m + 1, r)

def st_query(j: int, i = 0, l = 0, r = -1) -> int:
    global n, ta, tb, MOD
    if r < 0:
        r = n - 1
    if l == r:
        return tb[i] % MOD
    m = l + r >> 1
    if j <= m:
        return (st_query(j, i << 1 | 1, l, m) * ta[i] + tb[i]) % MOD
    else:
        return (st_query(j, i + 1 << 1, m + 1, r) * ta[i] + tb[i]) % MOD
    
def query1(x: int):
    global ti
    i = ti
    ti += 1
    st_update(1, x, i, i)

def query2(x: int):
    global ti
    if ti:
        st_update(1, x, 0, ti - 1)

def query3(p: int, q: int):
    global ti
    if ti:
        a = p * pow(q, -1, MOD) % MOD
        st_update(a, 0, 0, ti - 1)

def query4(i: int) -> int:
    return st_query(i)
