from functools import cmp_to_key
import bisect
def main():
    n = int(input())
    
    bid = [[] for i in range(n + 1)]
    mx = [-1] * (n + 1)
    for i in range(n):
        a,b = map(int,input().split())
        bid[a].append(b)
        mx[a] = max(mx[a],b)
    
    q = [i for i in range(n + 1)]
    def cmp(a,b):
        return mx[a] - mx[b]
    q.sort(key=cmp_to_key(cmp))
    idx = [0] * (n + 1)
    for i in range(n + 1):
        idx[q[i]] = i
    z = [0] * (n + 1)
    query = int(input())
    ans = []
    for i in range(query):
        b = list(map(int,input().split()))[1:]
        for x in b:
            z[idx[x]] = 1
        winner = -1
        price = -1
        for i in range(n, -1, -1):
            if not z[i]:
                if winner == -1:
                    winner = q[i]
                else:
                    price = mx[q[i]]
                    break
        if mx[winner] == -1:
            ans.append('0 0')
        else:
            price = bid[winner][bisect.bisect_left(bid[winner], price)]
            ans.append(f'{winner} {price}')
        for x in b:
            z[idx[x]] = 0
    
    for x in ans:
        print(x)



main()