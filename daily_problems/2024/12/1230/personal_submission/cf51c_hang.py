def main():
    n = int(input())
    x = list(map(int, input().split()))
    x.sort()
    def div_2(x):
        if x % 2 == 0:
            return f'{x // 2}.00000'
        else:
            return f'{x // 2}.50000'
    if n <= 2:
        print(div_2(0))
        print(div_2(x[0] * 2), div_2(x[-1] * 2), div_2(x[-1] * 2))
        return
    l,r = 0, n - 1
    cur = x[r - 1] - x[l + 1]
    idx = l + 1
    while l < r:
        if x[l+1] - x[0] < x[-1] - x[r - 1]:
            l += 1
        else:
            r -= 1
        v = max(x[l] - x[0], x[-1] - x[r], x[r - 1] - x[l + 1])
        if v < cur: 
            cur = v
            idx = l + 1
    
    print(div_2(cur))
    print(div_2(x[0] * 2 + cur), div_2(x[idx] * 2 + cur), div_2(x[-1] * 2 - cur))
main()