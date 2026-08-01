import sys
input = lambda: sys.stdin.readline().rstrip()

def solve():
    n = int(input())
    s = input()
    
    if s == '1' * n:
        print('a' * n)
    elif s == ''.join('1' if i % 2 == 0 else '0' for i in range(n)):
        print(''.join('a' if i % 2 == 0 else 'b' for i in range(n)))
    elif s == '1' + '0' * (n - 1):
        print('a' * (n - 1) + 'b')
    elif n >= 2 and s == '1' + '0' * (n - 2) + '1':
        print('a' * ((n - 1) // 2) + 'b' * (n - (n - 1) // 2 * 2) + 'a' * ((n - 1) // 2))
    else:
        print('-1')

T = int(input())
for _ in range(T):
    solve()
