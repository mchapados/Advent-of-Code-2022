def most_calories(elf_calories):
    most = 0
    for elf in elf_calories:
        food = elf.split('\n')
        food_sum = 0
        for item in food:
            if item != "":
                food_sum += int(item)
        if food_sum > most:
            most = food_sum
    return most

def top_3_most_calories(elf_calories):
    top_3 = [0, 0, 0]
    for elf in elf_calories:
        food = elf.split('\n')
        food_sum = 0
        for item in food:
            if item != "":
                food_sum += int(item)
        if food_sum > min(top_3):
            top_3[top_3.index(min(top_3))] = food_sum
    return sum(top_3)

input_file = open("input_files/day1_input.txt", "r")
elf_calories = input_file.read().split('\n\n')
input_file.close()
print(most_calories(elf_calories))
print(top_3_most_calories(elf_calories))