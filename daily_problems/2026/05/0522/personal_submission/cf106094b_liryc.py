'''
https://codeforces.com/gym/106094/submission/375592642
greedy
'''
def solve(n: int, t: int, da: list[int]) -> tuple[int, str]:
    enc = lambda x, y: x << 18 | y
    dec = lambda z: (z >> 18, z & (1 << 18) - 1)
    st = []
    vis = [0] * n
    ts = 0
    for i, d in enumerate(da):
        st.append(enc(d // 6, i))
        st.append(enc(d // 3, i))
        ts += d >> 1
    st.sort()
    for j in range(n << 1):
        d, i = dec(st[j])
        if ts + d <= t:
            ts += d
            vis[i] += 1
        else:
            break
    sa = ['2', '1.5', '1']
    return 50 * n + 25 * sum(vis), ' '.join(sa[i] for i in vis)
