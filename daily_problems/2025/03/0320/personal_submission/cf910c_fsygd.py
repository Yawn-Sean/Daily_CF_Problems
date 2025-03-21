n = int(input())
non_zero = set()
weights = {key: 0 for key in range(10)}
for i in range(n):
    numbers = input().strip()
    length = len(numbers)
    for j in range(length):
        key = ord(numbers[j]) - ord('a')
        weights[key] += 10 ** (length - j - 1)
    non_zero.add(ord(numbers[0]) - ord('a'))
ans = 0
used = set()
select = -1
for i in range(10):
    if i not in non_zero and (select == -1 or weights[i] > weights[select]):
        select = i
used.add(select)
for i in range(1, 10):
    select = -1
    for j in range(10):
        if j not in used and (select == -1 or weights[j] > weights[select]):
            select = j
    ans += weights[select] * i
    used.add(select)
print(ans)