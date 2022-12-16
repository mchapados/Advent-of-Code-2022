class File:
    def __init__(self, name, type, parent = None, size = 0):
        self.name = name
        self.size = size
        self.type = type
        self.parent = parent
        self.children = []

    def add_file(self, file):
        if self.type == 'd':
            self.children.append(file)

    def has_file(self, name):
        if self.type == 'd':
            for file in self.children:
                if file.name == name:
                    return True
        return False

    def get_file(self, name):
        if self.type == 'd':
            for file in self.children:
                if file.name == name:
                    return file
        return None
    
    def get_dir_size(self):
        if self.type == 'd':
            self.size = 0
            for file in self.children:
                if file.type == 'd':
                    file.get_dir_size()
                self.size += file.size
        return self.size

# get sum of sizes of all directories with size <= 100000
def get_sum(dir):
    result = 0
    if dir.type == 'd' and dir.get_dir_size() <= 100000:
        result += dir.size
    if len(dir.children) > 0:
        for file in dir.children:
            if file.type == 'd':
                result += get_sum(file)
    return result

TOTAL_SPACE = 70000000

root = File("/", "d") # root directory
input_file = open("input_files/day7_input.txt", "r")
commands = input_file.read().split('\n')
input_file.close()

# THIS PART CREATES THE FILE SYSTEM
curr_dir = root
for line in commands:
    if line[0] == '$' and 'cd' in line: # change current directory
        new_dir_name = line[5:]
        if new_dir_name == '/':
            curr_dir = root
        elif new_dir_name == '..':
            curr_dir = curr_dir.parent
        else: 
            if not curr_dir.has_file(new_dir_name):
                curr_dir.add_file(File(new_dir_name, 'd', curr_dir))
            curr_dir = curr_dir.get_file(new_dir_name)
    elif line[0] != '$': # line contains files in curr_dir
        if line.startswith('dir'):
            new_file_name = line[4:]
            new_file_size = 0
            new_file_type = 'd'
        else:
            new_file_size, new_file_name = line.split()
            new_file_type = 'f'
        if not curr_dir.has_file(new_file_name):
            curr_dir.add_file(File(new_file_name, new_file_type, curr_dir, int(new_file_size)))

print(get_sum(root))

# PART 2
space_needed = 30000000
free_space = TOTAL_SPACE - root.get_dir_size()
space_needed -= free_space

sizes = []
def get_all_sizes(dir, sizes):
    sizes.append(dir.size)
    for file in dir.children:
        if file.type == 'd':
            get_all_sizes(file, sizes)

get_all_sizes(root, sizes)
delete = root.size
for s in sizes:
    if s < delete and s >= space_needed:
        delete = s

print(delete)