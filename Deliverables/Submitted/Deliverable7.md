# D.7 V&V

Group 04 – “TypeLock”\
Date: May 3, 2023\
Location: Flagstaff, Arizona\
Group Members: Taylor Nielsen, Eduardo De La Rosa, Alexander Siegel, Brock Heinz, Levi Watlington, Michael Vertin

## Description

As internet usage diversifies and expands, many users face the challenge of remembering multiple passwords for their various accounts, leading to time-consuming processes and compromised security. TypeLock is a secure account login system designed to address this issue by employing typing metrics, such as speed and accuracy, to identify users without relying on traditional passwords. Instead of necessitating the precise memorization and entry of distinct short passwords, TypeLock utilizes the user's ability to type a previously seen phrase or paragraph, identifying them through their unique typing metrics. This method streamlines the login process, enabling users to access their accounts without the burden of memorizing multiple passwords or sifting through a password list or file, as their typing metrics serve as a unique identifier. TypeLock is an ideal solution for those struggling to remember passwords and seeking a more secure and convenient way to access their online accounts.

The primary objective of the system is to establish a secure, reliable, and user-friendly login process that enhances account security. To achieve this, the system accurately and efficiently identifies users based on typing metrics like speed and accuracy, while also facilitating easy setup and management of typing style datasets. The system comprises three main components: Back-end, Front-end, and Client-Server relationship. The Back-end employs algorithms to accurately identify users by their typing style, ensuring secure account access and preventing unauthorized entry. The Back-end's algorithm compares two lists of keypresses along with their associated timings, identifying spelling errors and calculating the ratio of average time delay differences. Constants are employed to determine if the input matches the user's recorded typing style. The Front-end focuses on user interface design, creating a reference passphrase for users to enter and implementing the algorithm to capture user input for processing. The Client and Server act as the central elements that integrate the Front-end design and data with the Back-end algorithm. Notably, the Front-end is developed in Python, while the Back-end uses C++. The primary distinction between these languages is their approach to endianness. Both Python and C++ store integers based on the endianness of the processor running the program. To avoid issues when passing data between end hosts with different endian storage systems, conversions are performed on the client and server sides before transferring information through the Client-Server connection.

## Verification (tests)

### Unit test

- The test framework **Gtest** was used to develop the automated unit tests.

- Link to folder: [Automated unit tests](https://github.com/Gus-Siegel/ProjectPassword/tree/main/Current_Release/BackEndServer)

- The [database](https://github.com/Gus-Siegel/ProjectPassword/blob/main/Current_Release/BackEndServer/mockTestWithServer.cpp) class is being tested [using a DatabaseMock](https://github.com/Gus-Siegel/ProjectPassword/blob/main/Current_Release/BackEndServer/mockTestWithServer.cpp).\
![Class Code](https://cdn.discordapp.com/attachments/856622349516144665/1103493888615923752/image.png)

- Automated unit test execution results:\
![Execution Results](https://cdn.discordapp.com/attachments/856622349516144665/1103494402497859644/image.png)

### Acceptance test

- The test framework **Unittest**, a Python testing library, was used to develop the automated acceptance tests.

- Link to folder: [Automated acceptance tests](https://github.com/Gus-Siegel/ProjectPassword/tree/main/Current_Release/FrontEndClient)

- The automated acceptance test performs 3 different tests. The first is a signup test to make sure that we can add a new user. The second test, tests that the user can log in as seen in the [LoginTest](https://github.com/Gus-Siegel/ProjectPassword/blob/main/Current_Release/FrontEndClient/acceptanceTestTypelock) class below. The third test checks that the user will not be able to sign in if the speed of the passphrase is incorrect. The fourth test checks for a fail if the passphrase has spellcheck mistakes that are abnormal to the user. Each of these tests modifies the user entries and connects to the server, testing the clinet/server connection as well as the algorithm.\
![Class Code](https://cdn.discordapp.com/attachments/1103515433862172673/1103517277489483816/acceptanceTestExample.jpg)

- Automated acceptance test execution results:\
![AcceptanceTestResults](https://github.com/Gus-Siegel/ProjectPassword/blob/main/Deliverables/Submitted/AcceptanceTest.png)

## Validation (user evaluation)

### Script

**Tasks for the user:**

- Navigate to sign up page
- Follow sign up procedure
- Follow login procedure

**Interview questions for the user:**

- What do you think of the product?
- Do you prefer the biometric login to regular password login?
- How easy was it to navigate through the product?
- Was it clear to you what you had to do in each section?
- If it wasn’t clear enough what would you suggest we add to fix that?
- Did you encounter any problems with the product? If so, how did you encounter them?
- Is the aesthetics of our product good? If not then why do you think so?
- How does the product compare to other sign up and login systems?
- Overall, what did you think of the product?
- Do you have anything that you would like to add?

### Results

**User 1:**

- What do you think of the product?
  - Looks interesting enough to continue work.
- Do you prefer the biometric login to regular password login?
  - No.
- How easy was it to navigate through the product?
  - It was intuitive to use. 
- Was it clear to you what you had to do in each section?
  - It was expect for the "practice field".
- If it wasn’t clear enough what would you suggest we add to fix that?
  - Maybe put optional somewhere on there.
- Did you encounter any problems with the product? If so, how did you encounter them?
  - No problems, everything seemed to work.
- Is the aesthetics of our product good? If not then why do you think so?
  - It had a clean look to it. I liked how it looked.
- How does the product compare to other sign up and login systems?
  - Easier, but without knowing the magic behind the scenes I don't trust it.
- Overall, what did you think of the product?
  - Intresting and worth keeping an eye on.
- Do you have anything that you would like to add?
  - N/A

**User 2:**

- What do you think of the product?
  - Could be integrated into other products.
- Do you prefer the biometric login to regular password login?
  - Regular is comfy to use, but this could grow on me.
- How easy was it to navigate through the product?
  - Fairly easy, I was confused going between signing up and logging in.
- Was it clear to you what you had to do in each section?
  - Yes, the practice field was a bit strange to include, but after attempting to log in it made more sense.
- If it wasn’t clear enough what would you suggest we add to fix that?
  - N/A
- Did you encounter any problems with the product? If so, how did you encounter them?
  - I purposefully typed like a psycopath to test if it works. Turns out it does and now I cannot access that account.
- Is the aesthetics of our product good? If not then why do you think so?
  - I liked it. It looked really clean.
- How does the product compare to other sign up and login systems?
  - Its much easier to login on your system than other systems.
- Overall, what did you think of the product?
  - I liked it, once my account was sset up properly I was able to easily login.
- Do you have anything that you would like to add?
  - A way to reset the password. 

**User 3:**

- What do you think of the product?
  - Honestly interesting but doesn't seem to be useful.
- Do you prefer the biometric login to regular password login?
  - Regular passwords work just fine.
- How easy was it to navigate through the product?
  - Easy to use, no complaints from me.
- Was it clear to you what you had to do in each section?
  - Yes.
- If it wasn’t clear enough what would you suggest we add to fix that?
  - N/A
- Did you encounter any problems with the product? If so, how did you encounter them?
  - No problems with it.
- Is the aesthetics of our product good? If not then why do you think so?
  - Could use some color.
- How does the product compare to other sign up and login systems?
  - Other systems work just fine.
- Overall, what did you think of the product?
  - Cool concept but not something needed. 
- Do you have anything that you would like to add?
  - Nope.

### Reflections

Overall, our user feedback was positive and provided us with a number of great suggestions on how to improve our product and its functionality. Throughout the testing process, users found the product to be consistently reliable and user-friendly, with secure login features they could see themselves using every day. The features that worked well included the sign-up and login processes, which allowed a new user to create an account and log in using their unique typing biometrics. The features and users' actions performed as expected, providing successful authentication upon logging in. The users appreciated the product's combination of convenience and security, including the easy login process and the ability to ensure that no one but them could access their account. They found value in its reliability and effectiveness, as they were able to log in without hassle throughout multiple attempts. The learning curve of our program is not too difficult since it uses the familiar processes of creating an account and logging in, which most internet users are accustomed to. As a result, users did not struggle navigating our system and performed the expected tasks without issues. However, users expressed concerns about the program's invasiveness and their inability to reset their typing baseline. To address these concerns and better fit our users' needs, we can make several changes. First, we can randomize passphrases for enhanced security. Second, we can provide recovery options for users who are locked out of their accounts and need to reset their typing baseline. Third, we can allow users to reset their typing baseline to accommodate changes in their typing style. In conclusion, we believe we accomplished our value proposition and brought our vision to life, achieving the results and success we desired. The valuable user feedback and suggestions we received will drive the next phase of our development, ensuring that we continue to meet the needs of our users.
