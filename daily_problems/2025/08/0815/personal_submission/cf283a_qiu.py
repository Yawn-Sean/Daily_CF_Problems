def solve():
    import sys
    input = sys.stdin.readline

    n = int(input())
    ans = 0
    ve = [0]
    tag = [0] * (n + 10)

    for _ in range(n):
        op_line = input().split()
        op = int(op_line[0])

        if op == 1:
            a = int(op_line[1])
            x = int(op_line[2])
            tag[a] += x
            ans += a * x
        elif op == 2:
            x = int(op_line[1])
            ve.append(x)
            ans += x
        else:
            tag[len(ve) - 1] += tag[len(ve)]
            ans -= tag[len(ve)] + ve[-1]
            tag[len(ve)] = 0
            ve.pop()

        print(f"{ans / len(ve):.6f}")


if __name__ == "__main__":
    solve()

