'''
https://codeforces.com/gym/105129/submission/344791008
'''
# 枚举全子集
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]
sorted_ans = [1]
for p in primes:
    for i in range(len(sorted_ans)):
        sorted_ans.append(sorted_ans[i] * p)
sorted_ans.sort()

def solve(n: int, a: list[int]) -> int:
    global sorted_ans
    a = list(set(a))
    for ans in sorted_ans:
        for x in a:
            if gcd(ans, x) == 1:
                break
        else:
            return ans

