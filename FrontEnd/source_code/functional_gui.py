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
root.geometry("500x400")

# Set the window color
root.configure(bg="#1F1F1F")

# Create the TypeLock logo
logo_image = tk.PhotoImage(file="logo.png")
logo_label = tk.Label(root, image=logo_image, bg="#1F1F1F")
logo_label.pack()

# Show the placeholder text for the entry boxes
def show_placeholder(event, entry, placeholder):
    if entry.get() == '':
        entry.insert(0, placeholder)
        entry.configure(fg="#808080")

# Hide the placeholder text for the entry boxes
def hide_placeholder(event, entry, placeholder):
    if entry.get() == placeholder:
        entry.delete(0, tk.END)
        entry.configure(fg="#1F1F1F")

# Create and format the username label
username_label = tk.Label(root,text="Username",
                                font=("Nunito", 16),
                                fg="#FFFFFF",
                                bg="#1F1F1F")
username_label.pack(pady=(10, 0))

# Create and format the username entry box with placeholder text
username_placeholder = "Type your username"
username_entry_box = tk.Entry(root, width=20,
                                font=("Nunito", 16),
                                bg="#FFFFFF",
                                fg="#808080",
                                insertbackground="#FFFFFF")
username_entry_box.insert(0, username_placeholder)
username_entry_box.bind("<FocusIn>",
                        lambda event: hide_placeholder(
                            event,
                            username_entry_box,
                            username_placeholder))
username_entry_box.bind("<FocusOut>",
                        lambda event: show_placeholder(
                            event,
                            username_entry_box,
                            username_placeholder))
username_entry_box.pack(pady=(0, 10))

# Create and format the passphrase label
passphrase_label = tk.Label(root, text="Passphrase",
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


# Create and format the passphrase entry box with placeholder text
passphrase_placeholder = "Type the passphrase"
passphrase_entry_box = tk.Entry(root, width=20,
                                font=("Nunito", 16),
                                bg="#FFFFFF",
                                fg="#808080",
                                insertbackground="#FFFFFF")
passphrase_entry_box.insert(0, passphrase_placeholder)
passphrase_entry_box.bind("<FocusIn>",
                            lambda event: hide_placeholder(
                                event,
                                passphrase_entry_box,
                                passphrase_placeholder))
passphrase_entry_box.bind("<FocusOut>",
                            lambda event: show_placeholder(
                                event,
                                passphrase_entry_box,
                                passphrase_placeholder))
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
login_button = tk.Button(root, width=10,
                                text="Login",
                                font=("Nunito", 16),
                                bg="#000000",
                                fg="#1F1F1F",
                                command=login_user)
login_button.pack(pady=20)

# Clear the text from the username and passphrase entry boxes and reset
def clear_and_reset():
    global keypress_data

    # Unbind the key press event from the passphrase entry box
    passphrase_entry_box.unbind("<KeyPress>")

    # Clear the text from the username and passphrase entry boxes
    username_entry_box.delete(0, tk.END)
    passphrase_entry_box.delete(0, tk.END)

    # Reset the keypress_data list
    keypress_data = []

    # Bind the key press event to the passphrase entry box again
    passphrase_entry_box.bind("<KeyPress>", log_key_press)

    # Reset placeholders
    show_placeholder(None, username_entry_box, username_placeholder)
    show_placeholder(None, passphrase_entry_box, passphrase_placeholder)

# Create the clear button
clear_button = tk.Button(root, width=10,
                            text="Clear",
                            font=("Nunito", 16),
                            bg="#000000",
                            fg="#1F1F1F",
                            command=clear_and_reset)
clear_button.pack(pady=0)

# Start the GUI event loop
root.mainloop()
