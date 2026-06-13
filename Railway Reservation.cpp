#include <iostream>
using namespace std;

// ---------------------- GLOBAL CONSTANTS ----------------------
const int SEAT_COUNT = 15;
const int QUEUE_SIZE = 10;
const int STACK_SIZE = 10;

// ---------------------- 1. ARRAY (Seat Booking) ----------------------
int seats[SEAT_COUNT] = {0};

// Function to show all seats
void displaySeats() {
    cout << "\n--- Current Seat Status ---\n";
    for (int i = 0; i < SEAT_COUNT; i++) {
        cout << "Seat " << i << ": ";
        if (seats[i] == 0)
            cout << "Empty\n";
        else
            cout << "Booked (Ticket ID: " << seats[i] << ")\n";
    }
}

// ---------------------- 2. QUEUE (Waiting List) ----------------------
int waitingList[QUEUE_SIZE];
int front = -1, rear = -1;

bool isWaitingFull() {
    return rear == QUEUE_SIZE - 1;
}

bool isWaitingEmpty() {
    return front == -1;
}

void addToWaiting(int ticketId) {
    if (isWaitingFull()) {
        cout << "Waiting list is full!\n";
        return;
    }
    if (front == -1) front = 0;
    waitingList[++rear] = ticketId;
    cout << "Added to waiting list.\n";
}

int removeFromWaiting() {
    if (isWaitingEmpty()) return -1;
    
    int id = waitingList[front];
    front++;

    if (front > rear) {
        front = rear = -1;
    }
    return id;
}

void showWaitingList() {
    cout << "\n--- Waiting List ---\n";
    if (isWaitingEmpty()) {
        cout << "No one in waiting list.\n";
        return;
    }
    for (int i = front; i <= rear; i++) {
        cout << waitingList[i] << " ";
    }
    cout << endl;
}

// ---------------------- 3. STACK (Cancellation History) ----------------------
int cancelStack[STACK_SIZE];
int top = -1;

bool isCancelFull() {
    return top == STACK_SIZE - 1;
}

bool isCancelEmpty() {
    return top == -1;
}

void pushCancel(int ticketId) {
    if (isCancelFull()) {
        cout << "Cancellation stack full!\n";
        return;
    }
    cancelStack[++top] = ticketId;
}

void showCancelHistory() {
    cout << "\n--- Cancellation History (Stack) ---\n";
    if (isCancelEmpty()) {
        cout << "No cancellations yet.\n";
        return;
    }
    for (int i = top; i >= 0; i--) {
        cout << cancelStack[i] << " ";
    }
    cout << endl;
}

// ---------------------- 4. RECURSION (Search Ticket) ----------------------
int searchTicketRec(int arr[], int index, int ticketId) {
    if (index == SEAT_COUNT) return -1;
    if (arr[index] == ticketId) return index;
    return searchTicketRec(arr, index + 1, ticketId);
}

// ---------------------- 5. TREE (Train Info) ----------------------
struct Train {
    int trainId;
    int left;
    int right;
};

// Static tree nodes (like BST)
Train trains[7] = {
    {50, 1, 2},   // Root
    {25, 3, 4},
    {75, 5, 6},
    {10, -1, -1},
    {40, -1, -1},
    {60, -1, -1},
    {90, -1, -1}
};

void inorder(int index) {
    if (index == -1) return;
    inorder(trains[index].left);
    cout << trains[index].trainId << " ";
    inorder(trains[index].right);
}

// ---------------------- 6. BOOKING FUNCTION ----------------------
void bookSeat() {
    int ticketId;
    cout << "Enter ticket ID to book: ";
    cin >> ticketId;

    bool booked = false;
    for (int i = 0; i < SEAT_COUNT; i++) {
        if (seats[i] == 0) {
            seats[i] = ticketId;
            cout << "Seat booked at position: " << i << endl;
            booked = true;
            break;
        }
    }

    if (!booked) {
        cout << "All seats full! Adding to waiting list...\n";
        addToWaiting(ticketId);
    }
}

// ---------------------- 7. CANCELLATION FUNCTION ----------------------
void cancelSeat() {
    int seatNo;
    cout << "Enter seat number to cancel: ";
    cin >> seatNo;

    if (seatNo < 0 || seatNo >= SEAT_COUNT || seats[seatNo] == 0) {
        cout << "Invalid or already empty!\n";
        return;
    }

    int oldTicket = seats[seatNo];
    seats[seatNo] = 0;
    pushCancel(oldTicket);

    cout << "Seat cancelled successfully.\n";

    // Add first waiting person if exists
    if (!isWaitingEmpty()) {
        int nextPassenger = removeFromWaiting();
        seats[seatNo] = nextPassenger;
        cout << "Waiting list passenger " << nextPassenger << " assigned to seat " << seatNo << endl;
    }
}

// ---------------------- 8. MAIN MENU ----------------------
int main() {
    int choice;

    while (true) {
        cout << "\n==========================\n";
        cout << "  RAILWAY RESERVATION SYSTEM\n";
        cout << "==========================\n";
        cout << "1. Book Seat\n";
        cout << "2. Cancel Seat\n";
        cout << "3. Show Seats\n";
        cout << "4. Show Waiting List\n";
        cout << "5. Show Cancellation History\n";
        cout << "6. Search Ticket (Recursion)\n";
        cout << "7. Show Train Info (Tree)\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: bookSeat(); break;
        case 2: cancelSeat(); break;
        case 3: displaySeats(); break;
        case 4: showWaitingList(); break;
        case 5: showCancelHistory(); break;
        case 6: {
            int id;
            cout << "Enter ticket ID to search: ";
            cin >> id;
            int pos = searchTicketRec(seats, 0, id);
            if (pos == -1)
                cout << "Ticket not found!\n";
            else
                cout << "Ticket found at seat: " << pos << endl;
            break;
        }
        case 7:
            cout << "Train IDs (Inorder Traversal): ";
            inorder(0);
            cout << endl;
            break;
        case 8:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
