from math import floor

class Monkey:
    def __init__(self, items, operation, test):
        self.items = items
        self.operation = operation
        self.test = test
        self.items_inspected = 0

    def inspect_item(self, item_id):
        self.items_inspected += 1
        # perform monkey's operation
        try:
            num = int(self.operation[1])
        except:
            num = self.items[item_id]

        if self.operation[0] == '*':
            self.items[item_id] *= num
        else:
            self.items[item_id] += num
        
        # PART 1: divide by 3 and round down
        #self.items[item_id] = floor(self.items[item_id] / 3)

        # PART 2
        self.items[item_id] %= 9699690
        
        # run test, return id of monkey to throw to
        if self.items[item_id] % self.test[0] == 0:
            return self.test[1]
        return self.test[2]

input_file = open("input_files/day11_input.txt")
monkey_input = input_file.read().split("\n\n")
input_file.close()

# create a list of monkeys
monkeys = []
for m in monkey_input:
    lines = m.split("\n")
    items = lines[1][lines[1].find(':')+1:].split(',')
    items = [int(i) for i in items]
    operation = lines[2].split()[4:]
    test = [lines[3].split()[3], lines[4].split()[5], lines[5].split()[5]]
    test = [int(i) for i in test]
    monkeys.append(Monkey(items, operation, test))

items_inspected = []
# play game for 20 rounds (PART 1) or 10,000 rounds (PART 2)
for i in range(10000):
    for monkey in monkeys:
        # inspect and throw all items
        for k in range(len(monkey.items)):
            next_monkey = monkey.inspect_item(k)
            monkeys[next_monkey].items.append(monkey.items[k])
        monkey.items.clear()
        if i == 10000-1: # last round
            items_inspected.append(monkey.items_inspected)

# find 2 monkeys who inspected the most items and multiply them
top = max(items_inspected)
items_inspected.remove(top)
result = top * max(items_inspected)
print(result)
            