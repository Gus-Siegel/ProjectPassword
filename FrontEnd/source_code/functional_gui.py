import tkinter as tk
from pynput import keyboard
import time

# Keypress recording functionality
keypress_data = []

def on_key_press(key):
    try:
        current_time = time.time()
        keypress_data.append([key.char, current_time])
    except AttributeError:
        pass

def on_key_release(key):
    if key == keyboard.Key.enter:
        return False

keyboard_listener = keyboard.Listener(on_press=on_key_press, on_release=on_key_release)
keyboard_listener.start()

# Create the main window
root = tk.Tk()
root.title("TypeLock")
root.geometry("500x350")

# Set the window color
root.configure(bg="#1F1F1F")

# Create the TypeLock logo
logo_image = tk.PhotoImage(file="FrontEnd/logo.png")
logo_label = tk.Label(root, image=logo_image, bg="#1F1F1F")
logo_label.pack(pady=10)

# Create the instructions label
instructions_label = tk.Label(root, text="Passphrase:", font=("Nunito", 16), fg="#FFFFFF", bg="#1F1F1F")
instructions_label.pack()

# Generate a random sentence for the passphrase
words = ['hello', 'world']
passphrase = ' '.join(words)

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
    print("Keypress data:", keypress_data)
    keyboard_listener.stop()    

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
