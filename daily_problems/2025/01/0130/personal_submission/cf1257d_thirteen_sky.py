import sys
import math

def solve():
    input = sys.stdin.read
    data = input().split()
    ptr = 0
    t = int(data[ptr])
    ptr +=1
    for _ in range(t):
        n = int(data[ptr])
        ptr +=1
        a = list(map(int, data[ptr:ptr+n]))
        ptr +=n
        m = int(data[ptr])
        ptr +=1
        heroes = []
        max_s = 0
        for __ in range(m):
            p, s = map(int, data[ptr:ptr+2])
            ptr +=2
            heroes.append((p, s))
        
        log_table = [0]*(n+1)
        for i in range(2, n+1):
            log_table[i] = log_table[i//2] +1
        k_max = log_table[n] +1 if n>0 else 0
        st = []
        if n>0:
            st = [[0]*n for _ in range(k_max)]
            for i in range(n):
                st[0][i] = a[i]
            for k in range(1, k_max):
                for i in range(n - (1<<k) +1):
                    st[k][i] = max(st[k-1][i], st[k-1][i + (1<<(k-1))])
        
        def get_max(l, r):
            if l > r:
                return 0
            length = r - l +1
            k = log_table[length]
            return max(st[k][l], st[k][r - (1<<k) +1])
        

        p_max = [0]*(n+2)  
        for p, s in heroes:
            s_clamped = min(s, n)
            if s_clamped <=0:
                continue
            if p > p_max[s_clamped]:
                p_max[s_clamped] = p

        for L in range(n, 0, -1):
            if L+1 <=n:
                if p_max[L] < p_max[L+1]:
                    p_max[L] = p_max[L+1]
        

        max_L = [0]*n
        possible = True
        for i in range(n):
            low =1
            high = n -i
            best =0
            while low <=high:
                mid = (low + high)//2
                end = i + mid -1
                if end >=n:
                    high = mid-1
                    continue
                current_max = get_max(i, end)
                if current_max <= p_max[mid]:
                    best = mid
                    low = mid+1
                else:
                    high = mid-1
            max_L[i] = best
            if best ==0:
                possible = False
        
        if not possible:
            print(-1)
            continue
        

        days =0
        current_end =0
        next_end =0
        for i in range(n):
            if i > current_end:
                possible = False
                break
            next_end = max(next_end, i + max_L[i])
            if i == current_end:
                days +=1
                current_end = next_end
                if current_end >=n:
                    break
        
        if current_end >=n:
            print(days)
        else:
            print(-1)
        
if __name__ == '__main__':
    solve()
