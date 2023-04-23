import tkinter as tk
import time
import os
from typelock_clientv3 import Signup, Login  #Connection to the Client Program

# Initialize the list of lists to store the keypress data
keypress_data = []


# Log the character entered by the user and the time it was pressed
def log_key_press(event):
    # Record the current time (in seconds)
    current_time = time.time()
    # Append the key event name (letter) and the time it was pressed
    keypress_data.append([event.char, current_time])


class TypeLock(tk.Tk):
    def __init__(self, *args, **kwargs):
        tk.Tk.__init__(self, *args, **kwargs)

        container = tk.Frame(self)
        container.pack(side="top", fill="both", expand=True)
        container.grid_rowconfigure(0, weight=1)
        container.grid_columnconfigure(0, weight=1)

        self.frames = {}
        for F in (GetStartedPage, LoginPage, SignUpPage, LoginSuccessPage,
                  LoginFailurePage, SignUpFailurePage):
            frame = F(container, self)
            self.frames[F] = frame
            frame.grid(row=0, column=0, sticky="nsew")

        self.show_frame(GetStartedPage)

    def show_frame(self, cont):
        frame = self.frames[cont]
        frame.tkraise()


class GetStartedPage(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        self.configure(bg="#1F1F1F")
        self.controller = controller

        image_path = os.path.join(os.getcwd(), "logo.png")

        logo_image = tk.PhotoImage(file=image_path)
        logo_label = tk.Label(self, image=logo_image, bg="#1F1F1F")
        logo_label.image = logo_image
        logo_label.pack(pady=10)

        # Create and format the welcome label
        welcome_label = tk.Label(self, text="Welcome to TypeLock",
                                  font=("Nunito", 18),
                                  fg="#FFFFFF",
                                  bg="#1F1F1F")
        welcome_label.pack(pady=(10, 5))

        # Create and format the "user new?" label
        new_user_label = tk.Label(self, text="Don't have an account?",
                                  font=("Nunito", 16),
                                  fg="#FFFFFF",
                                  bg="#1F1F1F")
        new_user_label.pack(anchor=tk.W, pady=(10, 0), padx=179)

        # Create the signup button and redirect to the signup page
        signup_button = tk.Button(self, width=20,
                                  text="Sign Up",
                                  font=("Nunito", 16),
                                  bg="#FFFFFF",
                                  fg="#1F1F1F",
                                  command=lambda: controller.
                                  show_frame(SignUpPage))
        signup_button.pack(pady=(0, 10))

        # Create and format the "Have an account?" label
        existing_user_label = tk.Label(self, text="Have an account?",
                                  font=("Nunito", 16),
                                  fg="#FFFFFF",
                                  bg="#1F1F1F")
        existing_user_label.pack(anchor=tk.W, pady=(10, 0), padx=179)

        # Create the login button and redirect to the login page
        login_button = tk.Button(self, width=20,
                                 text="Login",
                                 font=("Nunito", 16),
                                 bg="#FFFFFF",
                                 fg="#1F1F1F",
                                 command=lambda: controller.
                                 show_frame(LoginPage))
        login_button.pack(pady=(0, 10))


class LoginPage(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        self.configure(bg="#1F1F1F")
        self.controller = controller

        logo_image = tk.PhotoImage(file="logo.png")
        logo_label = tk.Label(self, image=logo_image, bg="#1F1F1F")
        logo_label.image = logo_image
        logo_label.pack(pady=10)

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

        # Create and format the LOGIN label
        login_label = tk.Label(self, text="Login",
                                  font=("Nunito", 18),
                                  fg="#FFFFFF",
                                  bg="#1F1F1F")
        login_label.pack(pady=(10, 5))

        # Create and format the username label
        username_label = tk.Label(self, text="Username",
                                  font=("Nunito", 16),
                                  fg="#FFFFFF",
                                  bg="#1F1F1F")
        username_label.pack(anchor=tk.W, pady=(10, 0), padx=191)

        # Create and format the username entry box with placeholder text
        username_placeholder = "Type your username"
        username_entry_box = tk.Entry(self, width=20,
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
        passphrase_label = tk.Label(self, text="Passphrase",
                                    font=("Nunito", 16),
                                    fg="#FFFFFF",
                                    bg="#1F1F1F")
        passphrase_label.pack(pady=(10, 0))

        # Create the passphrase
        passphrase = "hello world"

        # Display the passphrase
        passphrase_text_label = tk.Label(self, text=f"{passphrase}",
                                         font=("Nunito", 16, "bold"),
                                         fg="#FFFFFF", bg="#1F1F1F")
        passphrase_text_label.pack(pady=(0, 10))

        # Create and format the passphrase entry box with placeholder text
        passphrase_placeholder = "Type the passphrase"
        passphrase_entry_box = tk.Entry(self, width=20,
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

            # Call client and send data; Login needs to return result
            login = Login(keypress_data, username_entered, passphrase)

            # Get success/fail value from client
            login_result = login.user_login()

            print("Login value: " + str(login_result))

            # Check if the login was successful
            if login_result:
                # Redirect to the Success Page
                controller.show_frame(LoginSuccessPage)
            # Otherwise, assume the login wasn't successful
            else:
                # Redirect to the Failure Page
                controller.show_frame(LoginFailurePage)

            # Clear and reset the information
            clear_and_reset()

        # Create the login button
        login_button = tk.Button(self, width=10,
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
            show_placeholder(None, passphrase_entry_box,
                             passphrase_placeholder)

        # Create the clear button
        clear_button = tk.Button(self, width=10,
                                 text="Clear",
                                 font=("Nunito", 16),
                                 bg="#000000",
                                 fg="#1F1F1F",
                                 command=clear_and_reset)
        clear_button.pack(pady=0)

        back_button = tk.Button(self, width=10,
                                text="Back",
                                font=("Nunito", 16),
                                bg="#000000",
                                fg="#1F1F1F",
                                command=lambda: controller.
                                show_frame(GetStartedPage))
        back_button.pack(pady=20)


class LoginSuccessPage(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        self.configure(bg="#1F1F1F")
        self.controller = controller

        logo_image = tk.PhotoImage(file="logo.png")
        logo_label = tk.Label(self, image=logo_image, bg="#1F1F1F")
        logo_label.image = logo_image
        logo_label.pack(pady=10)

        # Display successful login message
        success_message = tk.Label(self, text="""Authentication Sucessful""",
                                   font=("Nunito", 16),
                                   fg="#FFFFFF",
                                   bg="#1F1F1F")
        success_message.pack(anchor=tk.W, pady=(10, 0), padx=191)


class LoginFailurePage(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        self.configure(bg="#1F1F1F")
        self.controller = controller

        logo_image = tk.PhotoImage(file="logo.png")
        logo_label = tk.Label(self, image=logo_image, bg="#1F1F1F")
        logo_label.image = logo_image
        logo_label.pack(pady=10)

        # Display failed login message
        failure_message = tk.Label(self, text="""Authentication Failed""",
                                   font=("Nunito", 16),
                                   fg="#FFFFFF",
                                   bg="#1F1F1F")
        failure_message.pack(pady=(10, 0))

        try_again_button = tk.Button(self, width=10,
                                text="Try Again",
                                font=("Nunito", 16),
                                bg="#000000",
                                fg="#1F1F1F",
                                command=lambda: controller.
                                show_frame(LoginPage))
        try_again_button.pack(pady=20)


class SignUpPage(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        self.configure(bg="#1F1F1F")
        self.controller = controller

        logo_image = tk.PhotoImage(file="logo.png")
        logo_label = tk.Label(self, image=logo_image, bg="#1F1F1F")
        logo_label.image = logo_image
        logo_label.pack(pady=10)

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

        # Create and format the sign_up_label label
        sign_up_label = tk.Label(self, text="Create an Account",
                                  font=("Nunito", 18),
                                  fg="#FFFFFF",
                                  bg="#1F1F1F")
        sign_up_label.pack(pady=(10, 5))

        # Create and format the name label
        name_label = tk.Label(self, text="Name",
                              font=("Nunito", 16),
                              fg="#FFFFFF",
                              bg="#1F1F1F")
        name_label.pack(anchor=tk.W, pady=(10, 0), padx=191)

        # Create and format the name entry box with placeholder text
        name_placeholder = "Type your name"
        name_entry_box = tk.Entry(self, width=20,
                                  font=("Nunito", 16),
                                  bg="#FFFFFF",
                                  fg="#808080",
                                  insertbackground="#FFFFFF")
        name_entry_box.insert(0, name_placeholder)
        name_entry_box.bind("<FocusIn>",
                            lambda event: hide_placeholder(
                                event,
                                name_entry_box,
                                name_placeholder))
        name_entry_box.bind("<FocusOut>",
                            lambda event: show_placeholder(
                                event,
                                name_entry_box,
                                name_placeholder))
        name_entry_box.pack(pady=(0, 10))

        # Create and format the username label
        username_label = tk.Label(self, text="Username",
                                  font=("Nunito", 16),
                                  fg="#FFFFFF",
                                  bg="#1F1F1F")
        username_label.pack(anchor=tk.W, pady=(10, 0), padx=191)

        # Create and format the username entry box with placeholder text
        username_placeholder = "Type your username"
        username_entry_box = tk.Entry(self, width=20,
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

        practice_label = tk.Label(self, text="Practice Field",
                                  font=("Nunito", 16),
                                  fg="#FFFFFF",
                                  bg="#1F1F1F")
        practice_label.pack(anchor=tk.W, pady=(10, 0), padx=191)

        practice_placeholder = "Practice typing passphrase"
        practice_box = tk.Entry(self, width=20,
                                font=("Nunito", 16),
                                bg="#FFFFFF",
                                fg="#808080",
                                insertbackground="#FFFFFF")
        practice_box.insert(0, practice_placeholder)
        practice_box.bind("<FocusIn>",
                          lambda event: hide_placeholder(
                              event,
                              practice_box,
                              practice_placeholder))
        practice_box.bind("<FocusOut>",
                          lambda event: show_placeholder(
                              event,
                              practice_box,
                              practice_placeholder))
        practice_box.pack(pady=(0, 10))

        # Create and format the passphrase label
        passphrase_label = tk.Label(self, text="Passphrase",
                                    font=("Nunito", 16),
                                    fg="#FFFFFF",
                                    bg="#1F1F1F")
        passphrase_label.pack(pady=(10, 0))

        # Create the passphrase
        passphrase = "hello world"

        # Display the passphrase
        passphrase_text_label = tk.Label(self, text=f"{passphrase}",
                                         font=("Nunito", 16, "bold"),
                                         fg="#FFFFFF", bg="#1F1F1F")
        passphrase_text_label.pack(pady=(0, 10))

        # Create and format the passphrase entry box with placeholder text
        passphrase_placeholder = "Type the passphrase"
        passphrase_entry_box = tk.Entry(self, width=20,
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

        # Sign up the user and output the data entered
        def sign_up_user():
            name_entered = name_entry_box.get()
            username_entered = username_entry_box.get()
            passphrase_entered = passphrase_entry_box.get()
            print(f"Name Entered: {name_entered}")
            print(f"New Username Entered: {username_entered}")
            print(f"Passphrase Entered: {passphrase_entered}")
            print("Keypress data:", keypress_data)

            # Call client and send data; Sign up needs to return result
            signup = Signup(keypress_data, name_entered, username_entered,
                            passphrase)

            # Get success/fail value from client
            signup_result = signup.user_signup()

            # Check if the sign up was successful
            if signup_result:
                # Redirect to the Login Page
                controller.showframe(LoginPage)
            # Otherwise, assume the sign up wasn't successful
            else:
                # Prompt the user to try again
                controller.showframe(SignUpFailurePage)

            print(f"Signup value:  {signup}")

            # Clear and reset the information
            clear_and_reset()

        # Create the sign up button
        sign_up_button = tk.Button(self, width=10,
                                   text="Sign Up",
                                   font=("Nunito", 16),
                                   bg="#000000",
                                   fg="#1F1F1F",
                                   command=sign_up_user)
        sign_up_button.pack(pady=20)

        # Clear the text from the name, username and passphrase entry boxes
        # and reset
        def clear_and_reset():
            global keypress_data

            # Unbind the key press event from the passphrase entry box
            passphrase_entry_box.unbind("<KeyPress>")

            # Clear the text from the name, username and passphrase entry boxes
            name_entry_box.delete(0, tk.END)
            username_entry_box.delete(0, tk.END)
            passphrase_entry_box.delete(0, tk.END)
            practice_box.delete(0, tk.END)

            # Reset the keypress_data list
            keypress_data = []

            # Bind the key press event to the passphrase entry box again
            passphrase_entry_box.bind("<KeyPress>", log_key_press)

            # Reset placeholders
            show_placeholder(None, username_entry_box, username_placeholder)
            show_placeholder(None, username_entry_box, username_placeholder)
            show_placeholder(None, passphrase_entry_box,
                             passphrase_placeholder)

        # Create the clear button
        clear_button = tk.Button(self, width=10,
                                 text="Clear",
                                 font=("Nunito", 16),
                                 bg="#000000",
                                 fg="#1F1F1F",
                                 command=clear_and_reset)
        clear_button.pack(pady=0)

        back_button = tk.Button(self, width=10,
                                text="Back",
                                font=("Nunito", 16),
                                bg="#000000",
                                fg="#1F1F1F",
                                command=lambda: controller.
                                show_frame(GetStartedPage))
        back_button.pack(pady=20)


class SignUpFailurePage(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        self.configure(bg="#1F1F1F")
        self.controller = controller

        logo_image = tk.PhotoImage(file="logo.png")
        logo_label = tk.Label(self, image=logo_image, bg="#1F1F1F")
        logo_label.image = logo_image
        logo_label.pack(pady=10)

        failure_message = tk.Label(self, text="""Sign up Unsuccessful""",
                                   font=("Nunito", 16),
                                   fg="#FFFFFF",
                                   bg="#1F1F1F")
        failure_message.pack(pady=(10, 0))

        try_again_button = tk.Button(self, width=10,
                                text="Try Again",
                                font=("Nunito", 16),
                                bg="#000000",
                                fg="#1F1F1F",
                                command=lambda: controller.
                                show_frame(LoginPage))
        try_again_button.pack(pady=20)

app = TypeLock()
app.title("TypeLock")
app.geometry("600x700")
app.configure
app.mainloop()
