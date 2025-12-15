import tkinter as tk
from tkinter import messagebox

expression = ""

def btn_click(item):
    global expression
    expression += str(item)
    input_text.set(expression)

def btn_clear(event=None):
    global expression
    expression = ""
    input_text.set("")

def btn_delete(event=None):
    global expression
    expression = expression[:-1]
    input_text.set(expression)

def btn_equal(event=None):
    #Exception Handling
    global expression
    try:
        result = str(eval(expression))
        input_text.set(result)
        expression = result
    except ZeroDivisionError:
        messagebox.showerror("Error", "Cannot divide by zero")
        expression = ""
    except:
        messagebox.showerror("Error", "Invalid Input")
        expression = ""

root = tk.Tk()
root.title("CALCULATOR")
root.geometry("400x500")
root.resizable(False, False)

input_text = tk.StringVar()

input_frame = tk.Frame(root, bd=2, relief="ridge")
input_frame.pack(side="top", fill="x")

input_field = tk.Entry(input_frame, font=("Arial", 20), textvariable=input_text, bd=2,
                       relief="sunken", justify="right")
input_field.pack(ipady=15, fill="x")

btns_frame = tk.Frame(root, bd=2, relief="ridge")
btns_frame.pack(fill="both", expand=True)

tk.Button(btns_frame, text="Clear", width=32, height=2, bd=1,
          command=btn_clear).grid(row=0, column=0, columnspan=3, padx=1, pady=1)

tk.Button(btns_frame, text="/", width=10, height=2, bd=1,
          command=lambda: btn_click("/")).grid(row=0, column=3, padx=1, pady=1)

buttons = [
    ("7", 1, 0), ("8", 1, 1), ("9", 1, 2), ("*", 1, 3),
    ("4", 2, 0), ("5", 2, 1), ("6", 2, 2), ("-", 2, 3),
    ("1", 3, 0), ("2", 3, 1), ("3", 3, 2), ("+", 3, 3),
    (".", 4, 1), ("=", 4, 3)
]

for (text, row, col) in buttons:
    if text == "=":
        tk.Button(btns_frame, text=text, width=10, height=2, bd=1,
                  command=btn_equal).grid(row=row, column=col, padx=1, pady=1)
    else:
        tk.Button(btns_frame, text=text, width=10, height=2, bd=1,
                  command=lambda x=text: btn_click(x)).grid(row=row, column=col, padx=1, pady=1)

tk.Button(btns_frame, text="0", width=21, height=2, bd=1,
          command=lambda: btn_click("0")).grid(row=4, column=0, columnspan=2, padx=1, pady=1)

root.bind("<Key>", lambda event: btn_click(event.char) if event.char in '0123456789+-*/.' else None)
root.bind("<Return>", btn_equal)
root.bind("<BackSpace>", btn_delete)
root.bind("<Escape>", btn_clear)

root.mainloop()
