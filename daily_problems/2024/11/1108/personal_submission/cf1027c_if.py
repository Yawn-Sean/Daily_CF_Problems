from collections import Counter
import sys
input = sys.stdin.readline
def solve():
    n = int(input())
    a = list(map(int, input().split()))
    hash_map = Counter(a)
    
    for key, value in hash_map.items():
        if value >= 4:
            print(f"{key} {key} {key} {key}")
            return
    
    b = [(key, value) for key, value in hash_map.items() if value >= 2]
    b.sort(key = lambda x: x[0])  # Sort by the first element (key)
    
    ans = float('inf')
    ans1, ans2 = -1, -1
    
    for i in range(len(b) - 1):
        p1 = b[i][0]
        p2 = b[i + 1][0]
        cur = p1 / p2 + p2 / p1
        if cur < ans:
            ans = cur
            ans1 = p1
            ans2 = p2
    
    print(f"{ans1} {ans1} {ans2} {ans2}")

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
