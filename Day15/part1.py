import sys

data = open(sys.argv[1]).readlines()

threshold_Y = 2000000
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

no_beacon_area = set()

for sensor, beacon in zip(sensors, beacons):
    md = abs(sensor[0] - beacon[0]) + abs(sensor[1] - beacon[1])

    if abs(sensor[1] - threshold_Y) > md:
        continue

    md -= abs(sensor[1] - threshold_Y)
    sensor[1] = threshold_Y

    if [sensor[0], sensor[1]] not in beacons:
        no_beacon_area.add((sensor[0], sensor[1]))

    for i in range(1, md + 1):
        if [sensor[0] - i, sensor[1]] not in beacons:
            no_beacon_area.add((sensor[0] - i, sensor[1]))
        if [sensor[0] + i, sensor[1]] not in beacons:
            no_beacon_area.add((sensor[0] + i, sensor[1]))

print(len(no_beacon_area))
