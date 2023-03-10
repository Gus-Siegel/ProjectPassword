import tkinter as tk
import random

# Create the main window
root = tk.Tk()
root.title("TypeLock")
root.geometry("500x300")

# Set the window color
root.configure(bg="#1F1F1F")

# Create the TypeLock logo
logo_image = tk.PhotoImage(file="logo.png")
logo_label = tk.Label(root, image=logo_image, bg="#1F1F1F")
logo_label.pack(pady=10)

# Create the instructions label
instructions_label = tk.Label(root, text="Passphrase:", font=("Nunito", 16), fg="#FFFFFF", bg="#1F1F1F")
instructions_label.pack()

# Generate a random sentence for the passphrase
words = ['The', 'quick', 'brown', 'fox', 'jumps', 'over', 'the', 'lazy', 'dog']
passphrase = ' '.join(random.choices(words, k=5))

# Create the passphrase label
passphrase_label = tk.Label(root, text=f"{passphrase}", font=("Nunito", 16, "bold"), fg="#FFFFFF", bg="#1F1F1F")
passphrase_label.pack()

# Create the password label and entry box
password_label = tk.Label(root, text="Type the passphrase below:", font=("Nunito", 16), fg="#FFFFFF", bg="#1F1F1F")
password_label.pack(pady=10)
password_entry = tk.Entry(root, width=20, font=("Nunito", 16), bg="#FFFFFF", fg="#1F1F1F", insertbackground="#FFFFFF")
password_entry.pack()

# Create the login button
def login():
    password = password_entry.get()
    print(f"Passphrase Entered: {password}")

login_button = tk.Button(root, text="Login", font=("Nunito", 16), bg="#000000", fg="#1F1F1F", command=login)
login_button.pack(pady=20)

# Create the clear button function
def clear_password():
    password_entry.delete(0, tk.END)

# Create the clear button
clear_button = tk.Button(root, text="Clear", font=("Nunito", 16), bg="#000000", fg="#1F1F1F", command=clear_password)
clear_button.pack(pady=0)

# Start the GUI event loop
root.mainloop()
