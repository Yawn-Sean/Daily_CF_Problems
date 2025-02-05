n = int(input())
dis = list(map(int, input().split()))
order = sorted(range(n), key=dis.__getitem__, reverse=True)
chain = [i*2+1 for i in order]
for i in range(n):
    d = dis[order[i]]
    v = 2*order[i]+2
    if i + d >= len(chain):
        chain.append(v)
    else:
        print(chain[i+d-1], v)
for i in range(len(chain)-1):
    print(chain[i], chain[i+1])
