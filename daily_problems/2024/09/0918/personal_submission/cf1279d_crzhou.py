MOD = 998244353
n = II()
cnt = defaultdict(int)
cnt1 = defaultdict(list)
s = 0
mx = 1
for _ in range(n):
    nums = LII()
    k = nums[0]
    s += k
    mx = lcm(mx, k)
    for i in range(1, k + 1):
        cnt[nums[i]] += 1
        cnt1[nums[i]].append(k)

total = n * mx * n
right = 0
for a, b in cnt.items():
    cur = 0
    for v in cnt1[a]:
        cur += mx // v
    right += cur * b

g = gcd(total, right)
x = right // g
y = total // g

def mod_inv(a, mod):
    return pow(a, mod - 2, mod)

result = x * mod_inv(y, MOD) % MOD

print(result)
