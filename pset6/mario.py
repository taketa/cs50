import cs50
rows = cs50.get_int()
stars = "*"
# Height must be > 0 and < 23
if (rows > 23 or rows<0):
    print("Height must be greater than 0 and less than 23")
else:
	# print space rows and stars rows
    for i in range(rows):
        stars+="*"
        print(" "*((rows+1)-stars.count("*"))+stars)