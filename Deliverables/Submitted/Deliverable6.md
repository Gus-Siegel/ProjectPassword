# D.6 Implementation 2

Group 04 – “TypeLock”\
Date: April 30, 2023\
Location: Flagstaff, Arizona\
Group Members: Taylor Nielsen, Eduardo De La Rosa, Alexander Siegel, Brock Heinz, Levi Watlington, Michael Vertin

## Introduction

TypeLock is a secure authentication system that identifies users by analyzing their typing behavior, offering a convenient and reliable alternative to traditional password-based login methods. The system's main value proposition lies in providing an effortless login experience for internet users who struggle with managing multiple passwords. Featuring seamless integration with existing systems, user-friendly design, and cross-platform compatibility, TypeLock ensures account security by recognizing unique typing patterns. By leveraging advanced typing metrics analysis, TypeLock allows users to effortlessly log in to their accounts without the need to memorize individual passwords. This innovative approach grants access to accounts based on users' typing behavior, making it an ideal solution for those who find it challenging to keep track of their passwords and login credentials. With its cutting-edge technology and ease of use, TypeLock streamlines the authentication process, enhancing security and convenience for its users.

**Project repository**: [https://github.com/Gus-Siegel/ProjectPassword](https://github.com/Gus-Siegel/ProjectPassword)

## Implemented requirements (Gus)

List in this section, the requirements and associated pull request that you implemented for this release, following the example below---include the description of the requirement, a link to the issue,  a link to the pull request(s) that implement the requirement, who implemented the requirement, who approved it, and a print screen that depicts the implemented feature (if applicable). Order the requirements by the name of the student who implemented them.

We expect that you implement/prototype the features you specified in your MVP (c.f. D.2 Requirements). We expect that all the members of the group have been involved in some programming activities and report here several pull requests.

Example:
Requirement: As a Student, I want to add a homework assignment so that I can organize my ToDo list.\
Issue:\
Pull request:\
Implemented by: Martin Fowler\
Approved by: Ada Lovelace\
Print screen: A print screen that depicts the implemented feature (if applicable)

Remember that all source code should be submitted by means of pull requests and the quality assurance person in the team should review and approve each pull request.

Grading criteria (20 points): This section will be evaluated in terms of correctness, completeness, thoroughness, consistency, coherence, adequate use of language, and amount of work put into the implementation. Students can receive different grades depending on their involvement. It is expected that all members contribute with non-trivial implementation. All pull requests should be approved and integrated by the quality assurance person. You should follow an adequate workflow (description of the requirement on the issue tracker, submission of the implemented requirement as a pull request, and review of the pull request by another developer).

## Tests

- The test framework **Gtest** was used to develop the automated tests.

- [Automated Unit Tests](https://github.com/Gus-Siegel/ProjectPassword/blob/main/Current_Release/BackEndServer/automatedTest.cpp)

- The following is a test case where the input contains more backspaces than there are characters preceding the backspaces, followed by the intended input. This [tests](https://github.com/Gus-Siegel/ProjectPassword/blob/main/Current_Release/BackEndServer/automatedTest.cpp) the [CharStateList](https://github.com/Gus-Siegel/ProjectPassword/blob/main/Current_Release/BackEndServer/compare_strings.h) class. \
![Excessive Characters Code](https://cdn.discordapp.com/attachments/856622349516144665/1102317933008539708/CS386_ExcessiveBackspace_TestCode.png)

- Automated Unit Test Results: \
![Test Output](https://cdn.discordapp.com/attachments/856622349516144665/1102323906876031058/CS386_GroupProject_D6.1_TestScreenshot.png)

## Demo

TypeLock Demo: [Youtube Link to Demo](https://youtu.be/C2s3oM5v9yE)

## Code quality

Our team was committed to maintaining high code quality throughout our project. We implemented several policies, conventions, and best practices to ensure that our code was clean, efficient, and easily understood by all team members. Some of the key measures we took included:

1. **Code Reviews**: We established a practice of performing code reviews, where every team member would review another member's code before it was merged into the main branch. This helped us catch errors, ensure consistency, and share knowledge among team members.

2. **Version Control**: We used Git for version control, which allowed us to track changes, collaborate effectively, and maintain a clean codebase. We also adopted a feature-branch workflow, where each team member would work on their own branch and then merge it into the main branch after a successful review.

3. **Documentation**: We documented our code with comments allowing team members to understand the purpose and functionality of different sections, making it easier for them to work with functions from different files or interpret the information being returned. Through documentation, our team was able to create clean, easily understood code that facilitated effective collaboration and development.

4. **Coding Standards**: We employed a naming convention to ensure that variables and functions had meaningful and descriptive names. This allowed the whole team to quickly grasp the purpose of different elements in the code. A good example of both our documentation and naming conventions being used effectively can be seen in the following code below. The comments in the snippet explain exactly what is going on in the function, including the specific unit of time being used. The variable names, such as current_time and keypress_data, are self-explanatory and clearly indicate their purpose.

```Python
    # Log the character entered by the user and the time it was pressed
    def log_key_press(event):
        # Record the current time (in seconds)
        current_time = time.time()
        # Append the key event name (letter) and the time it was pressed
        keypress_data.append([event.char, current_time])
```

By implementing these policies, conventions, and best practices, our team was able to maintain a high level of code quality throughout the project. This, in turn, facilitated better collaboration, easier debugging, and a more robust final product.

## Lessons learned

In retrospect, describe what your team learned during this second release and what would you change if you would continue developing the project.

I learned that managing a group requires constant and constant communication for group members. I looking back having more communication between the teams would have lead to a more streamlined development cycle.

I learned how to use TKInter pretty well during this project, and because of that I learned that a lot of premade gui’s have small incompatibilities when using different devices such as the inability to change the background color of buttons when using it with a MacOS.

Python and C++ were used to develop this project. During several intervals of the project, our team spent a lot of time attempting to combine C++ code with Python code. Our team would have had more time to work on other sections of the project if we had minimized the number of languages used.
