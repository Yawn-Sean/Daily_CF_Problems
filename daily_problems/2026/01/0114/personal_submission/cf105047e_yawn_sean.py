# Submission link: https://codeforces.com/gym/105047/submission/357670577
def main(): 
    n = II()
    nums = LII()
    ops = []
    
    def operate(i, j):
        if i != j:
            nums[i] ^= nums[j]
            ops.append(f'{i + 1} {j + 1}')
    
    def swap_zero(i, j):
        if i != j:
            operate(i, j)
            operate(j, i)
    
    for _ in range(100):
        u, v = random.randint(0, n - 1), random.randint(0, n - 1)
        operate(u, v)
    
    dp = [0] * (1 << 21)
    
    for i in range(1, 1 << 21):
        v = i & -i
        dp[i] = dp[i - v] ^ nums[v.bit_length() - 1]
    
    for i in range(1, 1 << 21):
        if dp[i] == 0:
            idxs = [j for j in range(21) if i >> j & 1]
            for j in range(1, len(idxs)):
                operate(idxs[0], idxs[j])
            swap_zero(idxs[0], 0)
            break
    
    pos = sorted(range(n), key=lambda x: nums[x])
    val = [0] * n
    
    for i in range(n):
        val[pos[i]] = i
    
    for i in range(1, n):
        if val[i] != i:
            pos[val[0]], pos[val[i]] = pos[val[i]], pos[val[0]]
            val[0], val[i] = val[i], val[0]
            swap_zero(0, i)
            
            cur = i
            while val[0] != cur:
                ncur = pos[cur]
                pos[val[cur]], pos[val[ncur]] = pos[val[ncur]], pos[val[cur]]
                val[cur], val[ncur] = val[ncur], val[cur]
                swap_zero(cur, ncur)
                cur = ncur
            
            pos[val[0]], pos[val[cur]] = pos[val[cur]], pos[val[0]]
            val[0], val[cur] = val[cur], val[0]
            swap_zero(cur, 0)
    
    print(len(ops))
    print('\n'.join(ops))