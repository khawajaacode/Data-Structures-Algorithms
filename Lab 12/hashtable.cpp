#include <iostream>
#include <string>

using namespace std;

// Structure for a user node in the linked list
struct UserNode {
    string email;
    string password;
    UserNode* next;
};

// Hash table with 10 buckets, each initialized to nullptr
UserNode* table[10] = {nullptr};

// Hash function to compute the index for a given email
int hashFunction(string email) {
    int sum = 0;
    for (char c : email) {
        sum += c; // Add ASCII value of each character
    }
    return sum % 10; // Return index between 0 and 9
}

// Function to insert a new user into the hash table
void insert(string email, string password) {
    int index = hashFunction(email);
    UserNode* newNode = new UserNode{email, password, table[index]};
    table[index] = newNode; // Add new node at the start of the list
}

// Function to search for a user's password by email
string search(string email) {
    int index = hashFunction(email);
    UserNode* current = table[index];
    while (current != nullptr) {
        if (current->email == email) {
            return current->password; // Found the email, return password
        }
        current = current->next;
    }
    return ""; // Email not found
}

int main() {
    int numUsers;
    cout << "How many users to add? ";
    cin >> numUsers;
    
    // Add users to the hash table
    for (int i = 0; i < numUsers; i++) {
        string email, password;
        cout << "Enter email: ";
        cin >> email;
        cout << "Enter password: ";
        cin >> password;
        insert(email, password);
    }
    
    // Search for users
    string input;
    cout << "Enter email to search or 'quit' to exit: ";
    cin >> input;
    while (input != "quit") {
        string password = search(input);
        if (!password.empty()) {
            cout << "Password: " << password << endl;
        } else {
            cout << "User not found." << endl;
        }
        cout << "Enter email to search or 'quit' to exit: ";
        cin >> input;
    }
    
    return 0;
}