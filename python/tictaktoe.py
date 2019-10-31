def end():
    print("Do you want play again!\npess 1 for yes, otherwise anynumber")
    z=int(input())
    if z==1:
        tik()
    else:
        print("Good Bye!")
print("Do you want play TIK TAK TOE game!")
print("Press 1 for yes, otherwise anynumber")
n=int(input())
if n==1:
    def tik():
        flag=True
        while flag:
            print("Welcome in TIK TAK TOE game")
            print("see all position!")
            def disp(board):
                print(" -------------")
                print(' | '+board[0]+' | '+board[1]+' | '+board[2]+' | ')
                print(" -------------")
                print(' | '+board[3]+' | '+board[4]+' | '+board[5]+' | ')
                print(" -------------")
                print(' | '+board[6]+' | '+board[7]+' | '+board[8]+' | ')
                print(" -------------")
            num=['1','2','3','4','5','6','7','8','9']
            disp(num)
            t=True
            while t:
                print("Player1: Select x or o")
                s1=input()
                if s1=="x":
                    s2="o"
                    t=False
                elif s1=="o":
                    s2="x"
                    t=False
                else:
                    print("Please Choose correct option!")
                    t=True
            while flag:
                print("Player1: Enter the position")
                def player(s1):
                    n1=int(input())
                    if n1<=9:
                        if num[n1-1]!="x" and num[n1-1]!="o":
                            num[n1-1]=s1
                            disp(num)
                        else:
                            print("choose right place")
                            player(s1)
                    else:
                        print("Please Choose number less than 10")
                        player(s1)
                player(s1)
                def check(num):
                    mylist=[(num[0],num[1],num[2]),(num[3],num[4],num[5]),(num[6],num[7],num[8]),(num[0],num[3],num[6]),(num[1],num[4],num[7]),(num[2],num[5],num[8]),(num[0],num[4],num[8]),(num[2],num[4],num[6])]
                    win=0
                    for c in mylist:
                        for z in c:
                            if z=="x":
                                win+=1
                            else:
                                win=0
                                break
                        if win==3 and s1=="x":
                            print("Player1 won the match")
                            win=0
                            end()
                        elif win==3 and s1=="o":
                            print("Player2 won the match")
                            win=0
                            end()
                    for c in mylist:
                        for z in c:
                            if z=="o":
                                win+=1
                            else:
                                win=0
                                break
                        if win==3 and s1=="o":
                            print("Player1 won the match")
                            win=0
                            end()
                        elif win==3 and s1=="x":
                            print("Player2 won the match")
                            win=0
                            end()
                    for ch in range(0,9):
                        if num[ch]=="x" or num[ch]=="o":
                            win+=1
                    if win>8:
                        print("Game Over!")
                        end()
                    else:
                        win=0
                check(num)
                print("Player2: Enter the position")
                player(s2)
                check(num)
    tik()
else:
    print("Outside from game!")