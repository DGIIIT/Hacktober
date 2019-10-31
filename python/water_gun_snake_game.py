import random
y=0
d=0
com=0
def lt():
    lst = ["snake","gun","water"]
    a=random.choice(lst)
    return a
for t in range(10):
    a = lt()
    x = input("s for Snake\nw for Water\ng for gun\nChoose one of them : ")
    print(f"Computer choose : {a}")
    if x == "s" and a == "gun":
        print("Computer won the game!")
        com+=1
    elif x == "g" and a == "snake":
        print("you won the game!")
        y+=1
    elif x == "g" and a == "water":
        print("Computer won the game!")
        com+=1
    elif x == "w" and a == "gun":
        print("you won the game!")
        y+=1
    elif x=="s" and a=="water":
        print("you won the game!")
        y+=1
    elif x== "w" and a=="snake":
        print("Computer won the game!")
        com+=1
    else:
        print("Draw")
        d+=1
print("\nREsult:")
print(f"Computer won the {com} game in 10 games")
print(f"You won the {y} game in 10 games")
print(f"{d} game Draw in 10 games")
if com>y:
    print("Computer is Winner!")
else:
    print("You are Winner!")