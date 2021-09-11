import sys

n = int(sys.stdin.readline())

s = 0
m = 0
for n in map(int, sys.stdin.readline().split()):
  if n > m:
    m = n
  s += n

print(s - m)

