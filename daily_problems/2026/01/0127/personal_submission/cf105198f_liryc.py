'''
https://codeforces.com/gym/105198/submission/360082069
'''
# lookup table
lut = ['-1', '-1', '1', '7', '4', '2', '0', '8', '10', '18', '22', '20', '28', '68', '88', '108', '188', '200', '208', '288']
for _ in range(int(input())):
    n = int(input())
    d, r = divmod(n, 7)
    while r + 7 < 20 and d > 0:
        r += 7
        d -= 1
    print(lut[r] + '8' * d)