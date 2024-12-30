import sys
input = lambda: sys.stdin.readline().strip()

def solve():   
    # 此題坑點: 注意是一起平移(分開交換是NP-Hard?)
    # 副對角線組合: x+y=n-k, x-y=2n-k
    # 主對角線組合: x-y=-k, x-y=n-k
    # 都可化簡為(x+y)%n, (x-y)%n 
    shift_sum = [0] * n
    for i in range(n):
        for j in range(n):
            shift_sum[(i - j) % n] += int(a[i][j])
    tot = sum(shift_sum)
    ans = min((tot - s) + (n - s) for s in shift_sum)
    print(ans)
               
for _ in range(int(input())):
    input() # 這個也很坑=.=
    n = int(input())
    a = [input() for _ in range(n)]
    solve()