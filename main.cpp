#include <iostream>
#include <iomanip> // For formatting outputs
#include <string>
#include <cstdlib>  // environment management
#include <conio.h> // For get console inputs

using namespace std;

// Structure to represent a Booking
struct Booking {
    string personName;
    string personNIC;
    string phoneNumber;
    string checkInDate;
    string checkOutDate;
};

// Structure to represent a Room
struct Room {
    string type;
    string acStatus;
    string identifier;
    string status;
    double price;
    Booking booking; // Booking details associated with the room
};

// Function prototypes
void adminLogin();
void userLogin();
string getPassword();
void clearScreen(); // Function to clear the screen
void viewRooms(); // Function to view all rooms
void bookRoom(); // Function to book a room
void adminMenu(); // Function to display the admin menu
void searchRoom();
void printRoomInfo();
void searchRoomDetails(int room_number);
void backadmin();
void bookingDetails();
void prepareBill();
void userMenu();
void backuser();

// Array to store room details
Room room_info[12] = {
    {"single room", "ac", "1", "available", 100, {"", "", "", "", ""}},
    {"single room", "non-ac", "2", "available", 80, {"", "", "", "", ""}},
    {"double room", "ac", "3", "available", 150, {"", "", "", "", ""}},
    {"double room", "non-ac", "4", "available", 120, {"", "", "", "", ""}},
    {"twin room", "ac", "5", "available", 150, {"", "", "", "", ""}},
    {"twin room", "non-ac", "6", "available", 120, {"", "", "", "", ""}},
    {"family room", "ac", "7", "available", 200, {"", "", "", "", ""}},
    {"family room", "non-ac", "8", "available", 160, {"", "", "", "", ""}},
    {"standard room", "ac", "9", "available", 120, {"", "", "", "", ""}},
    {"standard room", "non-ac", "10", "available", 90, {"", "", "", "", ""}},
    {"deluxe room", "ac", "11", "available", 180, {"", "", "", "", ""}},
    {"deluxe room", "non-ac", "12", "available", 140, {"", "", "", "", ""}}
};

int main() {
    int choice;


    cout << "\n\n";
    cout << "     =========================================================\n";
    cout << "     |                                                       |\n";
    cout << "     |           \033[1;32m***   Welcome to Moon Hotel   ***\033[0m           |\n";
    cout << "     |                                                       |\n";
    cout << "     =========================================================\n";
    cout << "     |                                                       |\n";
    cout << "     | 1. User Login                                         |\n";
    cout << "     |                                                       |\n";
    cout << "     | 2. Admin Login                                        |\n";
    cout << "     |                                                       |\n";
    cout << "     | 3. Exit Program                                       |\n";
    cout << "     |                                                       |\n";
    cout << "     =========================================================\n\n";
    cout << "     Enter your choice: ";
    cin >> choice;

    // Change between user choices
    switch (choice) {
        case 1:
            userLogin();
            break;
        case 2:
            adminLogin();
            break;
        case 3:
            cout << "\n     \033[1;32mExiting the program. Goodbye!\033[0m" << endl;
            break;
        default:
            cout << "\n     \033[1;32mInvalid choice. Please try again.\033[0m" << endl;
            break;
    }

    return 0;
}

// Function to input password securely
string getPassword() {
    string password = "";
    char ch;

    // Loop until Enter key is pressed
    while ((ch = _getch()) != '\r') {
        if (ch == '\b') { // If Backspace is pressed
            if (!password.empty()) { // If the password is not empty
                cout << "\b \b"; // Move the cursor back, print a space, and move the cursor back again
                password.pop_back(); // Remove the last character from the password
            }
        } else {
            cout << '*'; // Print a star (*) instead of the actual character
            password += ch; // Append the character to the password
        }
    }

    return password;
}

// Function to clear the screen
void clearScreen() {
    // Clear the screen using system command
    system("cls");
}

// Function to handle user login
void userLogin() {
    string username, password;

    // Clear the screen
    clearScreen();

    // Prompt for user login
    cout << "\n";
    cout << "     =========================================================\n";
    cout << "     |                                                       |\n";
    cout << "     |                 \033[1;32m***   User Login   ***\033[0m                |\n";
    cout << "     |                                                       |\n";
    cout << "     =========================================================\n";
    cout << "\n";
    cout << "       Enter username: ";
    cin >> username;
    cout << "\n";
    cout << "       Enter password: ";
    password = getPassword(); // Input password securely

    // Validate user credentials (Dummy validation for demonstration)
    if (username == "user" && password == "user") {
        clearScreen();
        cout << "\n     \033[1;32mUser login successful. Welcome, User!\033[0m" << endl;
        userMenu();
    } else {
        cout << "\n\n       \033[1;32mInvalid username or password!!!\033[0m" << endl;
        cout << "\n\n\n        1. Try again" << endl;
        cout << "\n        2. Back to main menu" << endl;
        cout << "\n       Enter your choice: ";
        int retryChoice;
        cin >> retryChoice;
        switch (retryChoice) {
            case 1:
                userLogin();
                break;
            case 2:
                clearScreen();
                cout << "\n   \033[1;32mReturned to Main Menu...\033[0m" << endl;
                main();
                return;
            default:
                cout << "\n   \033[1;32mInvalid choice. Please try again.\033[0m" << endl;
                break;
        }
    }
}

// Function to handle admin login
void adminLogin() {
    string username, password;

    // Clear the screen
    clearScreen();

    // Prompt for admin login
    cout << "\n";
    cout << "     =========================================================\n";
    cout << "     |                                                       |\n";
    cout << "     |                \033[1;32m***   Admin Login   ***\033[0m                |\n";
    cout << "     |                                                       |\n";
    cout << "     =========================================================\n";
    cout << "\n";
    cout << "       Enter username: ";
    cin >> username;
    cout << "\n";
    cout << "       Enter password: ";
    password = getPassword();

    // Validate admin credentials
    if (username == "admin" && password == "admin") {
        clearScreen();
        cout << "\n     \033[1;32mAdmin login successful. Welcome, Admin!\033[0m" << endl;
        adminMenu();
    } else {
        cout << "\n\n       \033[1;32mInvalid username or password!!!\033[0m" << endl;
        cout << "\n\n\n        1. Try again" << endl;
        cout << "\n        2. Back to main menu" << endl;
        cout << "\n       \033[1;32mEnter your choice: \033[0m";
        int retryChoice;
        cin >> retryChoice;
        switch (retryChoice) {
            case 1:
                adminLogin();
                break;
            case 2:
                clearScreen();
                cout << "\n   \033[1;32mReturned to Main Menu...\033[0m" << endl;
                main();
                return;
            default:
                cout << "\n   \033[1;32mInvalid choice. Please try again.\033[0m" << endl;
                break;
        }
    }
}

// Function to display the admin menu
void adminMenu() {
    int choice;

    // Display admin menu
    cout << "\n     =========================================================\n";
    cout << "     |                                                       |\n";
    cout << "     |                 \033[1;32m***   Admin Menu   ***\033[0m                |\n";
    cout << "     |                                                       |\n";
    cout << "     =========================================================\n";
    cout << "     |                                                       |\n";
    cout << "     | 1. View Rooms                                         |\n";
    cout << "     | 2. Search Rooms                                       |\n";
    cout << "     | 3. Book Rooms                                         |\n";
    cout << "     | 4. Booking Details                                    |\n";
    cout << "     | 5. Prepare Bill                                       |\n";
    cout << "     | 6. Back to main menu                                  |\n";
    cout << "     | 7. Exit                                               |\n";
    cout << "     |                                                       |\n";
    cout << "     =========================================================\n";
    cout << "\n     Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            clearScreen();
            printRoomInfo();
            backadmin();
            break;
        case 2:
            int room_number;
            clearScreen();
            cout << "\n     Enter the room number: ";
            cin >> room_number;
            searchRoomDetails(room_number);
            backadmin();
            break;
        case 3:
            clearScreen();
            bookRoom();
            backadmin();
            break;
        case 4:
            clearScreen();
            bookingDetails();
            backadmin();
            break;
        case 5:
            prepareBill();
            backadmin();
            break;
        case 6:
            clearScreen();
            cout << "\n   \033[1;32mReturned to Main Menu...\033[0m" << endl;
            main();
            break;
        case 7:
            cout << "\n     \033[1;32mExiting Admin Menu...\033[0m" << endl;
            break;
        default:
            cout << "     \033[1;32mInvalid choice. Please try again.\033[0m" << endl;
            break;
    }
}

// Function to display user menu
void userMenu() {
    int choice;

    // Display user menu
    cout << "\n     =========================================================\n";
    cout << "     |                                                       |\n";
    cout << "     |                 \033[1;32m***   User Menu   ***\033[0m                 |\n";
    cout << "     |                                                       |\n";
    cout << "     =========================================================\n";
    cout << "     |                                                       |\n";
    cout << "     | 1. View Rooms                                         |\n";
    cout << "     | 2. Book Room                                          |\n";
    cout << "     | 3. View Booking Details                               |\n";
    cout << "     | 4. View Bill                                          |\n";
    cout << "     | 5. Back to main menu                                  |\n";
    cout << "     | 6. Exit                                               |\n";
    cout << "     |                                                       |\n";
    cout << "     =========================================================\n";
    cout << "\n     Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            clearScreen();
            printRoomInfo();
            backuser();
            break;
        case 2:
            bookRoom();
            backuser();
            break;
        case 3:
            clearScreen();
            bookingDetails();
            backuser();
            break;
        case 4:
            prepareBill();
            backuser();
            break;
        case 5:
            clearScreen();
            cout << "\n     \033[1;32mReturned to Main Menu...\033[0m" << endl;
            main();
            break;
        case 6:
            cout << "\n     \033[1;32mExiting User Menu...\033[0m" << endl;
            break;
        default:
            cout << "\n     \033[1;32mInvalid choice. Please try again.\033[0m" << endl;
            break;
    }
}

// Function to go back to user menu or main menu
void backuser() {
    int menu_choice;
    cout << "\n       \033[1;32m1. Back to User Menu\033[0m" << endl;
    cout << "\n       \033[1;32m2. Back to Main Menu\033[0m" << endl;
    cout << "\n       Enter your choice: ";
    cin >> menu_choice;

    switch (menu_choice) {
        case 1:
            clearScreen();
            userMenu(); // Go back to the user menu
            break;
        case 2:
            clearScreen();
            main(); // Go back to the main menu
            break;
        default:
            cout << "\n     \033[1;32mInvalid choice. Please try again.\033[0m" << endl;
            break;
    }
}

// Function to go back to admin menu or main menu
void backadmin() {
    int menu_choice;
    cout << "\n       \033[1;32m1. Back to Admin Menu\033[0m" << endl;
    cout << "\n       \033[1;32m2. Back to Main Menu\033[0m" << endl;
    cout << "\n       Enter your choice: ";
    cin >> menu_choice;

    switch (menu_choice) {
        case 1:
            clearScreen();
            adminMenu(); // Go back to the admin menu
            break;
        case 2:
            clearScreen();
            main(); // Go back to the main menu
            break;
        default:
            cout << "\n       \033[1;32mInvalid choice. Please try again.\033[0m" << endl;
            break;
    }
}

// Function to print room information
void printRoomInfo() {
    cout << "\n     ==========================================================\n";
    cout << "     |                 \033[1;32m***   Room Details   ***\033[0m               |\n";
    cout << "     ==========================================================\n";
    cout << "     | Room No. | Room Type     | AC     | Status    | Price  |\n";
    cout << "     ==========================================================\n";

    for (int i = 0; i < 12; ++i) {
        cout << "     | ";
        cout << setw(8) << left << room_info[i].identifier << " | ";
        cout << setw(13) << left << room_info[i].type << " | ";
        cout << setw(6) << left << room_info[i].acStatus << " | ";
        cout << setw(8) << left << room_info[i].status << " | ";
        cout << setw(6) << left << room_info[i].price << " |" << endl;
    }

    cout << "     ==========================================================\n";
}

// Function to search for room details by room number
void searchRoomDetails(int room_number) {
    for (int i = 0; i < 12; ++i) {
        if (room_info[i].identifier == to_string(room_number)) {
            cout << "\n       Room Number: " << room_info[i].identifier << endl;
            cout << "       Room Type: " << room_info[i].type << endl;
            cout << "       AC Status: " << room_info[i].acStatus << endl;
            cout << "       Price: " << room_info[i].price << endl;
            cout << "\n       \033[1;32mBooking Details: \033[0m" << endl;
            cout << "       Status: " << room_info[i].status << endl;
            cout << "       Person Name: " << room_info[i].booking.personName << endl;
            cout << "       Person NIC: " << room_info[i].booking.personNIC << endl;
            cout << "       Phone Number: " << room_info[i].booking.phoneNumber << endl;
            cout << "       Check-in Date: " << room_info[i].booking.checkInDate << endl;
            cout << "       Check-out Date: " << room_info[i].booking.checkOutDate << endl;
            return;
        }
    }
    cout << "\n       Room number not found!" << endl;
}

// Function to book a room
void bookRoom() {
    string name, NIC, phoneNumber, checkInDate, checkOutDate;
    int room_number;

    // Clear the screen
    clearScreen();

    // Display room information
    printRoomInfo();

    // Input booking details
    cout << "\n\n     Enter the room number you want to book: ";
    cin >> room_number;

    // Check if the room is available
    for (int i = 0; i < 12; ++i) {
        if (room_info[i].identifier == to_string(room_number) && room_info[i].status == "available") {
            cout << "     Enter your name: ";
            cin >> name;
            cout << "     Enter your NIC: ";
            cin >> NIC;
            cout << "     Enter your phone number: ";
            cin >> phoneNumber;
            cout << "     Enter check-in date (MM.DD): ";
            cin >> checkInDate;
            cout << "     Enter check-out date (MM.DD): ";
            cin >> checkOutDate;

            // Update room status and booking details
            room_info[i].status = "booked";
            room_info[i].booking.personName = name;
            room_info[i].booking.personNIC = NIC;
            room_info[i].booking.phoneNumber = phoneNumber;
            room_info[i].booking.checkInDate = checkInDate;
            room_info[i].booking.checkOutDate = checkOutDate;

            cout << "\n\n       \033[1;32mRoom booked successfully!\033[0m" << endl;
            return;
        }
    }

    cout << "\n\n       \033[1;32mRoom not available or invalid room number!\033[0m" << endl;
}

// Function to display booking details
void bookingDetails() {
    cout << "\n     =========================================================\n";
    cout << "     |                 \033[1;32m***   Booking Details   ***\033[0m           |\n";
    cout << "     =========================================================\n";
    cout << "     | Room No. | Person Name    | Check-in    | Check-out |\n";
    cout << "     =========================================================\n";

    for (int i = 0; i < 12; ++i) {
        if (room_info[i].status == "booked") {
            cout << "     | ";
            cout << setw(8) << left << room_info[i].identifier << " | ";
            cout << setw(14) << left << room_info[i].booking.personName << " | ";
            cout << setw(9) << left << room_info[i].booking.checkInDate << " | ";
            cout << setw(12) << left << room_info[i].booking.checkOutDate << " |\n";
        }
    }

    cout << "     =========================================================\n";
}

// Function to prepare bill for booked rooms
void prepareBill() {
    clearScreen(); // Clear the screen

    cout << "\n     =========================================================\n";
    cout << "     |                    \033[1;32m***   Bill   ***\033[0m                   |\n";
    cout << "     =========================================================\n";

    // Variable to store total bill amount
    double totalBill = 0.0;

    // Loop through all rooms
    for (int i = 0; i < 12; ++i) {
        // Check if the room is booked
        if (room_info[i].status == "booked") {
            cout << "\n     Room Number: " << room_info[i].identifier << endl;
            cout << "     Person Name: " << room_info[i].booking.personName << endl;
            cout << "     Check-in Date: " << room_info[i].booking.checkInDate << endl;
            cout << "     Check-out Date: " << room_info[i].booking.checkOutDate << endl;
            cout << "     Price per night: " << room_info[i].price << endl;

            // Calculate number of days booked
            int daysBooked = stoi(room_info[i].booking.checkOutDate.substr(3)) - stoi(room_info[i].booking.checkInDate.substr(3));

            // Calculate total price for the booking
            double totalPrice = daysBooked * room_info[i].price;
            cout << "     Total Price: " << totalPrice << endl;

            // Add to the total bill
            totalBill += totalPrice;
        }
    }

    // Output total bill amount
    cout << "\n     Total Bill Amount: " << totalBill << endl;
    cout << "\n" <<endl;
}
