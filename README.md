# Airport Scheduling System

## Description
This program simulates an airport scheduling system for KLIA International Airport, allowing users to request landing and take-off slots. The program maintains a schedule of available slots for a 24-hour period and prevents double booking of the same time slot.

## Features
- Request a landing slot
- Request a take-off slot
- Display the current schedule of slots
- Prevents double booking of slots

## How to Use
1. Run the program.
2. Choose an option from the menu:
   - **1**: Request for Landing
   - **2**: Request for Take-off
   - **3**: Display the schedule
   - **4**: Exit the program
3. If requesting a landing or take-off slot, enter the desired hour (1-24). If the slot is available, it will be reserved.
4. View the schedule to check booked slots.

## Program Structure
- **main()**: Manages user input and menu selection.
- **landing_takeoff(int choice)**: Handles landing and take-off slot requests.
- **slots_left(int land_hour, int take_hour)**: Updates slot availability and prevents double booking.
- **display_menu()**: Displays the landing and take-off schedule in a structured format.

## Compilation and Execution
To compile and run the program, use the following commands:
```sh
gcc airport_scheduler.c -o airport_scheduler
./airport_scheduler
```

## Notes
- The program initializes with all slots available.
- Once a slot is booked, it cannot be reassigned.
- Landing slots are marked with **L**, and take-off slots are marked with **T** in the schedule.

## Author
Louis Chua Khai Yi

