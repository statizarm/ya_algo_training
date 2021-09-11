import sys

n = map(int, sys.stdin.readline())

prev = [num for num in map(int, sys.stdin.readline())]
deltas = [prev[-1] - num for num in prev[:-1]]
numbers = {num for num in map(int, sys.stdin.readline())}
count = [0] * 101

for num in numbers:
  count[num] += 1

for i in range (1, 101):
  count[i] += 1;
  numbers[n] = i;

  for num in numbers:
    if count[num] == 1:
      

