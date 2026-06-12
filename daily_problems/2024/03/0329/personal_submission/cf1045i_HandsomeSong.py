import sys
from collections import defaultdict

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    n = int(input_data[0])
    strings = input_data[1:n+1]
    
    count = defaultdict(int)
    ans = 0
    
    for s in strings:
        mask = 0
        for char in s:
            mask ^= (1 << (ord(char) - ord('a')))
            
        ans += count[mask]
    
        for i in range(26):
            ans += count[mask ^ (1 << i)]
            
        count[mask] += 1
        
    print(ans)

if __name__ == '__main__':
    solve()
