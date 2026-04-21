def f(arr):
    ans = 0
    for i in range(len(arr) - 1):
        ans += arr[i] * 10 + arr[i + 1]
    return ans

outs = []
for _ in range(int(input())):
    n = int(input())
    s = input()
    if n == 1:
        outs.append('0 0')
        continue

    a = [int(x) for x in s]
    b = sorted(a)

    cnt = 0
    cnt += a[-1] != b[-1]
    cnt += a[0] != b[-2]
    if cnt == 2 and a[0] == b[-1] and a[-1] == b[-2]:
        cnt -= 1

    b[0], b[-2] = b[-2], b[0]
    outs.append(' '.join(map(str, [cnt, f(b)])))

print('\n'.join(map(str, outs)))
