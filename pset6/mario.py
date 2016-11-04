import cs50
rows = cs50.get_int()
stars = "*"
if (rows > 23 or rows<0):
    print("Height must be greater than 0")
else:
    for i in range(rows):
        stars+="*"
        print(" "*((rows+1)-stars.count("*"))+stars)