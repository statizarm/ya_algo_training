import sys

max_number = 0
count = 0

for num in map(int, sys.stdin):
  if num == 0:
    break;

  if num > max_number:
    max_number = num
    count = 1
  elif num == max_number:
    count += 1

print(count)

