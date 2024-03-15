import collections
import random
import sys
input = lambda: sys.stdin.readline().strip()


def main():
    n = int(input())
    points = [list(map(int, input().split())) for _ in range(n)]

    rnd = random.randint(1, 10**9)
    seen = collections.Counter()
    for i in range(n):
        x1, y1 = points[i]
        for j in range(i+1, n):
            x2, y2 = points[j]
            # seen[(x1 + x2, y1 + y2)] += 1
            seen[(x1 + x2) * rnd + y1 + y2] += 1
    print(sum([v * (v-1) // 2 for v in seen.values()]))


main()
