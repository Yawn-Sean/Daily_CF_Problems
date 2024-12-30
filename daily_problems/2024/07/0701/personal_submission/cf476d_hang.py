
def main():
    n,k = map(int,input().split())
    ans = []
    ans.append(f'{k * (n * 6 - 1)}')
    for i in range(n):
        ans.append(f'{k * (i * 6 + 1)} {k * (i * 6 + 2)} {k * (i * 6 + 3)} {k * (i * 6 + 5)}')
    print('\n'.join(ans))
main()