n = 200000
m = 100000
print(f'{n} {m}')

for j in range(int(1e12), int(1e12) + n // m + 1):
    for i in range(1, m + 1):
        print(f'{i} {i*j}')
