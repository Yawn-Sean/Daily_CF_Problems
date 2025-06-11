input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    ans = 0
    p = list(map(int, input().split()))
    for x in p:
        ans ^= x

    xor_sum = [0] * (n+1)
    for i in range(1, n+1):
        xor_sum[i] = xor_sum[i-1] ^ i
    # 分别讨论行和列的 周期性
    for i in range(1, n+1):
        if (n-i)%2: ans ^= i

    for i in range(1, n+1):
        x, y = (n-i+1) // i, (n-i+1) % i
        if x%2:
            ans ^= xor_sum[i-1]
        if y > 0:
            ans ^= xor_sum[y-1]

    print(ans)
