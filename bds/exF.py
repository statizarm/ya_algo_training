import sys


class Cache(object):
    def __init__(self, m):
        self.m = m
        self.heap = []
        self.cached = dict()
        self.cached_index = dict()

    def push(self, index, time, op_id):
        if index in self.cached:
            if self.cached[index] < time:
                i = self.cached_index[index]
                self.heapify_to_leaf(i, (time, index))
                self.cached[index] = time

                sys.stdout.write(' '.join([str(op_id), 'UPDATE', index, '\n']))
        elif len(self.heap) < self.m:
            self.hpush((time, index))
            self.cached[index] = time

            sys.stdout.write(' '.join([str(op_id), 'PUT', index, '\n']))
        elif time < self.heap[0][0]:
            pass
        else:
            item = self.heap[0]
            self.heapify_to_leaf(0, (time, index))

            self.cached.pop(item[1])
            self.cached_index.pop(item[1])

            self.cached[index] = time

            sys.stdout.write(' '.join([str(op_id), 'DELETE', item[1], '\n']))
            sys.stdout.write(' '.join([str(op_id), 'PUT', index, '\n']))

    def hpush(self, item):
        n = len(self.heap)
        self.heap.append(item)
        self.heapify_to_parent(n, item)

    def heapify_to_leaf(self, i, item):
        l = self.left(i)
        n = len(self.heap)
        while l < n:
            r = self.right(i)
            if r < n and self.heap[r] < self.heap[l]:
                dst = r
            else:
                dst = l

            if item > self.heap[dst]:
                self.cached_index[self.heap[dst][1]] = i
                self.heap[i] = self.heap[dst]
            else:
                break

            i = dst
            l = self.left(i)

        self.heap[i] = item
        self.cached_index[item[1]] = i

    def heapify_to_parent(self, i, item):
        while i > 0:
            p = self.parent(i)

            if item < self.heap[p]:
                self.cached_index[self.heap[p][1]] = i
                self.heap[i] = self.heap[p]
                pass
            else:
                break
            i = p

        self.cached_index[item[1]] = i
        self.heap[i] = item

    @staticmethod
    def left(i):
        return i * 2 + 1

    @staticmethod
    def right(i):
        return (i + 1) * 2

    @staticmethod
    def parent(i):
        return (i - 1) // 2


def main():
    f = open('input.txt')
    n, m = map(int, f.readline().split())
    cache = Cache(m)

    for i in range(1, n + 1):
        index, time = f.readline().split()
        time = int(time)
        cache.push(index, time, i)


if __name__ == '__main__':
    main()
