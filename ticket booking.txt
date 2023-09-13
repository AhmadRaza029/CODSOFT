#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 5;
const double TICKET_PRICE = 10.0;

// Function to display the seating chart
void displaySeatingChart(const vector<vector<char>>& seats) {
    cout << "Seating Chart:\n";
    for (int row = 0; row < NUM_ROWS; ++row) {
        for (int col = 0; col < NUM_COLS; ++col) {
            cout << setw(3) << seats[row][col];
        }
        cout << endl;
    }
}

// Function to calculate the total cost of selected seats
double calculateTotalCost(const vector<vector<char>>& seats, const vector<pair<int, int>>& selectedSeats) {
    double totalCost = 0.0;
    for (const auto& seat : selectedSeats) {
        totalCost += TICKET_PRICE;
    }
    return totalCost;
}

int main() {
    vector<vector<char>> seats(NUM_ROWS, vector<char>(NUM_COLS, 'O'));  // 'O' represents available seats
    vector<pair<int, int>> selectedSeats;  // Stores the selected row and column of seats

    char choice;
    do {
        int row, col;
        displaySeatingChart(seats);

        cout << "Select a movie seat (row column): ";
        cin >> row >> col;

        if (row < 1 || row > NUM_ROWS || col < 1 || col > NUM_COLS || seats[row - 1][col - 1] == 'X') {
            cout << "Invalid seat selection. Please choose a valid available seat.\n";
        } else {
            seats[row - 1][col - 1] = 'X';  // 'X' represents booked seats
            selectedSeats.push_back(make_pair(row, col));
            cout << "Seat " << row << ", " << col << " booked.\n";
        }

        cout << "Do you want to book another seat? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    double totalCost = calculateTotalCost(seats, selectedSeats);

    cout << "Booking Summary:\n";
    cout << "Total seats booked: " << selectedSeats.size() << endl;
    cout << "Total cost: $" << totalCost << endl;

    return 0;
}
