def main():
    def check(x):
        for a, b in pairs[1:]:
            if a % x != 0 and b % x != 0:
                return False
        return True

    n = int(input())
    pairs = [list(map(int, input().split())) for _ in range(n)]
    for i in range(2):
        v = pairs[0][i]
        x = 2
        while x ** 2 <= v:
            if v % x == 0:
                while v % x == 0:
                    v //= x
                if check(x):
                    return x
            x += 1
        if v > 1 and check(v):
            return v
    return -1


print(main())
