n = int(input())
a = list(map(int, input().split()))
i = 0
j = n - 1

while i < n - 1 and a[i] < a[i + 1]:
    i += 1

while j > 0 and a[j] < a[j - 1]:
    j -= 1

if (i + 1) % 2 == 1 or (n - j) % 2 == 1:
    print("Alice")
else:
    print("Bob")
