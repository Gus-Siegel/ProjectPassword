# D.6 Implementation 2

Group 04 – “TypeLock”\
Date: April 30, 2023\
Location: Flagstaff, Arizona\
Group Members: Taylor Nielsen, Eduardo De La Rosa, Alexander Siegel, Brock Heinz, Levi Watlington, Michael Vertin

## Introduction (Eddie)

Provide 1-2 paragraphs to describe your system. This description should contain the value proposition and the main features. At the end of the introduction, include a link to your project on GitHub.

Grading criteria (1 point): This section will be evaluated in terms of correctness, completeness, thoroughness, consistency, coherence, and adequate use of language. The description should be consistent with the current state of the project. You should include the link to GitHub.

## Implemented requirements 

[Database](https://github.com/Gus-Siegel/ProjectPassword/issues/91)\
In the first release we were unable to create a database that worked, but in this release we were able to develop a working database\
Implemented by Everyone\
[Pull request](https://github.com/Gus-Siegel/ProjectPassword/pull/143)

[UI Update](https://github.com/Gus-Siegel/ProjectPassword/issues/180) \
We felt that our UI could be updated after the first implementation so we changed the look of our program\
Implemented by Eddie, Taylor\
[Pull request](https://github.com/Gus-Siegel/ProjectPassword/issues/180)


[Deployable](https://github.com/Gus-Siegel/ProjectPassword/issues/116) \
In the first implementation, we were unable to create a true deliverable product. In this version we created a executeable to run the product.\
Implemented by: Taylor, Eddie\
[Pull request](https://github.com/Gus-Siegel/ProjectPassword/pull/172)

[Sign up page](https://github.com/Gus-Siegel/ProjectPassword/issues/179) \
In order to use our product, users need to be able to sign up to access their account.\
Implemented in 2 parts, Frontend: Eddie, Levi, Taylor Backend: Michael, Gus\
[Pull request](https://github.com/Gus-Siegel/ProjectPassword/pull/154)

[Backend reliability](https://github.com/Gus-Siegel/ProjectPassword/issues/181)\
In our first release, we found it was too easy to log in. To fix this we changed the algorithm for logging in to be more strict.\
Implemented by Michael, Gus\
[Pull request](https://github.com/Gus-Siegel/ProjectPassword/pull/143)





## Tests

- 3.1.1. Gtest was chosen for testing. 
- 3.1.2. [Automated Unit Tests](https://github.com/Gus-Siegel/ProjectPassword/blob/main/Current_Release/BackEndServer/automatedTest.cpp)
- 3.1.3. The following is a test case where the input contains more backspaces than there are characters preceding the backspaces, followed by the intended input. This [tests](https://github.com/Gus-Siegel/ProjectPassword/blob/main/Current_Release/BackEndServer/automatedTest.cpp) 
 the [CharStateList](https://github.com/Gus-Siegel/ProjectPassword/blob/main/Current_Release/BackEndServer/compare_strings.h) class. \
![Excessive Characters Code](https://cdn.discordapp.com/attachments/856622349516144665/1102317933008539708/CS386_ExcessiveBackspace_TestCode.png)
- 3.1.4. Test Results: \
![Test Output](https://cdn.discordapp.com/attachments/856622349516144665/1102323906876031058/CS386_GroupProject_D6.1_TestScreenshot.png)

## Demo

TypeLock Demo: [Link to Demo](https://youtu.be/C2s3oM5v9yE)

## Code quality (Brock, Levi)

Describe how your team managed code quality. What were your policies, conventions, adopted best practices, etc. to foster high-quality code?

Our team has used a few conventions to help us in the engineering of our program. We use a lot of comments to explain what is going on so that if our other team members need to do something that calls a function from a different file, or if they need to know what type of information is being returned to their portion as a success or failure signal, they can go to that file and read the comments for that function. We also used a naming convention to make sure everything made sense. We didn’t have specific names that we needed to use for certain things, we just wanted to have the names of variables make sense so that the whole team knows what they are used for. A good example of both conventions being used is shown in this code snippet:

```Python
    # Log the character entered by the user and the time it was pressed\n
    def log_key_press(event):
        # Record the current time (in seconds)
        current_time = time.time()
        # Append the key event name (letter) and the time it was pressed
        keypress_data.append([event.char, current_time])
```

The comments in the snippet explain exactly what is going on in the function, even listing the specific unit of time being used for the function. The names of the variables are also very self explanatory, being current_time for what time a key was pressed and keypress_data for all of the keys that were pressed and recorded.

## Lessons learned (All members)

In retrospect, describe what your team learned during this second release and what would you change if you would continue developing the project.

I learned that managing a group requires constant and constant communication for group members. I looking back having more communication between the teams would have lead to a more streamlined development cycle.

I learned how to use TKInter pretty well during this project, and because of that I learned that a lot of premade gui’s have small incompatibilities when using different devices such as the inability to change the background color of buttons when using it with a MacOS.

Python and C++ were used to develop this project. During several intervals of the project, our team spent a lot of time attempting to combine C++ code with Python code. Our team would have had more time to work on other sections of the project if we had minimized the number of languages used. 

Grading criteria (2 points): Adequate reflection about problems and solutions, clear description with adequate use of language.
