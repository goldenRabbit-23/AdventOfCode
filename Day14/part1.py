import sys

data = open(sys.argv[1]).readlines()

rock = []
final_level = 0

for line in data:
    arr = line.split()
    for i, pair in enumerate(arr):
        if i % 2 == 0:
            x, y = map(int, pair.split(','))
            if i == 0:
                rock.append([x, y])
            else:
                if x == lastX:
                    if y > lastY:
                        for y1 in range(lastY + 1, y + 1):
                            rock.append([x, y1])
                    else:
                        for y1 in range(y, lastY):
                            rock.append([x, y1])
                else:
                    if x > lastX:
                        for x1 in range(lastX + 1, x + 1):
                            rock.append([x1, y])
                    else:
                        for x1 in range(x, lastX):
                            rock.append([x1, y])

            lastX, lastY = x, y

            final_level = max(final_level, lastY)

sand = []
sand_cnt = 0
finished = False

while True:
    sandX, sandY = 500, 0

    while True:
        if sandY > final_level:
            finished = True
            break

        if [sandX, sandY + 1] not in rock and [sandX, sandY + 1] not in sand:
            sandY += 1
        elif [sandX - 1, sandY + 1] not in rock and [sandX - 1, sandY + 1] not in sand:
            sandX -= 1
            sandY += 1
        elif [sandX + 1, sandY + 1] not in rock and [sandX + 1, sandY + 1] not in sand:
            sandX += 1
            sandY += 1
        else:
            sand.append([sandX, sandY])
            sand_cnt += 1
            break

    if finished:
        break

print(sand_cnt)
