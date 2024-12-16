def main():
    k = int(input())
    ans = []
    def f(x):
        c = 0
        for i in range(1,x + 1):
            if i * (i + 1) // 2 <= x: c += 1
            else: break
        ans.append(c + 1)
        return c * (c + 1) // 2
    while k:
        k -= f(k)

    if ans:
        print(''.join(chr(ord('a') + i) * ans[i] for i in range(len(ans))))
    else:
        print('a') 

main()