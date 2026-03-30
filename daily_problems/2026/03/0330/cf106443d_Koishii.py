for _ in range(int(input())):
    n = int(input())
    print('the greatest' if (n + 2) & (-2 - n) == n + 2 else 'mastermei')
