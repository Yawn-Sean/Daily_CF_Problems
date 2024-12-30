import sys
input = sys.stdin.buffer.readline

n = int(input())
bit_dict = {}

for i in range(1, n + 1):
    binary_str = bin(i)[2:].zfill(10)
    for j in range(10):
        bit_value = int(binary_str[j])
        if (j, bit_value) not in bit_dict:
            bit_dict[(j, bit_value)] = []
        bit_dict[(j, bit_value)].append(i)

answer = [float('inf')] * n

for (j, bit_value) in bit_dict:
    opposite_bit_value = 1 - bit_value
    if (j, opposite_bit_value) in bit_dict:
        current_list = bit_dict[(j, bit_value)]
        sys.stdout.write(f'{len(current_list)}\n')
        sys.stdout.flush()
        sys.stdout.write(' '.join(map(str, current_list)) + '\n')
        sys.stdout.flush()
        response = list(map(int, input().split()))
        for idx in range(n):
            if idx + 1 not in current_list:
                answer[idx] = min(answer[idx], response[idx])

sys.stdout.write('-1\n')
sys.stdout.flush()
sys.stdout.write(' '.join(map(str, answer)) + '\n')
sys.stdout.flush()
