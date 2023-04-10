# D.4 Implementation 1

Group 04 – “TypeLock”\
Date: March 26, 2023\
Location: Flagstaff, Arizona\
Group Members: Taylor Nielsen, Eduardo De La Rosa, Alexander Siegel, Brock Heinz, Levi Watlington, Michael Vertin

## Introduction

TypeLock is a secure authentication system that identifies users by analyzing their typing behavior, offering a convenient and reliable alternative to traditional password-based login methods. The system's main value proposition lies in providing an effortless login experience for internet users who struggle with managing multiple passwords. Featuring seamless integration with existing systems, user-friendly design, and cross-platform compatibility, TypeLock ensures account security by recognizing unique typing patterns. By leveraging advanced typing metrics analysis, TypeLock allows users to effortlessly log in to their accounts without the need to memorize individual passwords. This innovative approach grants access to accounts based on users' typing behavior, making it an ideal solution for those who find it challenging to keep track of their passwords and login credentials. With its cutting-edge technology and ease of use, TypeLock streamlines the authentication process, enhancing security and convenience for its users.

**Project repository**: [https://github.com/Gus-Siegel/ProjectPassword](https://github.com/Gus-Siegel/ProjectPassword)

## Implemented requirements

Requirement: As a developer, I want to be able to switch keyboards and still log into my account.\
Issue: [Link to Issue](https://github.com/Gus-Siegel/ProjectPassword/issues/23)\
Implemented by: Michael Vertin\
Approved by: Gus Siegel

Requirement: As an elderly person, I want an easier way to login so I don’t have to remember so many passwords.\
Issue: [Link to Issue](https://github.com/Gus-Siegel/ProjectPassword/issues/25)\
Implemented by: Eduardo De La Rosa and Levi Watlington\
Approved by: Gus Siegel

Requirement: As a college student, I want a more secure login so I don’t have to constantly change my passwords.\
Issue: [Link to Issue](https://github.com/Gus-Siegel/ProjectPassword/issues/26)\
Implemented by: Taylor Nielsen and Gus Siegel\
Approved by: Michael Vertin

Requirement: As a busy person, I want a quick and consistent way to log in to my account, so that I do not need to spend excessive time logging in.\
Issue: [Link to Issue](https://github.com/Gus-Siegel/ProjectPassword/issues/27)\
Implemented by: Michael Vertin, Taylor Nielsen, and Gus Siegel\
Approved by: Levi Watlington

Requirement: As a forgetful person, I want to not need to remember a password, so that I do not need to remember information to log in.\
Issue: [Link to Issue](https://github.com/Gus-Siegel/ProjectPassword/issues/28)\
Implemented by: Michael Vertin, Taylor Nielsen, and Gus Siegel\
Approved by: Eduardo De La Rosa

Requirement: As a novice tech user, I want to be able to use a more flexible login system so I don't get locked out of my accounts.\
Issue: [Link to Issue](https://github.com/Gus-Siegel/ProjectPassword/issues/31)\
Implemented by: Eduardo De La Rosa and Levi Watlington\
Approved by: Gus Siegel

## Tests

<<<<<<< HEAD
- 
## Tests (Michael)
- gtest
=======
- The test framework, **gtest**, was used to develop the automated tests.

>>>>>>> b4b12a7d1bd184ef2cf9d20c7849e498b046288e
- [Automated Unit Tests Folder](https://github.com/Gus-Siegel/ProjectPassword/tree/main/BackEnd/StringComparison)

- Example testing the [TimeWeightType](https://github.com/Gus-Siegel/ProjectPassword/blob/main/BackEnd/StringComparison/compare_strings.cpp) class:\
The time error [is being tested](https://github.com/Gus-Siegel/ProjectPassword/blob/main/BackEnd/StringComparison/automatedTest.cpp) by generating a randomized input, and comparing a manual error calculation to the error the class function gives.

- ![Result of the execution of the automated tests](https://raw.githubusercontent.com/Gus-Siegel/ProjectPassword/main/Deliverables/Submitted/Deliverable4_Tests.png)

## Adopted technologies

### Frontend Technologies

- **Tkinter**: This technology was adopted because we needed a graphical user interface (GUI) that our users could use to help them input what they need to in the correct box.

### Client Server Technologies

- **PyCharm**: PyCharm was utilized to run the frontend and client because visual studio code (VSC) required additional work arounds to be implemented for the pynput module, used in the frontend GUI to work.

- **PuTTY**: PuTTY was adopted as it was vital for running the C++ Server in a remote environment.

- **HostWinds**: HostWinds was adopted to  host the remote server where we run our C++ Server.

- **FileZilla**: FileZilla was adopted as our file transfer service in order to allows us to upload programs to our remote server.

### Backend Technologies

- **g++**: This technology was adoped as the compiler for c++, which is used to generate machine code to be used during run-time.

## Learning/training

### Frontend Team

During the development of the frontend, Eduardo and Levi quickly mastered the adopted technology, tkinter, thanks to the comprehensive tutorials available on YouTube and the numerous helpful posts on Stack Overflow.

### Client/Server Team

 For establishing the client-server relationship, we needed to delve deeper into understanding classes and how to connect a Python client to a C++ server. We designed the Python client as a class for seamless integration with the frontend code, enabling the GUI to connect to the client directly.

Gus and Taylor collaborated on the client-server aspect of the project to achieve the minimum viable product. Gus, with his expertise in object-oriented programming, guided Taylor in writing classes and implementing object-oriented practices for the client. Both students, currently enrolled in CS460 Computer Networking, utilized their classroom experience to develop client-server programs using a TCP connection. Google proved invaluable in helping the students learn how to keep the server running continuously and accept connections effectively.

### Backend Team

The backend system developed by Michael and Brock, learned and continued working with g++ to successfully implement the necessary functionality. Since gcc was used in previous courses, this made learning g++ quick as the syntax of c and cpp are almost identical. There were a few issues including modules, although an alternative method was found for those modules.

## Deployment

The deployment we researched was **Docker**. Upon implementing we found that part of Docker that allows for sharing, Docker Playground
was down. We submitted an issue to the creators git repo and saw we weren't the only ones having this issue.
If this issue persists we won't be able to utilize Docker and will have to find another method of distribution.

![dockerError](https://raw.githubusercontent.com/Gus-Siegel/ProjectPassword/main/Deliverables/Submitted/DockerIssue.png)

Note: Messaged Ana with this issue on Sunday at 2:15 pm.

## Licensing

We opted for the **MIT license** to allow maximum freedom for others to use and distribute our project, even in closed source versions. Our aim is to make the project as inclusive as possible for anyone interested in contributing.

**Project License**: [https://github.com/Gus-Siegel/ProjectPassword/blob/main/LICENSE.md](https://github.com/Gus-Siegel/ProjectPassword/blob/main/LICENSE.md)

## Readme File

- [README.md](https://github.com/Gus-Siegel/ProjectPassword/blob/main/README.md)

- [CONTRIBUTING.md](https://github.com/Gus-Siegel/ProjectPassword/blob/main/CONTRIBUTING.MD)

- [CODE_OF_CONDUCT.md](https://github.com/Gus-Siegel/ProjectPassword/blob/main/CODE_OF_CONDUCT.md)

- [LICENSE.md](https://github.com/Gus-Siegel/ProjectPassword/blob/main/LICENSE.md)

## Look & feel

Initially, we commenced our design process by deliberating on the logo's appearance, considering the visual appeal as a priority. Upon finalizing the logo, which prominently featured white font, we opted to compliment it with a black background color for the main window. This deliberate color choice was made with an intention to enhance the logo's visibility and lend a sleek, modern aesthetic to the overall design.

![logo](https://user-images.githubusercontent.com/90239263/227803445-bf05812f-e666-408a-a5a0-11b12f1628ac.png)

Once the color scheme was finalized, we proceeded to design a cohesive layout for the user interface. We opted for a centralized layout that positioned all the inputs and buttons over each other in the center column. This approach not only creates a clean and organized appearance, but also ensures easy accessibility and user-friendliness.

![userface layout](https://cdn.discordapp.com/attachments/1073663644589633536/1089779829446033438/Screen_Shot_2023-03-26_at_22.15.34_PM.png)

Ultimately, we concluded that a two-button interface would be ideal for our software. The login button functioned by capturing the user's keyboard input, recording the timing of each keystroke, and compiling the data into a list that was then assigned to a variable. On the other hand, the second button was responsible for clearing the text box, allowing for a new phrase to be entered and recorded.

![textbox and buttons](https://cdn.discordapp.com/attachments/1073663644589633536/1089779423466762291/Screen_Shot_2023-03-26_at_22.10.03_PM.png)

## Lessons learned

For even a minimum viable product, effective communication and collaboration play crucial roles in achieving project completion for this stage. Our team faced numerous last-minute issues that required prompt resolution before we could record the final video. Each time we encountered a problem, we needed to contact the team members responsible for the relevant code and request their assistance. Fortunately, our team had anticipated such situations arising during this crucial weekend, ensuring that everyone was prepared and readily available for collaboration. This proactive mindset eliminated the need to chase after team members, allowing us to efficiently address any outstanding issues and successfully complete each step. This experience underscores the importance of teamwork, open communication, and mutual support in successfully navigating the challenges of software development projects. As we plan for our second release, to enhance our team's communication and ensure that everyone is on the same page, we have proposed implementing a system that includes more frequent discussions, not just relying on our in-class interactions or the existing weekly meetings. By scheduling a quick Discord meeting at the beginning of each week, in addition to our regular weekly gathering, we aim to create a more structured and consistent communication framework. These biweekly touchpoints will allow team members to share updates, ask questions, and address any potential issues in a timely manner. Moreover, the increased frequency of communication will foster a stronger sense of teamwork and collaboration, as we will be able to monitor progress more closely and offer support when needed. By adopting this approach, we anticipate improved project management, streamlined workflows, and ultimately, a more successful outcome moving forward.

## Demo

**Youtube Link**: [TypeLock Demo](https://youtu.be/H_fW2biRHsk)
