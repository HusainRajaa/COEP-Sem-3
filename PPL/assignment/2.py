from tkinter import *


def Addition():
    try : 
        val1= int(entry1.get())
        val2 = int(entry2.get())

        Message(root, text=f"Sum is {val1 + val2}").grid(row=3,column=0,)
    except (ValueError) as e:
        print("Error : " + str(e))




root = Tk()
Label(root, text="Enter first number").grid(row=0,column=0)
entry1 = Entry(root)
entry1.grid(row=0,column=1)


Label(root, text="Enter second number").grid(row=1,column=0)
entry2 = Entry(root)
entry2.grid(row=1,column=1)


Button(root, text= "add", command=Addition).grid(row=2,column=0)


root.mainloop()
    


