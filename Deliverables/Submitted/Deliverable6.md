# D.6 Implementation 2

Group 04 – “TypeLock”\
Date: April 30, 2023\
Location: Flagstaff, Arizona\
Group Members: Taylor Nielsen, Eduardo De La Rosa, Alexander Siegel, Brock Heinz, Levi Watlington, Michael Vertin

## Introduction

TypeLock is a secure authentication system that identifies users by analyzing their typing behavior, offering a convenient and reliable alternative to traditional password-based login methods. The system's main value proposition lies in providing an effortless login experience for internet users who struggle with managing multiple passwords. Featuring seamless integration with existing systems, user-friendly design, and cross-platform compatibility, TypeLock ensures account security by recognizing unique typing patterns. By leveraging advanced typing metrics analysis, TypeLock allows users to effortlessly log in to their accounts without the need to memorize individual passwords. This innovative approach grants access to accounts based on users' typing behavior, making it an ideal solution for those who find it challenging to keep track of their passwords and login credentials. With its cutting-edge technology and ease of use, TypeLock streamlines the authentication process, enhancing security and convenience for its users.

**Project repository**: [https://github.com/Gus-Siegel/ProjectPassword](https://github.com/Gus-Siegel/ProjectPassword)

## Implemented requirements

**Requirement**: As a user, I want to be able to login so that I can access my account.\
**Issue**: [Link to Issue](https://github.com/Gus-Siegel/ProjectPassword/issues/91)\
**Pull Request**: [Link to Pull request](https://github.com/Gus-Siegel/ProjectPassword/pull/143)\
**Implemented by**: Taylor Nielsen, Eduardo De La Rosa, Alexander Siegel, Brock Heinz, Levi Watlington, and Michael Vertin\
**Approved by**: Alexander Siegel\
**Print Screen**:\
![LoginPage](https://cdn.discordapp.com/attachments/1073663644589633536/1102498998012629022/LoginPage.png)

**Requirement**: As a user, I want an intuitive user interface so I can interact with the application comfortably.\
**Issue**: [Link to Issue](https://github.com/Gus-Siegel/ProjectPassword/issues/180)\
**Pull Request**: [Link to Pull request](https://github.com/Gus-Siegel/ProjectPassword/issues/180)\
**Implemented by**: Taylor Nielsen and Eduardo De La Rosa\
**Approved by**: Alexander Siegel\
**Print Screen**: Not applicable

**Requirement**: As a user, I want to be able to run the appliction on any operating system so that I can access the application any computer.\
**Issue**: [Link to Issue](https://github.com/Gus-Siegel/ProjectPassword/issues/116)\
**Pull Request**: [Link to Pull request](https://github.com/Gus-Siegel/ProjectPassword/pull/172)\
**Implemented by**: Taylor Nielsen and Eduardo De La Rosa\
**Approved by**: Taylor Nielsen\
**Print Screen**: Not applicable

**Requirement**: As a user, I want to be able to sign up so that I can access my account securely.\
**Issue**: [Link to Issue](https://github.com/Gus-Siegel/ProjectPassword/issues/179)\
**Pull Request**: [Link to Pull request](https://github.com/Gus-Siegel/ProjectPassword/pull/154)\
**Implemented by**: Taylor Nielsen, Eduardo De La Rosa, Alexander Siegel, Levi Watlington, and Michael Vertin\
**Approved by**: Taylor Nielsen\
**Print Screen**:\
![SignupPage](https://cdn.discordapp.com/attachments/1073663644589633536/1102499027213369384/SignupPage.png)

**Requirement**: As a user, I want to know that my account is secure so that I have peace of mind that my information is safe.\
**Issue**: [Link to Issue](https://github.com/Gus-Siegel/ProjectPassword/issues/181)\
**Pull Request**: [Link to Pull request](https://github.com/Gus-Siegel/ProjectPassword/pull/143)\
**Implemented by**: Alexander Siegel and Michael Vertin\
**Approved by**: Alexander Siegel\
**Print Screen**: Not applicable

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

In retrospect, our team learned valuable lessons during the second release of our project, with a strong emphasis on effective communication and planning. We discovered that setting clear milestones, prioritizing tasks, and fostering constant communication between team members led to a more streamlined development cycle. One challenge we faced was integrating Python and C++ code, which consumed a significant amount of time. If we were to continue developing the project, we would consider minimizing the number of languages used to save time and resources. By doing so, we could allocate more time to address other aspects of the project, improving overall efficiency. We also learned that test-driven development may be an effective way to ensure steady and quick deployment of new features, and one that we should consider in the future. Although we had automated integration testing implemented for new builds, we hadn't updated that framework to cover some of our later-implemented features. As such, we unfortunately lost a significant amount of time in the last leg of development when attempting to make the backend functional. In hindsight, unit tests for the database and its communication with other backend files are something we should have invested more in. Furthermore, we recognized the importance of regularly reassessing our progress and adjusting our strategies accordingly. By conducting frequent retrospectives, we could identify areas for improvement and implement necessary changes more effectively. This iterative approach would enable our team to learn from our experiences and continuously refine our development process. In addition to refining our technical skills, we also learned the value of fostering a supportive and inclusive team environment. Encouraging open dialogue, sharing knowledge, and providing constructive feedback not only enhanced collaboration but also contributed to individual growth and development. Our experiences during the second release reinforced the value of effective communication, proper planning, and a strong focus on best practices in software development. Moving forward, our team would concentrate on these lessons to enhance collaboration and ensure the successful execution of future project releases.
