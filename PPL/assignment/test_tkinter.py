import tkinter as tk

def test_tkinter():
    try:
        root = tk.Tk()
        root.title("Tkinter Test")
        label = tk.Label(root, text="Tkinter is installed correctly!")
        label.pack(padx=20, pady=20)
        root.after(2000, root.destroy)  # Close the window after 2 seconds
        root.mainloop()
        print("Tkinter is available.")
    except tk.TclError as e:
        print(f"An error occurred: {e}")
        print("Tkinter is not available or not configured correctly.")

if __name__ == "__main__":
    test_tkinter()
