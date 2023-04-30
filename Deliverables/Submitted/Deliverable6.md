# D.6 Implementation 2

Group 04 – “TypeLock”\
Date: April 30, 2023\
Location: Flagstaff, Arizona\
Group Members: Taylor Nielsen, Eduardo De La Rosa, Alexander Siegel, Brock Heinz, Levi Watlington, Michael Vertin

## Introduction (Eddie)

Provide 1-2 paragraphs to describe your system. This description should contain the value proposition and the main features. At the end of the introduction, include a link to your project on GitHub.

Grading criteria (1 point): This section will be evaluated in terms of correctness, completeness, thoroughness, consistency, coherence, and adequate use of language. The description should be consistent with the current state of the project. You should include the link to GitHub.

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

## Tests (Michael)

You should implement automated tests for the features described in the previous subsection. Provide the following information:

- 3.1.1. Test framework you used to develop your tests (e.g., JUnit, unittest, pytest, etc.):
- 3.1.2.Link to your GitHub folder where your automated unit tests are located.
- 3.1.3. An example of a test case. Include in your answer a GitHub link to the class being tested and to the test.
- 3.1.4. A print screen showing the result of the automated tests execution.

Grading criteria (3 points): You should have an adequate number of automated tests. They should be well written and match the features implemented in the aforementioned pull requests.

## Demo

TypeLock Demo: [Link to Demo](https://youtu.be/C2s3oM5v9yE)

## Code quality (Brock, Levi)

Describe how your team managed code quality. What were your policies, conventions, adopted best practices, etc. to foster high-quality code?

Our team has used a few conventions to help us in the engineering of our program. We us a lot of comments to explain what is going on so that if our other team members need to do something that calls a function from a different file, or if they need to know what type of information is being returned to their portion as a success or failure signal, they can go to that file and read the comments for that function. We also used a naming convention to make sure everything made sense. We didn’t have specific names that we needed to use for certain things, we just wanted to have the names of variables make sense so that the whole team knows what they are used for. A good example of both conventions being used is shown in this code snippet:

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

I learned how to use TKInter pretty well during this project, and because of that I learned that a lot of premade gui’s have small incompatibilities when using different devices such as the inability to change the background color of buttons when using it with a MacOS.

Grading criteria (2 points): Adequate reflection about problems and solutions, clear description with adequate use of language.
