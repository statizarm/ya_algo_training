import sys

n = int(sys.stdin.readline())

for i in range(n):
  res = 0
  for j, n in enumerate(map(int, sys.stdin.readline().split())):
    if j != i:
      res = res | n

  sys.stdout.write(f'{res} ')

sys.stdout.write('\n')

