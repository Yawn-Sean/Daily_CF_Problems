def soviet():
    n = int(input())
    a = list(map(int, input().split()))

    ans = dict()

    def query(x, y):
        print(f'? {x} {y}', flush = True)
        return int(list(input().split())[1])

    def f(x):
        if x in ans: return ans[x]
        if x & -x == x:
            ans[x] = query(x, x) // 2
            return ans[x]
        p = 1 << (x.bit_length())
        ans[x] = query(x, p - x) - f(p - x)
        return ans[x]
    
    for x in a:
        print(f'! {f(x)}', flush = True)
        ne = input()


soviet()
