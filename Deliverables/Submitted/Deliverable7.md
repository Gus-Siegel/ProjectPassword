# D.7 V&V

Group 04 – “TypeLock”\
Date: May 3, 2023\
Location: Flagstaff, Arizona\
Group Members: Taylor Nielsen, Eduardo De La Rosa, Alexander Siegel, Brock Heinz, Levi Watlington, Michael Vertin

## Description

As internet usage diversifies and expands, many users face the challenge of remembering multiple passwords for their various accounts, leading to time-consuming processes and compromised security. TypeLock is a secure account login system designed to address this issue by employing typing metrics, such as speed and accuracy, to identify users without relying on traditional passwords. Instead of necessitating the precise memorization and entry of distinct short passwords, TypeLock utilizes the user's ability to type a previously seen phrase or paragraph, identifying them through their unique typing metrics. This method streamlines the login process, enabling users to access their accounts without the burden of memorizing multiple passwords or sifting through a password list or file, as their typing metrics serve as a unique identifier. TypeLock is an ideal solution for those struggling to remember passwords and seeking a more secure and convenient way to access their online accounts.

The primary objective of the system is to establish a secure, reliable, and user-friendly login process that enhances account security. To achieve this, the system accurately and efficiently identifies users based on typing metrics like speed and accuracy, while also facilitating easy setup and management of typing style datasets. The system comprises three main components: Back-end, Front-end, and Client-Server relationship. The Back-end employs algorithms to accurately identify users by their typing style, ensuring secure account access and preventing unauthorized entry. The Back-end's algorithm compares two lists of keypresses along with their associated timings, identifying spelling errors and calculating the ratio of average time delay differences. Constants are employed to determine if the input matches the user's recorded typing style. The Front-end focuses on user interface design, creating a reference passphrase for users to enter and implementing the algorithm to capture user input for processing. The Client and Server act as the central elements that integrate the Front-end design and data with the Back-end algorithm. Notably, the Front-end is developed in Python, while the Back-end uses C++. The primary distinction between these languages is their approach to endianness. Both Python and C++ store integers based on the endianness of the processor running the program. To avoid issues when passing data between end hosts with different endian storage systems, conversions are performed on the client and server sides before transferring information through the Client-Server connection.

## Verification (tests)

Verification aims to ensure that you correctly developed the product.

### Unit test (Michael)

- gtest was chosen to create the tests

- [Folder of Mock Tests](https://github.com/Gus-Siegel/ProjectPassword/tree/main/Current_Release/BackEndServer)

- The [database](https://github.com/Gus-Siegel/ProjectPassword/blob/main/Current_Release/BackEndServer/mockTestWithServer.cpp) class is being tested [using a DatabaseMock](https://github.com/Gus-Siegel/ProjectPassword/blob/main/Current_Release/BackEndServer/mockTestWithServer.cpp)
\
![Class Code](https://cdn.discordapp.com/attachments/856622349516144665/1103493888615923752/image.png)

- Execution Results:\
![Execution Results](https://cdn.discordapp.com/attachments/856622349516144665/1103494402497859644/image.png)

### Acceptance test (TBD)

An acceptance test is a test that verifies the correct implementation of a feature from the user interface perspective. An acceptance test is a black box test (the system is tested without knowledge about its internal implementation). Provide the following information:

- Test framework you used to develop your tests (e.g., Selenium, Katalon Studio, Espresso2, Cucumber, etc.):

Unittest - Python testing library

- Link to your GitHub folder where your automated acceptance tests are located.

Test Link: [Link to Test location](https://github.com/Gus-Siegel/ProjectPassword/tree/main/Current_Release/FrontEndClient)

- An example of an acceptance test. Include in your answer a GitHub link to the test and an explanation about the tested feature.

![AcceptanceTestResults](https://github.com/Gus-Siegel/ProjectPassword/blob/main/Deliverables/Submitted/AcceptanceTest.png)

The above test performs 3 different tests. The first is a signup test to make sure that we can add a new user. The second test, tests that the user can log in. The third test checks that the user will not be able to sign in if the speed of the passphrase is incorrect. The fourth test checks for a fail if the passphrase has spellcheck mistakes that are abnormal to the user. Each of these tests modifies the user entries and connects to the server, testing the clinet/server connection as well as the algorithm.

## Validation (user evaluation) (Gus)

### Script

**Tasks for the user:**

- Navigate to sign up page
- Follow sign up procedure
- Follow login procedure

**Interview questions:**

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

Conduct the user evaluation with at least 3 users. Report the data that you collected.

### Reflections

Reflect on what you observed. Some questions that you can explore: What features worked well? What can be changed? How is the learning curve of your system? Did the users perform the tasks as you expected? Did the users’ actions produce the results they expected? What did the users like the most? Is your value proposition accomplished?
