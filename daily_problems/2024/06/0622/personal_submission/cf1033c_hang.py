from functools import cache
def main():
    n = int(input())
    a = list(map(int, input().split()))
    
    @cache
    def f(i):
        j = i
        res = 0
        while j < n: 
            if a[j] > a[i] and f(j) == 0:
                res = 1
            j += a[i]
        j = i
        while j > -1:
            if a[j] > a[i] and f(j) == 0:
                res = 1
            j -= a[i]
        return res
    ans = []
    for i in range(n):
        ans.append('A' if f(i) else 'B')
    print(''.join(ans))

main()