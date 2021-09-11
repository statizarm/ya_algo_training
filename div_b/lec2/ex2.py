import sys

houses = []
stores = []

for i, t in enumerate(map(int, sys.stdin.readline().split())):
  if t == 1:
    houses.append(i)
  elif t == 2:
    stores.append(i)

max_dist = 0

for h in houses:
  min_dist = abs(stores[0] - h)

  for s in stores[1:]:
    dist = abs(s - h)
    if dist < min_dist:
      min_dist = dist

  if min_dist > max_dist:
    max_dist = min_dist

print(max_dist)

