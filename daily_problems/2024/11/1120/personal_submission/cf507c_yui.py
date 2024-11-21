from sys import stdin, stderr
input = lambda: stdin.readline().strip()

h, n = map(int, input().split(' '))

ext =  (1 << h) - 1 + n
# print(ext)

ans = 0
print(ext, file=stderr)

def f(x, d):
    global ext, ans
    if x == ext or h < d:
        return
    # go left
    if x % 2 == 1:
        if ext >= (2 * x + 1) << (h - d - 1):
            ans += (1 << (h - d))
            f(2 * x + 1, d + 1)
        else:
            ans += 1
            f(2 * x, d + 1)
    # go right
    else:
        if ext >= (2 * x + 1) << (h - d - 1):
            ans += 1
            f(2 * x + 1, d + 1)
        else:
            ans += (1 << (h - d))
            f(2 * x, d + 1)

f(1, 0)

print(ans)
