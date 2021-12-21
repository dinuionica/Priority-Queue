import random

print("GENERATOR TEST:\n")

# read the test number
test_number = int(input("Enter the number of test: "))

# create a list of commands
list_commands = ["push", "pop", "top"]

# take the range and the number of elements for the list
number_elements = int(input("Enter the number of elements for the list: "))
range_list = int(input("Enter the range for the list of numbers: "))

# generate a random list of numbers
list_numbers = random.sample(range(range_list), number_elements)

# take a input about sorting
choice = input("Do you want a sorted list : yes/no ")
if choice == "yes":
    is_sorted = True
    second_choice = input("Ascending or descending: a/d ")
    if second_choice == "a":
        ascending_order = True
    else:
        ascending_order = False
else:
    is_sorted = False

# open the file with the desired name
file = open("./in/test" + str(test_number) + ".in", "w")

if is_sorted == True:
    if ascending_order == True:
        list_numbers.sort()
        for number in list_numbers:
            file.write("push " + str(number) + '\n')
    else:
        list_numbers.sort(reverse=True)
        for number in list_numbers:
            file.write("push " + str(number) + '\n')
            
# generate a random number of push operations 
upper_limit = int(input(
              "Enter the upper limit for number of push operations: " ))
for i in range(random.randint(0, upper_limit)):
    file.write("push " + str(random.choice(list_numbers)) + '\n')

# generate a random number of operations
upper_limit = int(input(
              "Enter the upper limit for number of random operations: " ))
for i in range(random.randint(0, upper_limit)):
    command = random.choice(list_commands)
    if command == "push":
        file.write(command + " " + str(random.choice(list_numbers)) + '\n')
    else:
        file.write(command + '\n')
    
# close the file
file.close()

print ("Test " + str(test_number) + " was generated with success!\n");
    