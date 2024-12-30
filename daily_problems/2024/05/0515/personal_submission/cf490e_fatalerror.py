import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

plus1 = lambda x: chr((ord(x) - 47) % 10 + 48)

def redo(num, indices):
    for j in reversed(indices):
        num[j] = plus1(num[j])
        if num[j] != '0':
            return True
    return False

def solve():
    n = ii()
    ans = ['0']
    nd = 1
    for _ in range(n):
        num = list(input())
        if len(num) < nd:
            print('NO')
            return
        elif len(num) == nd:
            eq = True
            indices = []
            for i in range(nd):
                x, y = ans[-1][i], num[i]
                if x == y:
                    continue
                if y == '?':
                    num[i] = x if eq else '0'
                    indices.append(i)
                else:
                    if eq:
                        if y < x:
                            if not redo(num, indices):
                                print('NO')
                                return
                        eq = False
            if eq:
                if not redo(num, indices):
                    print('NO')
                    return
        else:
            nd = len(num)
            if num[0] == '?':
                num[0] = '1'
            for i in range(1, nd):
                if num[i] == '?':
                    num[i] = '0'
        ans.append(''.join(num))

    print('YES')
    print(*ans[1:], sep='\n')

solve()