# D.5 Design

Group 04 – “TypeLock”\
Date: April 9, 2023\
Location: Flagstaff, Arizona\
Group Members: Taylor Nielsen, Eduardo De La Rosa, Alexander Siegel, Brock Heinz, Levi Watlington, Michael Vertin

## Description

As internet usage diversifies and expands, many users face the challenge of remembering multiple passwords for their various accounts, leading to time-consuming processes and compromised security. TypeLock is a secure account login system designed to address this issue by employing typing metrics, such as speed and accuracy, to identify users without relying on traditional passwords. Instead of necessitating the precise memorization and entry of distinct short passwords, TypeLock utilizes the user's ability to type a previously seen phrase or paragraph, identifying them through their unique typing metrics. This method streamlines the login process, enabling users to access their accounts without the burden of memorizing multiple passwords or sifting through a password list or file, as their typing metrics serve as a unique identifier. TypeLock is an ideal solution for those struggling to remember passwords and seeking a more secure and convenient way to access their online accounts.

The primary objective of the system is to establish a secure, reliable, and user-friendly login process that enhances account security. To achieve this, the system accurately and efficiently identifies users based on typing metrics like speed and accuracy, while also facilitating easy setup and management of typing style datasets. The system comprises three main components: Back-end, Front-end, and Client-Server relationship. The Back-end employs algorithms to accurately identify users by their typing style, ensuring secure account access and preventing unauthorized entry. The Back-end's algorithm compares two lists of keypresses along with their associated timings, identifying spelling errors and calculating the ratio of average time delay differences. Constants are employed to determine if the input matches the user's recorded typing style. The Front-end focuses on user interface design, creating a reference passphrase for users to enter and implementing the algorithm to capture user input for processing. The Client and Server act as the central elements that integrate the Front-end design and data with the Back-end algorithm. Notably, the Front-end is developed in Python, while the Back-end uses C++. The primary distinction between these languages is their approach to endianness. Both Python and C++ store integers based on the endianness of the processor running the program. To avoid issues when passing data between end hosts with different endian storage systems, conversions are performed on the client and server sides before transferring information through the Client-Server connection.

## Architecture 

Present a diagram of the high-level architecture of your system. Use a UML package diagram to describe the main modules and how they interrelate.
See some examples at:

- [https://www.uml-diagrams.org/package-diagrams-examples.html](https://www.uml-diagrams.org/package-diagrams-examples.html)

Make clear the layers of your architecture (if they exist) as described in:

- [https://www.uml-diagrams.org/multi-layered-application-uml-model-diagram-example.html](https://www.uml-diagrams.org/multi-layered-application-uml-model-diagram-example.html)

Provide a brief rationale of your architecture explaining why you designed it that way.

The reason we went with this kind of architecture is so that we could future proof control and security into newer versions of our product. We wanted to have the user to have as little access as possible to our product. To do this we implemented a 3 layer design that was split into a user interface layer, a network layer, and a backend layer. The goal of the user interface layer was to clearly display what the user must do to use our product. The network layers goal was to seperate what was running on the users computer to give us more control of who was logging into our product. The goal of the backend layer was to verify that the user is who they said they were, and not some random person attempting to use the user's credentials. 


## Class diagram (Brock)

Present a refined class diagram of your system, including implementation details such as visibilities, attributes to represent associations, attribute types, return types, parameters, etc. The class diagram should match the code you have produced so far, but not be limited to it (e.g., it can contain classes not implemented yet).

The difference between this class diagram and the one that you presented in D.3 is that the last focuses on the conceptual model of the domain while the former reflects the implementation. Therefore, the implementation details are relevant in this case.

## Sequence diagram

![Sequence Diagram](https://cdn.discordapp.com/attachments/856622349516144665/1094706096297480302/CS386_GroupProject_SequenceDiagram.png)

## Design patterns (Taylor)

Split this section into 2 subsections. For each subsection, present a UML class diagram showing the application of a design pattern to your system (a different pattern for each section). Each class diagram should contain only the classes involved in the specific pattern (you don’t need to represent the whole system). Choose patterns from two different categories: Behavioral, Structural, and Creational. You are not limited to design patterns studied in class.

Your system may not be appropriate for any design pattern. In this case, for didactic purposes, be creative and extend a little bit the scope of your system to make the design patterns appropriate.

Implement each design pattern in your system and provide GitHub links to the corresponding classes. Example (the links are just illustrative):

![exmaple](https://cdn.discordapp.com/attachments/1093988004302950531/1093988073316044971/Screenshot_2023-04-07_at_12.57.17_PM.jpg)

## Design principles (Levi)

How does your design observe the SOLID principles? Provide a short description of the following principles giving concrete examples from your classes.

Our design follows the Single Responsibility Principle since when we are using classes in our code, such as ‘class Client’ from the python client server code ‘socket_clientClass.py’, they are made for a singular purpose. In this case that purpose is connecting the client to the server to login.

Our design doesn’t follow the Open-Closed Principle since although we do use a class there is no reason to extend it since there is only one type of information it works with so there is no need to extend the class since nothing needs to be done without modifying the code.

Our design doesn’t follow the Liskov Substitution principle since we don’t use any subclasses or derived classes in the first place. We just have one class with no parent or child classes attached to it.

Our design follows the Interface Segregation Principle since we only have one type of interface that clients using our program will be familiar with and doesn’t force any extra steps to be had in the program. Every client gives the same type of information to the interface so there is no difference in the processing of it all.

Our design follows the Dependency Inversion Principle since our code only depends on the input of the user to work like it was designed to do. If the different aspects of our code have the right inputs given to them they will work regardless of if it was sent by another part of the code or not.
