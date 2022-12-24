LETTERS = "abcdefghijklmnopqrstuvwxyz"

input_file = open("input_files/day12_input.txt")
heightmap = []
for row in input_file.read().split("\n"):
    heightmap.append(list(row))
input_file.close()

# find starting and ending positions
found = 0
for i in range(len(heightmap)):
    for j in range(len(heightmap[i])):
        if heightmap[i][j] == 'S':
            start = (i, j)
            found += 1
        elif heightmap[i][j] == 'E':
            end = (i, j)
            found += 1
        if found == 2:
            break

def find_shortest_path(start, end, steps):
    curr_elevation = heightmap[start[0]][start[1]]