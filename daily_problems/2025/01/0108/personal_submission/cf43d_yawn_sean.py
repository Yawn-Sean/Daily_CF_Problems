# Submission link: https://codeforces.com/contest/43/submission/300100351
def main():
    n, m = MII()

    if n == 1:
        if m == 2:
            print(0)
            print(1, 1)
            print(1, 2)
            print(1, 1)
        else:
            print(1)
            print(1, m, 1, 1)
            print('\n'.join(f'1 {i}' for i in range(1, m + 1)))
            print(1, 1)

    elif m == 1:
        if n == 2:
            print(0)
            print(1, 1)
            print(2, 1)
            print(1, 1)
        else:
            print(1)
            print(n, 1, 1, 1)
            print('\n'.join(f'{i} 1' for i in range(1, n + 1)))
            print(1, 1)

    elif n % 2 == 0:
        print(0)
        outs = []
        outs.append('\n'.join(f'{i} 1' for i in range(1, n + 1)))
        
        for i in range(n):
            if i % 2 == 0: outs.append('\n'.join(f'{n - i} {j}' for j in range(2, m + 1)))
            else: outs.append('\n'.join(f'{n - i} {j}' for j in range(m, 1, -1)))
        
        outs.append('1 1')
        print('\n'.join(outs))

    elif m % 2 == 0:
        print(0)
        outs = []
        outs.append('\n'.join(f'1 {i}' for i in range(1, m + 1)))
        
        for i in range(m):
            if i % 2 == 0: outs.append('\n'.join(f'{j} {m - i}' for j in range(2, n + 1)))
            else: outs.append('\n'.join(f'{j} {m - i}' for j in range(n, 1, -1)))
        
        outs.append('1 1')
        print('\n'.join(outs))

    else:
        print(1)
        print(n, m, 1, 1)
        
        outs = []
        for i in range(1, n + 1):
            if i % 2: outs.append('\n'.join(f'{i} {j}' for j in range(1, m + 1)))
            else: outs.append('\n'.join(f'{i} {j}' for j in range(m, 0, -1)))
        
        outs.append('1 1')
        print('\n'.join(outs))