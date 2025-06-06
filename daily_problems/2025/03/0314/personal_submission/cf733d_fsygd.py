if __name__ == '__main__':
    n = int(input())
    d = {}
    ans, solution = 0, [0]
    for i in range(1, n + 1):
        lens = sorted(list(map(int, input().split(' '))))
        if lens[0] > ans:
            ans, solution = lens[0], [i]
        for j in range(3):
            other = tuple(lens[_] for _ in range(3) if _ != j)
            if other in d and min(d[other][0] + lens[j], other[0]) > ans:
                ans, solution = min(d[other][0] + lens[j], other[0]), [d[other][1], i]
        for j in range(3):
            other = tuple(lens[_] for _ in range(3) if _ != j)
            if other not in d or lens[j] > d[other][0]:
                d[other] = (lens[j], i)
    print(len(solution))
    print(" ".join(map(str, solution)))