# -*- coding: UTF-8 -*-
import sys

global outs
input = lambda: sys.stdin.readline().rstrip()


def solve(_case: int) -> None:
    X, Y = map(int, input().split())

    if X == Y:
        outs[_case] = "0"
        return

    ans = 0
    if X < Y:
        # X -> [X+1,2X]
        while X < Y:
            X <<= 1
            ans += 1
        outs[_case] = str(ans)
    else:
        # X -> p
        # X-p < 2p-X
        # 3p > 2X
        if Y <= 2:
            outs[_case] = "-1"
        else:
            while X > Y:
                X = X * 2 // 3 + 1
                ans += 1
            outs[_case] = str(ans)


if __name__ == "__main__":
    total_cases = int(input())
    outs = [""] * total_cases
    for _ in range(total_cases):
        solve(_)
    print("\n".join(outs))
