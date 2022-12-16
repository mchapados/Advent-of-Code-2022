from math import floor
PRIORITY = "-abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

def get_priority_sum(rucksacks):
    priority_sum = 0
    for sack in rucksacks:
        comp1, comp2 = sack[:floor(len(sack)/2)], sack[floor(len(sack)/2):]
        for item in comp1:
            if item in comp2:
                priority_sum += PRIORITY.index(item)
                break
    return priority_sum

def get_priority_sum_badges(rucksacks):
    priority_sum = 0
    for i in range(0, len(rucksacks), 3):
        elf1, elf2, elf3 = set(rucksacks[i]), set(rucksacks[i+1]), set(rucksacks[i+2])
        item = str(elf1.intersection(elf2, elf3))[2]
        priority_sum += PRIORITY.index(item)          
    return priority_sum

input_file = open("input_files/day3_input.txt", "r")
rucksacks = input_file.read().split('\n')
input_file.close()
print(get_priority_sum(rucksacks))
print(get_priority_sum_badges(rucksacks))