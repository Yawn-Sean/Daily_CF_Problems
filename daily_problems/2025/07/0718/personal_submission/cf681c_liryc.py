'''
https://codeforces.com/problemset/submission/681/329594508
'''
# priorityqueue, constructive
from heapq import heappop, heappush
from sys import stdin
input = lambda: stdin.readline().strip()

hp = []
ans = []

def solve(s: str) -> None:
    global hp, ans
    if s[0] == 'i': # insert
        heappush(hp, int(s.split()[1]))
        ans.append(s)
    elif s[0] == 'g': # getMin
        x = int(s.split()[1])
        while hp and hp[0] < x:
            heappop(hp)
            ans.append("removeMin")
        if not hp or hp[0] != x:
            heappush(hp, x)
            ans.append(f"insert {x}")
        ans.append(s)
    else: # removeMin
        if hp:
            heappop(hp)
        else:
            ans.append("insert 1")
        ans.append(s)

if __name__ == '__main__':
    for _ in range(int(input())):
        solve(input())
    print(len(ans))
    print(*ans, sep='\n')
