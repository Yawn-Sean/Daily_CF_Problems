def main():
    n = int(input())
    a = list(map(int, input().split()))
    chains = [i for i in range(n) if a[i] > 1]
    nodes = [i for i in range(n) if a[i] == 1]
    ans = 0
    length = len(chains)
    if length == 0:
        exit(print('NO'))
    outs = []
    ans = length - 1
    if length > 1:
        for i in range(1, length):
            outs.append(f'{chains[i - 1] + 1} {chains[i] + 1}')
        a[chains[0]] -= 1
        a[chains[-1]] -= 1
        for i in range(1, length-1):
            a[chains[i]] -= 2
    head1 = False
    head2 = False
    for u in nodes:
        if not head1:
            head1 = True
            a[chains[0]] -= 1
            outs.append(f'{u + 1} {chains[0] + 1}')
        elif not head2:
            head2 = True
            a[chains[-1]] -= 1
            outs.append(f'{u + 1} {chains[-1] + 1}')
        else:
            for v in chains:
                if a[v]:
                    a[v] -= 1
                    outs.append(f'{u + 1} {v + 1}')
                    break
            else:
                exit(print('NO'))
    print('YES', ans + head1 + head2)
    print(len(outs))
    print('\n'.join(outs))

main()