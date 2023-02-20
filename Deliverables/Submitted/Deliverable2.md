# D.2 Requirements

Group 04 – “TypeLock”\
Date: Feb 19, 2023\
Location: Flagstaff, Arizona\
Group Members: Taylor Nielsen, Eduardo De La Rosa, Alexander Siegel, Brock Heinz, Levi Watlington, Michael Vertin

## 1. Positioning

### 1.1 Problem statement

The issue with having many accounts with unique individual passwords affects all internet users who struggle to memorize each individual set of account/password combination and impacts the users time and the account security.

### 1.2. Product Position Statement

For internet users who have multitudes of passwords, TypeLock is an account login system that uses metrics such as type speed and accuracy to correctly identify the user without the need of a dedicated password; unlike the current system of memorizing unique passwords and their matching accounts, our product does not rely on exact memorization and correct input of a short password but rather the input of a given phrase or paragraph the user has seen before.

### 1.3. Value proposition

TypeLock allows internet users easy log in to their accounts without the need to memorize individual passwords by analyzing their typing metrics to grant them access to their accounts.

Internet users that have difficulty keeping track of their passwords and logging into their individual accounts.

## 2. Stakeholders

**Users**: Companies looking for the next big login method, people that don't want to remember many different passwords.\
**Competitors**: FaceID and Fingerprint Scan password companies.\
**Detractors**: People that don't think reading someone's typing style is secure enough for a password.\
**Developers**: Alexander Siegel, Brock Heinz, Eduardo De La Rosa, Levi Watlington, Michael Vertin, Taylor Nielsen

## 3. Functional requirements (features)

- Identify user based on how they type
- Account is secure from others
- Account is still easy to log into

## 4. Non-functional requirements

1. Readability and maintainability\
Three sections: back-end, front-end, server. Each is written in the same language. \
Importance: Partitioning each part will create modularity and help identify input/output needed for each section.
Each section is written in the same language so that functions in each section are compatible. \
Verifiability: No section computes something that another section was assigned, each section is written in one language.
2. Reliability\
Available to users on different devices\
Importance: Users are able to access their account several devices, so that their devices are compatible. \
Verifiability: The system can be used on most device types, and does not limit the account to be used on exactly one device.
3. Functionally suitable\
Backend algorithms correctly identify users by their typing style. \
Importance: Users need to be able to log into their account, and not be able to log into others' accounts. \
Verifiability: A user is verified by the system when using their account, and rejected by the system when using another user's account.

## 5. MVP

Even in the final version, any servers or user login systems we add will end up serving as a practical demonstration of the core product-- which is
fundamentally a **tool** to be used in _other_ products.
Therefore a minimum viable product for this program, since its primary function is its entire value, would be an isolated version of our typing recognition method.
That MVP must be able to build a typing style dataset from a sample size of user inputs, and recognize if further inputs of the phrase match the style within a
certain tolerance level. We will need to validate that the system is able to accurately recognize style at a statistically consistent rate via
iterative implementation and user testing cycles.

## 6. Use cases

### 6.1. Use case diagram

![Use Case Diagram](/UseCaseDiagram "Use case for Typelock")

### 6.2. Use case descriptions

**Use case 1:**

**Use Case**: Logging into bank account\
**Actor**: Internet user\
**Description**: The internet user has opted into online banking and needs to log into his banking app to transfer money, to do this they use the TypeLock system to gain access.\
**Preconditions**: Internet user must have an online banking system, money to transfer and access to a keyboard.

**Main Flow**:

1. User enters unique user/account name.
2. User then types passphrase into metric analyzing box.
3. TypeLock compares typing biometrics with database.
4. TypeLock confirms user identity and grants account access.

**Use case 2:**

**Use Case**: Logging into FAFSA website\
**Actor**: FAFSA applicant\
**Description**: The applicant needs to login to the Fafsa website for the first time this year to renew it for the next school year. The TypeLock program will observe the typing and discern who the user is to decide to grant access or not.\
**Preconditions**: Must have a FAFSA account

**Main Flow**:

1. Applicant enters username
2. Applicant types prompted text into the password field
3. TypeLock observes typing style and compares with those in its database to confirm and grant access

**Use case 3:**

**Use Case**: Initializing style dataset for user\
**Actor**: Login User\
**Description**: A user needs to create an account on a Typelock enabled website. The program will generate a passphrase and prompt the user to type it a specific number of times, allowing them to login with their typing style for the given phrase.\
**Preconditions**: User must not have an account, or is choosing to generate a new style key for a preexisting account\
**Postconditions**: A style dataset has been created for the user to be referenced in future login attempts\

**Main Flow**:

1. User opts to create an account
2. TypeLock generates a string of moderate length for the reference phrase
3. User is allowed any number of practice runs to type the phrase
4. User ends practice phase
5. User types the phrase with a determined number of repetitions
6. TypeLock compiles the input statistics from each repetition into dataset attributed to user
7. [User finishes account creation]

**Alternative Flow**:

1. User opts to create new style key
2. Website prompts user to verify old style key or provide alternate form of authentication
3. TypeLock produces reference phrase and user provides dataset as normal
4. User confirms new style key

**Use case 4:**

**Use Case**: Use Case: Creating a Typing Style Dataset for User Authentication\
**Actor**: User\
**Description**: A user wants to create a Typing Style Dataset for future use in logging in to a TypeLock enabled website. The program prompts the user to type a specific reference phrase a few times, which is then used to generate a dataset based on the user's unique typing style. This dataset is then saved for future use, allowing the user to log in to their account using their typing style for the given reference phrase.\
**Preconditions**: User must have an account on a TypeLock enabled website.\
**Postconditions**: A typing style dataset has been created for the user to be referenced in future login attempts.\

**Main Flow**:

1. User selects "Create Typing Style Dataset" option from the website.
2. The website generates a reference phrase of moderate length for the user to type.
3. User is prompted to type the reference phrase a specific number of times.
4. User types the reference phrase for the determined number of repetitions.
5. Typelock compiles the input statistics from each repetition into a dataset attributed to the user.
6. The typing style dataset is saved for future use in logging in to the website.

**Alternative Flow**:

1. User selects "Create New Typing Style Key" option from the website.
2. The website prompts the user to verify old typing style key or provide alternate form of authentication.
3. Typelock generates a reference phrase for the user to type.
4. User types the reference phrase as per the main flow.
5. The website prompts the user to confirm the new typing style key.
6. The new typing style key is saved for future use in logging in to the website.

**Use case 5:**

**Use Case**: [INSERT HERE]\
**Actor**: [INSERT HERE]\
**Description**: [INSERT HERE]\
**Preconditions**: [INSERT HERE]\
**Postconditions**: [INSERT HERE]\
**Main Flow**:

1. [INSERT HERE]
2. [INSERT HERE]

**Alternative Flow**: [INSERT HERE]

**Use case 6:**

**Use Case**: [INSERT HERE]\
**Actor**: [INSERT HERE]\
**Description**: [INSERT HERE]\
**Preconditions**: [INSERT HERE]\
**Postconditions**: [INSERT HERE]\
**Main Flow**:

1. [INSERT HERE]
2. [INSERT HERE]

**Alternative Flow**: [INSERT HERE]

## 7. User stories

**User story 1**: As a user, I want to be able to reset my typing metrics if my typing improves overtime, so that my log in metrics continue to match those in the database.\
Priority Level: 6\
Estimated Hours: 48 hours

**User story 2**: As a user, I want to be able to send a secure code to my phone, confirming my identity if my metrics don't work after a few tries, so I can still log in.\
Priority Level: 10\
Estimated Hours: 76 hours

**User story 3**: As a developer, I want to be able to switch keyboards and still log into my account\
Priority Level: 4\
Estimated Hours: 60 hours

**User story 4**: As a user, I want to be able to log in when its cold and my fingers aren't working\
Priority Level: 5\
Estimated Hours: 60 hours

**User story 5**: As a busy executive, I want a more efficient and secure way to log into my accounts, so that I can save time and eliminate the need to remember multiple passwords.\
Priority Level: 7\
Estimated Hours: 8

**User story 6**: As a small business owner, I want a more secure login system for my employees, so that I can protect my customers' sensitive information and give my employees a convenient and secure way to access their accounts.\
Priority Level: 5\
Estimated Hours: 16

**User story 7**: As a security consultant, I want to be able to circumvent the threat of password leaks so my clients can keep their information safe.\
Priority Level: 7\
Estimated Hours: 80

**User story 8**: As a novice tech user, I want to be able to use a more flexible login system so I don't get locked out of my accounts.\
Priority Level: 6\
Estimated Hours: 40

**User story 9**: As an elderly person, I want an easier way to login so I don’t have to remember so many passwords.\
Priority Level: 7\
Estimated Hours: 12

**User story 10**: As a college student, I want a more secure login so I don’t have to constantly change my passwords.\
Priority Level: 8\
Estimated Hours: 15

**User story 11**: As a busy person, I want a quick and consistent way to log in to my account, so that I do not need to spend excessive time logging in.\
Priority Level: 9\
Estimated Hours: 20

**User story 12**: As a forgetful person, I want to not need to remember a password, so that I do not need to remember information to log in.\
Priority Level: 8\
Estimated Hours: 9\

## 8. Issue Tracker

**Issue Tracker Link:** https://github.com/Gus-Siegel/ProjectPassword/issues

<img width="1440" alt="Screen Shot 2023-02-19 at 10 32 11 PM" src="https://user-images.githubusercontent.com/90239263/220017356-e6f5a90b-f9c5-49b1-9731-7427a5f9c25d.png">

