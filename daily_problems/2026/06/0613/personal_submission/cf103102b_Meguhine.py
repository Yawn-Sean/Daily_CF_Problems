if 0:
    N = 1 << 10
    sg = bytearray([2] * N)

    def dfs(x: int) -> int:
        if sg[x] != 2:
            return sg[x]
        s = list(f"{x:b}")
        n = len(s)
        pack = lambda: dfs(int(''.join(s), 2))
        for i in range(1, n):
            if s[i - 1] == '1' and s[i] == '0':
                s[i - 1], s[i] = '0', '1'
                if pack() == 0:
                    sg[x] = 1
                    return 1
                s[i - 1], s[i] = '1', '0'
        for i in range(2, n):
            if s[i - 2] == '1' and s[i - 1] == '1' and s[i] == '0':
                s[i - 2], s[i - 1], s[i] = '0', '0', '1'
                if pack() == 0:
                    sg[x] = 1
                    return 1
                s[i - 2], s[i - 1], s[i] = '1', '1', '0'
            if s[i - 2] == '1' and s[i - 1] == '0' and s[i] == '0':
                s[i - 2], s[i - 1], s[i] = '0', '1', '1'
                if pack() == 0:
                    sg[x] = 1
                    return 1
                s[i - 2], s[i - 1], s[i] = '1', '0', '0'
        for i in range(3, n):
            if s[i - 3] == '1' and s[i - 2] == '0' and s[i - 1] == '1' and s[i] == '0':
                s[i - 3], s[i - 2], s[i - 1], s[i] = '0', '1', '0', '1'
                if pack() == 0:
                    sg[x] = 1
                    return 1
                s[i - 3], s[i - 2], s[i - 1], s[i] = '1', '0', '1', '0'
        sg[x] = 0
        return 0

    from sys import stderr as err
    sg[0] = sg[1] = 0
    for x in range(N):
        dfs(x)
        s = f"{x:b}"
        cnt, c0 = 0, 0
        for c in reversed(s):
            if c == '1':
                cnt += c0
            else:
                c0 += 1
        print(f"{s} {cnt} {cnt % 3 != 0} {sg[x]}", file=err)


cnt, c0 = 0, 0
for c in reversed(input()):
    if c == '1':
        cnt += c0
    else:
        c0 += 1
print("Alice" if cnt % 3 else "Bob")


"""
显然是要用逆序对来考虑的
所以先暴力打个表
发现当逆序对数量 % 3 != 0 时, 为 Alice, 否则为 Bob
顺带一提, 我的暴力写的好 tuoshi
"""
