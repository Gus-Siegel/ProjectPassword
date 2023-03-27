# D.4 Implementation 1

Group 04 – “TypeLock”\
Date: March 26, 2023\
Location: Flagstaff, Arizona\
Group Members: Taylor Nielsen, Eduardo De La Rosa, Alexander Siegel, Brock Heinz, Levi Watlington, Michael Vertin

## Introduction (Eddie)

Provide a short paragraph that describes your system. This paragraph should contain the value proposition and the description of the main features of the software. At the end of the introduction, include links to your project on GitHub.

Project repository: [https://github.com/Gus-Siegel/ProjectPassword](https://github.com/Gus-Siegel/ProjectPassword)

## Implemented requirements (Gus, Eddie, Brock)

List in this section, the requirements and associated pull request that you implemented for this release, following the example below---include the description of the requirement, a link to the issue, a link to the pull request(s) that implement the requirement, who implemented the requirement, who approved it, and a print screen that depicts the implemented feature (if applicable). I expect that you implement the features you specified in your MVP (c.f. D.2 Requirements).

Requirement: As a developer, I want to be able to switch keyboards and still log into my account
Issue: [Issue](https://github.com/Gus-Siegel/ProjectPassword/issues/23)
Implemented by: Michael  
Approved by: Gus Siegel
PrintScreen: N/A

Requirement: As an elderly person, I want an easier way to login so I don’t have to remember so many passwords.
Issue: [Issue](https://github.com/Gus-Siegel/ProjectPassword/issues/25)
Implemented by: Eddie, Levi 
Approved by: Gus Siegel
PrintScreen: N/A

Requirement: As a college student, I want a more secure login so I don’t have to constantly change my passwords.
Issue: [Issue](https://github.com/Gus-Siegel/ProjectPassword/issues/26)
Implemented by: Taylor, Gus
Approved by: Michael
PrintScreen: N/A

Requirement: As a busy person, I want a quick and consistent way to log in to my account, so that I do not need to spend excessive time logging in.
Issue: [Issue](https://github.com/Gus-Siegel/ProjectPassword/issues/27)
Implemented by: Michael, Taylor, Gus
Approved by: Levi
PrintScreen: N/A

Requirement: As a forgetful person, I want to not need to remember a password, so that I do not need to remember information to log in.
Issue: [Issue](https://github.com/Gus-Siegel/ProjectPassword/issues/28)
Implemented by: Michael, Taylor, Gus
Approved by: Eddie
PrintScreen: N/A

Requirement: As a novice tech user, I want to be able to use a more flexible login system so I don't get locked out of my accounts.
Issue: [Issue](https://github.com/Gus-Siegel/ProjectPassword/issues/31)
Implemented by: Eddie, Levi
Approved by: Gus Siegel
PrintScreen: N/A


Order the requirements below by the name of the student who implemented them. All the members of the group should have worked on implementation activities and submitted pull requests. Only stable code should be included in the release. The code that is still under development should be in branches.

Taylor
- Wrote python client
- Made python client a class
- Encoded data from client
- Connected Front End to Client
- Client sends username and passphrase metrics to the server
- Client sends close TCP request to server after sending all data
- 
## Tests (Michael)
- gtest
- [Automated Unit Tests Folder](https://github.com/Gus-Siegel/ProjectPassword/tree/main/BackEnd/StringComparison)
- Example testing the [TimeWeightType](https://github.com/Gus-Siegel/ProjectPassword/blob/main/BackEnd/StringComparison/compare_strings.cpp) class:\
The time error [is being tested](https://github.com/Gus-Siegel/ProjectPassword/blob/main/BackEnd/StringComparison/compare_strings.cpp/automatedTest.cpp) by generating a randomized input, and comparing a manual error calculation to the error the class function gives. 
![](/Deliverable4_Tests.png)

## Adopted technologies (Levi, Taylor, Michael)

List the adopted technologies with a brief description and justification for choosing them.

Front End Technologies: Tkinter - We adopted this technology because we needed a GUI that our users could use to help them input what they need to in the correct box.

Client Server Technologies:

PyCharm - We used PyCharm to run the front end and client because VSC required additional work arounds be implemented for pynput which was utilized on the Front End.

PuTTY - PuTTY was vital for running our C++ Server in a remote environment.

HostWinds - HostWinds is the host for our remote server where we run our C++ Server.

FileZilla - FileZilla is our file transfer service that allows us to upload programs to our remote server.

## Learning/training (Levi, Taylor, Michael)

Describe the strategies employed by the team to learn the adopted technologies.

In the front end portion we learned our adopted technology, tkinter, pretty quickly since there are a lot of comprehensive tutorials
on youtube as well as a lot of helpful posts on stackoverflow.
For the Client Server relationship we needed to research classes, and how to connect a python client to a c++ Server.
The python client was made into a class for easy connection to the front end code. This allows the gui to call the client directly.

Gus and Taylor Worked on the Client Server portion of the project for the minimum viable product. Gus is knowledgeable in
object oriented programing and helped get Taylor up to speed when it came to writing classes and implementing object-oriented
practices on the client. Both students are taking CS460 Computer Networking, thus their experience in class helped them
to write Client Server programs with a TCP connection. Google was essential in teaching the students how to continuously
allow the server to run and accept connections.

## Deployment (Gus)

Provide a link for the system in production and describe how you are deploying your system.

The deployment we researched was Docker. Upon implementing we found that part of Docker that allows for sharing, Docker Playground
was down. We submitted an issue to the creators git repo and saw we weren't the only ones having this issue.
If this issue persists we won't be able to utilize Docker and will have to find another method of distribution.
![dockerError](https://raw.githubusercontent.com/Gus-Siegel/ProjectPassword/main/Deliverables/Submitted/DockerIssue.png)

Message Ana with this issue on Sunday at 2:15 pm.


## Licensing (Eddie)

Inform the license you adopted for your source code (remember to configure GitHub accordingly). Explain why you adopted this license.

MIT License

- [MIT license overview](https://choosealicense.com/licenses/mit/)

- [Project license](https://github.com/Gus-Siegel/ProjectPassword/blob/main/LICENSE.md)

We opted for the MIT license to allow maximum freedom for others to use and distribute our project, even in closed source versions. Our aim is to make the project as inclusive as possible for anyone interested in contributing.

## Readme File (Eddie)

You should also prepare your repository for receiving new contributors. You should prepare a Readme.md file. Tag the GitHub repository accordingly.

Your repository should contain a CONTRIBUTING.md file, a LICENSE file, and a CODE_OF_CONDUCT.md file. Search online for some examples of these files. In this section of the deliverable, put links to these files on GitHub.

- [README.md](https://github.com/Gus-Siegel/ProjectPassword/blob/main/README.md)

- [CONTRIBUTING.md](https://github.com/Gus-Siegel/ProjectPassword/blob/main/CONTRIBUTING.MD)

- [CODE_OF_CONDUCT.md](https://github.com/Gus-Siegel/ProjectPassword/blob/main/CODE_OF_CONDUCT.md)

- [LICENSE](https://github.com/Gus-Siegel/ProjectPassword/blob/main/LICENSE.md)

## Look & feel (Eddie, Levi)

Describe the approach you adopted to design your user interface. Include some screenshots.

The first thing we did was talk about what the logo was going to look like since we chose to work on the aesthetics first. The logo we chose ended up having a white font color so with that in mind we chose black as a background color for the screen

![logo](https://user-images.githubusercontent.com/90239263/227803445-bf05812f-e666-408a-a5a0-11b12f1628ac.png)

After we figured out the color scheme we decided on a central layout for the inputs and buttons, everything is put over one another in the center column of the interface.

(Screenshot of layout of our interface)

In the end we decided to go with two buttons for our interface. One button would take the data recorded from the keyboard and put it in a list with the times they were pushed and put it in a variable while the other button clears the text box for another phrase to be typed and recorded

(Screenshot of textbox and both buttons)

## Lessons learned (Everyone)

In retrospective, describe what your team learned during this first release and what you are planning to change for the second release.

Even for a minimum viable product, communication and collaboration are vital parts of completion. We had lots of last minute 
issues we needed to fix before being able to take the final video. Each time we found an issue we had to reach out to the 
team responsible for that code and ask for their help. Thankfully, everyone was expecting that might be the case this weekend,
which meant we didn't have to hound anyone to jump online and complete a step.

## Demo

Include a link to a video showing the system working.
Youtube Demo:
https://youtu.be/H_fW2biRHsk