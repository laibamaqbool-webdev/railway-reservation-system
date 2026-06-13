**Introduction**:

The Railway Reservation System is a console-based application developed in C++ programming language. It is designed to simulate the basic working mechanism of a real-world railway ticket booking system.

This project is created as an academic assignment to demonstrate the practical implementation of Data Structures and Algorithms (DSA) concepts in a real-life scenario.

The system efficiently manages seat booking, cancellations, waiting lists, ticket searching, and train information using structured programming techniques.

 **Objective of the Project**:

The main objectives of this project are:

To understand and implement core Data Structures in C++
To simulate a real-world railway reservation system
To manage dynamic seat booking and cancellations
To handle overflow situations using a waiting list system
To improve problem-solving and programming logic skills

 **Key Features**:

 1. Seat Booking System
Users can book available seats using a unique Ticket ID
Seats are automatically assigned from available slots
Prevents double booking of the same seat
Handles full-capacity situations efficiently

 2. Waiting List Management (Queue Implementation)
Implemented using Queue (FIFO - First In First Out)
If seats are full, passengers are added to waiting list
Automatically assigns seat when one becomes available
Ensures fair processing of passengers

 3. Cancellation System (Stack Implementation)
Stores cancelled tickets using Stack (LIFO - Last In First Out)
Maintains history of cancellations
Helps track recently cancelled bookings

 4. Ticket Searching (Recursion)
Uses recursive function to search ticket ID
Efficient traversal of seat array
Displays seat number if ticket is found

5. Train Information System (Tree Structure)
Represents train data using Binary Tree
Uses inorder traversal for displaying train IDs
Demonstrates tree data structure concept

6. Seat Status Display
Shows real-time status of all seats
Displays whether seat is:
Empty
Booked (with Ticket ID)

**Data Structures Used**:

This project is based on fundamental DSA concepts:

Array → Seat management system
Queue → Waiting list handling (FIFO)
Stack → Cancellation history (LIFO)
Recursion → Ticket searching
Binary Tree → Train information display

**Functional Modules**:

The system provides the following options:

Book Seat 
Cancel Seat 
Display Seat Status 
Show Waiting List 
Show Cancellation History 
Search Ticket 
Display Train Information 
Exit System 

**Project Structure**:

Railway-Reservation-System/
│── main.cpp
│── README.md
│── /images
│     ├── main-menu.png
│     ├── booking.png
│     ├── seats.png

 **How to Run the Project**:

Step 1: Compile the code
g++ main.cpp -o railway

Step 2: Run the program
./railway

**Learning Outcomes**:

By completing this project, the following skills are improved:

Understanding of Data Structures in real applications
Logical thinking and problem-solving ability
C++ programming fundamentals
System design and modular programming
Handling real-world simulation problems

**Future Improvements**:

This project can be further enhanced by adding:

Graphical User Interface (GUI)
Database integration (MySQL or SQLite)
Online booking system
User login & authentication system
Admin panel for management
Real-time ticket availability system

**Developer**:

Laiba
Computer Science Student
Focus: C++ Programming & Data Structures (DSA)
