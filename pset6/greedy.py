import cs50
coins = cs50.get_float()*100
change = 0
while (coins<0):
    print("Coins must be positive!")
    coins = cs50.get_float()*100
while coins:
    if (coins - 25) >= 0:
        coins -= 25
        change+=1
    elif (coins - 10) >= 0:
        coins -= 10
        change+=1
    elif (coins - 5) >= 0:
        coins -= 5
        change+=1    
    elif (coins - 1) >= 0:
        coins -= 1
        change+=1
print (change)