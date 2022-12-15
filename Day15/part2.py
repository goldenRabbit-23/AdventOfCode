import sys

data = open(sys.argv[1]).readlines()

MAX = 4000000
sensors = []
beacons = []

for line in data:
    line = line.strip().split()
    sensor_X = int(line[2].rstrip(",").lstrip("x="))
    sensor_Y = int(line[3].rstrip(":").lstrip("y="))
    closest_beacon_X = int(line[8].rstrip(",").lstrip("x="))
    closest_beacon_Y = int(line[9].lstrip("y="))

    sensors.append([sensor_X, sensor_Y])
    beacons.append([closest_beacon_X, closest_beacon_Y])

mds = []

for sensor, beacon in zip(sensors, beacons):
    mds.append(abs(sensor[0] - beacon[0]) + abs(sensor[1] - beacon[1]))

x = 0
y = 0

while y <= MAX:
    while x <= MAX:
        found = True
        for sensor, md in zip(sensors, mds):
            cd = abs(x - sensor[0]) + abs(y - sensor[1])
            if cd <= md:
                if x >= sensor[0]:
                    x += md - cd
                else:
                    x += (md - abs(y - sensor[1])) * 2 - (md - cd)

                x += 1
                found = False
                break

        if found:
            print(x * 4000000 + y)
            exit(0)

    x = 0
    y += 1
