#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void registerUser() {
    string username, password;
    
    cout << "\n--- User Registration ---\n";
    cout << "Enter a new username: ";
    cin >> username;
    
    cout << "Enter a new password: ";
    cin >> password;
    
    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << username << " " << password << endl;
        file.close();
        cout << "? Registration successful!\n";
    } else {
        cout << "? Error opening file.\n";
    }
}

bool loginUser() {
    string username, password, user, pass;
    
    cout << "\n--- User Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    
    cout << "Enter password: ";
    cin >> password;
    
    ifstream file("users.txt");
    if (file.is_open()) {
        while (file >> user >> pass) {
            if (user == username && pass == password) {
                cout << "? Login successful! Welcome, " << username << "!\n";
                return true;
            }
        }
        file.close();
    }
    
    cout << "? Login failed! Invalid credentials.\n";
    return false;
}


int main() {
    int choice;
    
    while (true) {
        cout << "\n========== Login & Registration System ==========\n";
        cout << "1?? Register\n";
        cout << "2?? Login\n";
        cout << "3?? Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "?? Exiting the system. Goodbye!\n";
                return 0;
            default:
                cout << "? Invalid choice. Please try again.\n";
        }
    }
    
    return 0;
}

