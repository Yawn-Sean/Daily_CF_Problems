# -*- coding: UTF-8 -*-
import sys

global outs
input = lambda: sys.stdin.readline().rstrip()

extra = (
    (),
    (1,),
    (1, 3, 5, 2, 7, 4, 6),
    (1, 3, 5, 2, 7, 4, 6, 8),
    (2, 4, 1, 3)
)


def solve(_case: int) -> None:
    n = int(input())
    if n == 2 or n == 3:
        outs[_case] = "-1"
        return
    m, r = divmod(n, 5)
    if r == 2 or r == 3:
        m -= 1
    base = m * 5

    def gen():
        for x in range(0, base, 5):
            yield f"{x + 1} {x + 3} {x + 5} {x + 2} {x + 4}"
        yield ' '.join(map(lambda x: str(base + x), extra[r]))

    outs[_case] = ' '.join(gen())


if __name__ == "__main__":
    t = int(input())
    outs = [""] * t
    for _ in range(t):
        solve(_)
    print('\n'.join(outs))
