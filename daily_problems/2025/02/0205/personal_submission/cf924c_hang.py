def main():
    n = int(input())
    arr = list(map(int, input().split()))
    ans = 0
    cnt =[0] * n
    mx = max(arr)
    idx = arr.index(mx) # 找出线条数量最多的起点
    mx += 1
    cnt[idx] = mx 
    # idx左边的线条数量尽可能小
    for i in range(idx - 1, -1, -1):
        cnt[i] = max(cnt[i + 1] - 1, arr[i]+1)
    # idx右边的线条数量不变
    for i in range(idx + 1, n):
        cnt[i] = mx
    # 保证是非递减数组
    for i in range(1, n):
        cnt[i] = max(cnt[i - 1], cnt[i])
    for i in range(n):
        if arr[i] < cnt[i]:
            ans += cnt[i] - arr[i] - 1
    print(ans)

main()