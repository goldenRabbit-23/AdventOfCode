import sys
from functools import cmp_to_key

data = open(sys.argv[1]).read().strip()

pairs = data.split('\n\n')


def comp(left, right):
    if isinstance(left, int) and isinstance(right, int):
        if left < right:
            return -1
        elif left == right:
            return 0
        else:
            return 1

    elif isinstance(left, list) and isinstance(right, list):
        i = 0

        while i < len(left) and i < len(right):
            res = comp(left[i], right[i])

            if res == -1:
                return -1
            elif res == 1:
                return 1

            i += 1

        if i == len(left) and i < len(right):
            return -1
        elif i < len(left) and i == len(right):
            return 1
        else:
            return 0

    elif isinstance(left, int) and isinstance(right, list):
        return comp([left], right)

    else:
        return comp(left, [right])


packets = []

for pair in pairs:
    left, right = pair.split('\n')
    packets.append(eval(left))
    packets.append(eval(right))

packets.append([[2]])
packets.append([[6]])

packets = sorted(packets, key=cmp_to_key(lambda p1, p2: comp(p1, p2)))

ans = 1

for idx, packet in enumerate(packets):
    if packet == [[2]] or packet == [[6]]:
        ans *= idx + 1

print(ans)
