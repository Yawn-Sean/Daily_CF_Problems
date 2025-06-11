def main(ac=FastIO()):
    """
    question: https://codeforces.com/problemset/problem/893/D
    submission: https://codeforces.com/contest/893/submission/265135622
    """
    n, m = ac.read_list_ints()
    a = ac.read_list_ints()
    l, r = 0, 0 # 初始时存款为0，可能取的区间为[0, 0]
    tot = 0
    for x in a: 
        if x == 0: 
            l = max(l, 0)   # 查询完之后，存款不可能为负数
            if r < 0: 
                r = m 
                tot += 1 
        else:
            l, r = l + x, min(m, r + x)
            if l > r: 
                ac.st(-1)
                return
    ac.st(tot)
