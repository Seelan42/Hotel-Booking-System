#include <iostream>
#include <string>
#include <vector>


using namespace std;

// Structure to store room details
struct Room {
    int roomNumber;
    string roomType;
    bool isBooked;
    string customerName;
};

// Function to display available rooms
void displayAvailableRooms(vector<Room> &rooms) {
    cout << "\nAvailable Rooms:\n";
    for (Room &room : rooms) {
        if (!room.isBooked) {
            cout << "Room Number: " << room.roomNumber << ", Type: " << room.roomType << "\n";
        }
    }
}

// Function to book a room
void bookRoom(vector<Room> &rooms) {
    int roomNumber;
    string customerName;

    cout << "\nEnter Room Number to Book: ";
    cin >> roomNumber;

    for (Room &room : rooms) {
        if (room.roomNumber == roomNumber && !room.isBooked) {
            cout << "Enter your name: ";
            cin >> customerName;
            room.isBooked = true;
            room.customerName = customerName;
            cout << "Room " << roomNumber << " has been successfully booked under the name " << customerName << ".\n";
            return;
        }
    }
    cout << "Room not available or already booked.\n";
}

// Function to cancel a booking
void cancelBooking(vector<Room> &rooms) {
    int roomNumber;
    string customerName;

    cout << "\nEnter Room Number to Cancel Booking: ";
    cin >> roomNumber;

    for (Room &room : rooms) {
        if (room.roomNumber == roomNumber && room.isBooked) {
            cout << "Enter your name to confirm cancellation: ";
            cin >> customerName;
            if (room.customerName == customerName) {
                room.isBooked = false;
                room.customerName = "";
                cout << "Booking for Room " << roomNumber << " has been successfully canceled.\n";
            } else {
                cout << "Name mismatch. Cancellation failed.\n";
            }
            return;
        }
    }
    cout << "Room not found or not booked.\n";
}

// Main function
int main() {
    vector<Room> rooms = {
        {101, "Single", false, ""},
        {102, "Double", false, ""},
        {103, "Suite", false, ""},
        {104, "Single", false, ""},
        {105, "Double", false, ""}
    };

    int choice;

    do {
        cout << "\nHotel Room Booking System\n";
        cout << "1. Display Available Rooms\n";
        cout << "2. Book a Room\n";
        cout << "3. Cancel a Booking\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAvailableRooms(rooms);
                break;
            case 2:
                bookRoom(rooms);
                break;
            case 3:
                cancelBooking(rooms);
                break;
            case 4:
                cout << "Exiting the system...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
