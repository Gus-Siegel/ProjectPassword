# D.4 Implementation 1

Group 04 – “TypeLock”\
Date: March 26, 2023\
Location: Flagstaff, Arizona\
Group Members: Taylor Nielsen, Eduardo De La Rosa, Alexander Siegel, Brock Heinz, Levi Watlington, Michael Vertin

## Introduction

TypeLock is a secure authentication system that identifies users by analyzing their typing behavior, offering a convenient and reliable alternative to traditional password-based login methods. The system's main value proposition lies in providing an effortless login experience for internet users who struggle with managing multiple passwords. Featuring seamless integration with existing systems, user-friendly design, and cross-platform compatibility, TypeLock ensures account security by recognizing unique typing patterns. By leveraging advanced typing metrics analysis, TypeLock allows users to effortlessly log in to their accounts without the need to memorize individual passwords. This innovative approach grants access to accounts based on users' typing behavior, making it an ideal solution for those who find it challenging to keep track of their passwords and login credentials. With its cutting-edge technology and ease of use, TypeLock streamlines the authentication process, enhancing security and convenience for its users.

**Project repository**: [https://github.com/Gus-Siegel/ProjectPassword](https://github.com/Gus-Siegel/ProjectPassword)

## Implemented requirements (Gus, Eddie, Brock)

List in this section, the requirements and associated pull request that you implemented for this release, following the example below---include the description of the requirement, a link to the issue, a link to the pull request(s) that implement the requirement, who implemented the requirement, who approved it, and a print screen that depicts the implemented feature (if applicable). I expect that you implement the features you specified in your MVP (c.f. D.2 Requirements).

Order the requirements below by the name of the student who implemented them. All the members of the group should have worked on implementation activities and submitted pull requests. Only stable code should be included in the release. The code that is still under development should be in branches.

## Tests

- The test framework, **gtest**, was used to develop the automated tests.

- [Automated Unit Tests Folder](https://github.com/Gus-Siegel/ProjectPassword/tree/main/BackEnd/StringComparison)

- Example testing the [TimeWeightType](https://github.com/Gus-Siegel/ProjectPassword/blob/main/BackEnd/StringComparison/compare_strings.cpp) class:\
The time error [is being tested](https://github.com/Gus-Siegel/ProjectPassword/blob/main/BackEnd/StringComparison/automatedTest.cpp) by generating a randomized input, and comparing a manual error calculation to the error the class function gives.

- ![Result of the execution of the automated tests](https://raw.githubusercontent.com/Gus-Siegel/ProjectPassword/main/Deliverables/Submitted/Deliverable4_Tests.png)

## Adopted technologies

### Frontend Technologies

- **Tkinter**: This technology was adopted because we needed a graphical user interface (GUI) that our users could use to help them input what they need to in the correct box.

### Client/Server Technologies

- **PyCharm**: PyCharm was utilized to run the frontend and client because visual studio code (VSC) required additional work arounds to be implemented for the pynput module, used in the frontend GUI to work.

- **PuTTY**: PuTTY was adopted as it was vital for running the C++ Server in a remote environment.

- **HostWinds**: HostWinds was adopted to  host the remote server where we run our C++ Server.

- **FileZilla**: FileZilla was adopted as our file transfer service in order to allows us to upload programs to our remote server.

## Learning/training

### Frontend Team

During the development of the frontend, Eduardo and Levi quickly mastered the adopted technology, tkinter, thanks to the comprehensive tutorials available on YouTube and the numerous helpful posts on Stack Overflow.

### Client/Server Team

For establishing the client-server relationship, we needed to delve deeper into understanding classes and how to connect a Python client to a C++ server. We designed the Python client as a class for seamless integration with the frontend code, enabling the GUI to connect to the client directly.

Gus and Taylor collaborated on the client-server aspect of the project to achieve the minimum viable product. Gus, with his expertise in object-oriented programming, guided Taylor in writing classes and implementing object-oriented practices for the client. Both students, currently enrolled in CS460 Computer Networking, utilized their classroom experience to develop client-server programs using a TCP connection. Google proved invaluable in helping the students learn how to keep the server running continuously and accept connections effectively.

## Deployment

The deployment we researched was **Docker**. Upon implementing we found that part of Docker that allows for sharing, Docker Playground
was down. We submitted an issue to the creators git repo and saw we weren't the only ones having this issue.
If this issue persists we won't be able to utilize Docker and will have to find another method of distribution.

![dockerError](https://raw.githubusercontent.com/Gus-Siegel/ProjectPassword/main/Deliverables/Submitted/DockerIssue.png)

## Licensing

We opted for the **MIT license** to allow maximum freedom for others to use and distribute our project, even in closed source versions. Our aim is to make the project as inclusive as possible for anyone interested in contributing.

**Project License**: [https://github.com/Gus-Siegel/ProjectPassword/blob/main/LICENSE.md](https://github.com/Gus-Siegel/ProjectPassword/blob/main/LICENSE.md)

## Readme File

- [README.md](https://github.com/Gus-Siegel/ProjectPassword/blob/main/README.md)

- [CONTRIBUTING.md](https://github.com/Gus-Siegel/ProjectPassword/blob/main/CONTRIBUTING.MD)

- [CODE_OF_CONDUCT.md](https://github.com/Gus-Siegel/ProjectPassword/blob/main/CODE_OF_CONDUCT.md)

- [LICENSE.md](https://github.com/Gus-Siegel/ProjectPassword/blob/main/LICENSE.md)

## Look & feel

The first thing we did was talk about what the logo was going to look like since we chose to work on the aesthetics first. The logo we chose ended up having a white font color so with that in mind we chose black as a background color for the screen

![logo](https://user-images.githubusercontent.com/90239263/227803445-bf05812f-e666-408a-a5a0-11b12f1628ac.png)

After we figured out the color scheme we decided on a central layout for the inputs and buttons, everything is put over one another in the center column of the interface.

![userface layout](https://cdn.discordapp.com/attachments/1073663644589633536/1089779829446033438/Screen_Shot_2023-03-26_at_22.15.34_PM.png)

In the end we decided to go with two buttons for our interface. One button would take the data recorded from the keyboard and put it in a list with the times they were pushed and put it in a variable while the other button clears the text box for another phrase to be typed and recorded

![textbox and buttons](https://cdn.discordapp.com/attachments/1073663644589633536/1089779423466762291/Screen_Shot_2023-03-26_at_22.10.03_PM.png)

## Lessons learned

In retrospective, describe what your team learned during this first release and what you are planning to change for the second release.

## Demo

Include a link to a video showing the system working.
