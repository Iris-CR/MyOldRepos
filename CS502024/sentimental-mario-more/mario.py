import cs50

while True:
    height = cs50.get_int("Height: ")
    if height > 0 and height < 9:
        break
for i in range(1, height+1):
    for j in range(height-i):
        print(" ", end="")
    for k in range(i):
        print("#", end="")
    print("  ", end="")
    for l in range(i):
        print("#", end="")
    print()
