def main():
    n = int(input())
    p = list(map(lambda x : int(x) - 1, input().split()))
    a = [0] *(n + 2)
    b = [0] *(n + 2)
    for i in range(n):
        x = p[i]
        if x >= i:
            a[1] -= 1
            a[x - i + 1] += 2
            a[n - i + 1] -= 2
            b[0] += x - i
            b[n- i] -= n - x * 2
        else:
            a[1] += 1
            a[n-i+1] -= 2
            a[n-i+x+1] += 2
            b[0] += i-x
            b[n-i] -= n - x * 2
    ans = 10 ** 18
    idx = 0
    for i in range(n):
        a[i+1] += a[i]
        b[i] += a[i]
        b[i +1] += b[i]
        if b[i] < ans:
            ans = b[i]
            idx = i
    print(ans, idx )
main()