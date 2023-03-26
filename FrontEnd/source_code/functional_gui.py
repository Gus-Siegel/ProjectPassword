import tkinter as tk
import time

# Initialize the list of lists to store the keypress data
keypress_data = []

# Log the character entered by the user and the time it was pressed
def log_key_press(event):
    # Record the current time (in seconds)
    current_time = time.time()
    # Append the key event name (letter) and the time it was pressed
    keypress_data.append([event.char, current_time])

# Create the main window of the gui
root = tk.Tk()
root.title("TypeLock")
root.geometry("500x425")

# Set the window color
root.configure(bg="#1F1F1F")

# Create the TypeLock logo
logo_image = tk.PhotoImage(file="FrontEnd/logo.png")
logo_label = tk.Label(root, image=logo_image, bg="#1F1F1F")
logo_label.pack()

# Create and format the username label
username_label = tk.Label(root,text="Username:",
                                font=("Nunito", 16),
                                fg="#FFFFFF",
                                bg="#1F1F1F")
username_label.pack(pady=(10, 0))

# Create and format the username entry box
username_entry_box = tk.Entry(root, width=20,
                                    font=("Nunito", 16),
                                    bg="#FFFFFF",
                                    fg="#1F1F1F",
                                    insertbackground="#FFFFFF")
username_entry_box.pack(pady=(0, 10))

# Create and format the passphrase label
passphrase_label = tk.Label(root, text="Passphrase:",
                                    font=("Nunito", 16),
                                    fg="#FFFFFF",
                                    bg="#1F1F1F")
passphrase_label.pack(pady=(10, 0))

# Generate the passphrase from the list of possible words
possible_words = ['hello', 'world']
passphrase = ' '.join(possible_words)

# Display the passphrase
passphrase_text_label = tk.Label(root, text=f"{passphrase}",
                                        font=("Nunito", 16, "bold"),
                                        fg="#FFFFFF", bg="#1F1F1F")
passphrase_text_label.pack(pady=(0, 10))

# Create and format the passphrase instructions label
passphrase_instructions__label = tk.Label(root,
                                            text="Type the passphrase below:",
                                            font=("Nunito", 16),
                                            fg="#FFFFFF",
                                            bg="#1F1F1F")
passphrase_instructions__label.pack(pady=(5, 0))

# Create and format the passphrase entry box
passphrase_entry_box = tk.Entry(root, width=20,
                                        font=("Nunito", 16),
                                        bg="#FFFFFF",
                                        fg="#1F1F1F",
                                        insertbackground="#FFFFFF")
passphrase_entry_box.pack(pady=(0, 10))

# Record the data entered inside the password entry box
passphrase_entry_box.bind("<KeyPress>", log_key_press)

# Login the user and ouput the data entered
def login_user():
    username_entered = username_entry_box.get()
    passphrase_entered = passphrase_entry_box.get()
    print(f"Username Entered: {username_entered}")
    print(f"Passphrase Entered: {passphrase_entered}")
    print("Keypress data:", keypress_data)

# Create the login button
def login():
    password = password_entry.get()
    print(f"Passphrase Entered: {password}")
    print("Keypress data:", keypress_data)
    keyboard_listener.stop()

login_button = tk.Button(root, text="Login", font=("Nunito", 16), bg="#000000", fg="#1F1F1F", command=login)
login_button.pack(pady=20)

# Clear the text from the username and passphrase entry boxes
def clear_text():
    username_entry_box.delete(0, tk.END)
    passphrase_entry_box.delete(0, tk.END)

# Create the clear button
clear_button = tk.Button(root, text="Clear",
                                font=("Nunito", 16),
                                bg="#000000",
                                fg="#1F1F1F",
                                command=clear_text)
clear_button.pack(pady=0)

# Start the GUI event loop
root.mainloop()
