import sys
input = lambda: sys.stdin.readline().rstrip()


def soviet():
    n = int(input())
    acc = [0] + list(map(int, input().split()))
    for i in range(n):
        acc[i + 1] += acc[i]
    
    ans = 0
    stk = [n + 1]
    stk_acc = [0]
    
    for i in range(n, -1, -1):
        while (stk[-1] != n + 1 and acc[i] >= acc[stk[-1]]):
            stk_acc.pop();
            stk.pop()

        stk_acc.append(stk_acc[-1] + (stk[-1] - i) * acc[i])
        stk.append(i)

        ans += stk_acc[-1] - (n + 1 - i) * acc[i]

    print(ans)


MT = int(input())
for _ in range(MT):
    soviet()
