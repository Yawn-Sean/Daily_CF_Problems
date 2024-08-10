# https://codeforces.com/contest/792/submission/272047825
n, q = RII()
mx_lv = n.bit_length()
for _ in range(q):
    x = RI()
    lv = (x & -x).bit_length()  # 当前在第几层，从下到上依次是1，2，3...
    for c in RS():
        # x的左孩子= x - first,右=x + first
        diff = 2 ** lv  # 第lv层，相邻元素差值
        first = 2 ** (lv - 1)  # 第lv层，第一个元素
        idx = (x - first) // diff # x是第lv层的第几个元素,用来判断是左还是右孩子
        if c == 'U':
            if lv == mx_lv:
                continue
            if idx & 1 == 0:
                # 左孩子
                x += first
            else:
                x -= first
            lv += 1
        elif c == 'L':
            if lv == 1:
                continue
            x -= first // 2
            lv -= 1
        elif c == 'R':
            if lv == 1:
                continue
            x += first // 2
            lv -= 1
    print(x)
