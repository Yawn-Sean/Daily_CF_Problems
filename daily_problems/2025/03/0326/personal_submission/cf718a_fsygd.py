n, t = list(map(int, input().split(' ')))
integer, decimal = input().split('.')
integer = [int(digit) for digit in integer]
decimal = [int(digit) for digit in decimal]
for i in range(len(decimal)):
    if decimal[i] >= 5:
        j = i
        while (j > 0 and decimal[j - 1] == 4 and i - j + 2 <= t):
            j -= 1
        decimal = decimal[:j]

        j = len(decimal) - 1
        while j >= 0 and decimal[j] == 9:
            j -= 1
        
        if j >= 0:
            decimal[j] += 1
            decimal = decimal[:j + 1]
        else:
            j = len(integer) - 1
            while j >= 0 and integer[j] == 9:
                j -= 1
            
            if j >= 0:
                integer[j] += 1
                for k in range(j + 1, len(integer)):
                    integer[k] = 0
            else:
                for k in range(len(integer)):
                    integer[k] = 0
                integer = [1] + integer
        
        break
ans = ''.join(map(str, integer))
if len(decimal) > 0:
    ans += '.' + ''.join(map(str, decimal))
print(ans)