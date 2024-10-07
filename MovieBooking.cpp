#include<bits/stdc++.h>
using namespace std;

const int rows = 5;
const int cols = 10;
char seats[rows][cols];

// Function to initialize all seats to available ('A' for Available)
void initializeSeats() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            seats[i][j] = 'A';  // A stands for Available
        }
    }
}

// Function to display the current seating arrangement
void displaySeats() {
    cout << "Current seating arrangement: " << endl;
    cout << "Seats: (A = Available, B = Booked)" << endl;
    cout << "   ";
    for (int i = 0; i < cols; i++) {
        cout << i + 1 << " ";  // Column numbers
    }
    cout << endl;

    for (int i = 0; i < rows; i++) {
        cout << "Row " << i + 1 << ": ";
        for (int j = 0; j < cols; j++) {
            cout << seats[i][j] << " ";  // Seat availability
        }
        cout << endl;
    }
}

// Function to book a seat
void bookTicket() {
    int row, col;
    cout << "Enter row number (1-" << rows << "): ";
    cin >> row;
    cout << "Enter seat number (1-" << cols << "): ";
    cin >> col;

    // Validating the input
    if (row < 1 || row > rows || col < 1 || col > cols) {
        cout << "Invalid seat selection. Please choose a valid seat." << endl;
        return;
    }

    // Check if the seat is already booked
    if (seats[row - 1][col - 1] == 'B') {
        cout << "Sorry, this seat is already booked. Please choose another one." << endl;
    } else {
        // Book the seat
        seats[row - 1][col - 1] = 'B';
        cout << "Seat successfully booked!" << endl;
    }
}

// Function to display the number of available seats
void displayAvailableSeats() {
    int availableSeats = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (seats[i][j] == 'A') {
                availableSeats++;
            }
        }
    }
    cout << "Total available seats: " << availableSeats << endl;
}

int main() {
    int choice;
    initializeSeats();  // Initialize all seats as available

    do {
        // Display menu
        cout << "\n==== Movie Ticket Booking System ====" << endl;
        cout << "1. View available seats" << endl;
        cout << "2. Book a ticket" << endl;
        cout << "3. Check number of available seats" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displaySeats();
            break;
        case 2:
            bookTicket();
            break;
        case 3:
            displayAvailableSeats();
            break;
        case 4:
            cout << "Exiting the system. Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}


