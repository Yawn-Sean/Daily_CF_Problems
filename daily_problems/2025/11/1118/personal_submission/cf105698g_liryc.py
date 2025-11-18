'''
https://codeforces.com/gym/105698/submission/349576035
'''
def init():
    n, q = map(int, input().split())
    st = SegTree(pmin, n, [-1] * n)
    return n, q, st

def solve(n: int, qa: list[int], st: SegTree) -> int: 
    if qa[0] == 1:
        l, r = qa[1] - 1, qa[2] - 1
        st.set(l, pmax(st.get(l), r))
        return -1
    else:
        i = qa[1] - 1
        p = st.min_left(i + 1, lambda x: x >= i)
        return i - p + 2
