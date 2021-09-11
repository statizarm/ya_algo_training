import sys

l, k = map(int, sys.stdin.readline().split())

coords = list(map(int, sys.stdin.readline().split()))

mid = 0
for i in range(k):
  if coords[i] <= (l - 1) // 2:
    mid = i
  else:
    break

for i in range (mid, k):
  if coords[i] * 2 + 1 >= l:
    if i == mid:
      print(coords[mid])
    else:
      print(f'{coords[mid]} {coords[i]}')
    break

