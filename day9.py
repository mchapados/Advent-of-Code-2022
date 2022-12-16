import copy

def update_tail(H_pos, T_pos):
    if H_pos[0] == T_pos[0]: # same row
        if H_pos[1] > T_pos[1] and H_pos[1] - T_pos[1] == 2:
            T_pos[1] += 1
        elif H_pos[1] < T_pos[1] and T_pos[1] - H_pos[1] == 2:
            T_pos[1] -= 1
    elif H_pos[1] == T_pos[1]: # not same row, but same column
        if H_pos[0] > T_pos[0] and H_pos[0] - T_pos[0] == 2:
            T_pos[0] += 1
        elif H_pos[0] < T_pos[0] and T_pos[0] - H_pos[0] == 2:
            T_pos[0] -= 1
    elif abs(H_pos[0]-T_pos[0]) > 1 or abs(H_pos[1]-T_pos[1]) > 1: # not same row or column
        if H_pos[0] > T_pos[0]: # head is in a higher row
            T_pos[0] += 1
        else:
            T_pos[0] -= 1
        if H_pos[1] > T_pos[1]: # head is to the right of tail
            T_pos[1] += 1
        else:
            T_pos[1] -= 1

input_file = open("input_files/day9_input.txt", "r")
motions = input_file.read().split('\n')
input_file.close()

H_pos = [0, 0]
T_pos = [0, 0]
visited = [[0, 0]]

moves = {"L": [0, -1], "R": [0, 1], "D": [-1, 0], "U": [1, 0]}

for line in motions:
    dir, num = line.split()
    num = int(num)
    for i in range(num):
        H_pos[0] += moves[dir][0]
        H_pos[1] += moves[dir][1]
        update_tail(H_pos, T_pos)
        if T_pos not in visited:
            visited.append(copy.deepcopy(T_pos))

print(len(visited))

# part 2
H_pos = [0, 0]
T_pos = []
visited = [[0, 0]]
for i in range(9):
    T_pos.append([0, 0])

for line in motions:
    dir, num = line.split()
    num = int(num)
    for i in range(num):
        H_pos[0] += moves[dir][0]
        H_pos[1] += moves[dir][1]
        for i in range(len(T_pos)):
            if i == 0:
                update_tail(H_pos, T_pos[i])
            else:
                update_tail(T_pos[i-1], T_pos[i])
        if T_pos[8] not in visited:
            visited.append(copy.deepcopy(T_pos[8]))

print(len(visited))