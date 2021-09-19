import sys

n, k = map(int, sys.stdin.readline().split())

stones = sys.stdin.readline()[:n]
stone_pairs = dict()

for i in range(k):
    pair = sys.stdin.readline()
    f, s = pair[0], pair[1]
    if s not in stone_pairs:
        stone_pairs[s] = []
    stone_pairs[s].append(f)

stone_count = dict()
total = 0
for s in stones:
    if s not in stone_count:
        stone_count[s] = 0

    if s in stone_pairs:
        for p in stone_pairs[s]:
            if p in stone_count:
                total += stone_count[p]

    stone_count[s] += 1


sys.stdout.write(f'{total}\n')
