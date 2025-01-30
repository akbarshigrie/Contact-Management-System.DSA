/*
INTRODUCTION
The Contact Management System is a simple, user-friendly project de
designed to store and manage personal and professional contacts. T
he system enables users to:
Add new contacts.
Display all contacts in a tabular format, sorted alphabetically by name.
Search for a contact by name.
Delete a contact by name.

FEATURES
1. Add Contact
2. Display Contact in Tabular Form
3. Search contact
4. Delete Contact

DATA STRUCTURES:
Array:
Contacts are stored in a fixed-size array of Contact structures.
The maximum number of contacts is defined by MAX_CONTACTS.

Sorting:
Uses the Bubble Sort algorithm to arrange contacts alphabetically by name.

*/

#include <iostream>
#include <iomanip> // For setw
#include <string>
using namespace std;

#define MAX_CONTACTS 500 // Maximum number of contacts

// Structure for Contact
struct Contact {
    string name;
    string phone;
    string email;
    string city;
};

// Class for Contact Management System
class ContactManagementSystem {
private:
    Contact contacts[MAX_CONTACTS];
    int contactCount;

    // Helper function to find a contact index by name
    int findContactIndex(string name) {
        for (int i = 0; i < contactCount; i++) {
            if (contacts[i].name == name) {
                return i;
            }
        }
        return -1;
    }

    // Helper function to sort contacts alphabetically by name
    void sortContacts() {
        for (int i = 0; i < contactCount - 1; i++) {
            for (int j = 0; j < contactCount - i - 1; j++) {
                if (contacts[j].name > contacts[j + 1].name) {
                    swap(contacts[j], contacts[j + 1]);
                }
            }
        }
    }

public:
    // Constructor
    ContactManagementSystem() : contactCount(0) {}

    // Add a new contact
    void addContact(string name, string phone, string email, string city) {
        if (contactCount >= MAX_CONTACTS) {
            cout << "Contact list is full! Cannot add more contacts." << endl;
            return;
        }

        contacts[contactCount] = {name, phone, email, city};
        contactCount++;
        sortContacts(); // Maintain alphabetical order
        cout << "\nContact added successfully!" << endl;
    }

    // Display all contacts in tabular form
    void displayContacts() {
        if (contactCount == 0) {
            cout << "\nNo contacts to display!" << endl;
            return;
        }

        // Display table headers
        cout << left << setw(20) << "Name" 
             << setw(20) << "Contact No." 
             << setw(30) << "Email" 
             << setw(20) << "City" 
             << endl;

        cout << string(90, '-') << endl; // Separator line

        // Display each contact in tabular format
        for (int i = 0; i < contactCount; i++) {
            cout << left << setw(20) << contacts[i].name
                 << setw(20) << contacts[i].phone
                 << setw(30) << contacts[i].email
                 << setw(20) << contacts[i].city
                 << endl;
        }
    }

    // Search for a contact by name
    void searchContact(string name) {
        int index = findContactIndex(name);
        if (index != -1) {
            cout << "Contact Found:" << endl;
            cout << "Name: " << contacts[index].name 
                 << ", Phone: " << contacts[index].phone 
                 << ", Email: " << contacts[index].email 
                 << ", City: " << contacts[index].city << endl;
        } else {
            cout << "\nContact with name '" << name << "' not found." << endl;
        }
    }

    // Search for contacts by city
    void searchContactByCity(string city) {
        bool found = false;
        cout << "\nContacts in city '" << city << "':" << endl;
        cout << left << setw(20) << "Name" 
             << setw(20) << "Contact No." 
             << setw(30) << "Email" 
             << setw(20) << "City" 
             << endl;
        cout << string(90, '-') << endl; // Separator line

        for (int i = 0; i < contactCount; i++) {
            if (contacts[i].city == city) {
                found = true;
                cout << left << setw(20) << contacts[i].name
                     << setw(20) << contacts[i].phone
                     << setw(30) << contacts[i].email
                     << setw(20) << contacts[i].city
                     << endl;
            }
        }

        if (!found) {
            cout << "\nNo contacts found in city '" << city << "'." << endl;
        }
    }

    // Delete a contact by name
    void deleteContact(string name) {
        int index = findContactIndex(name);
        if (index == -1) {
            cout << "\nContact with name '" << name << "' not found." << endl;
            return;
        }

        // Shift all contacts after the deleted one to the left
        for (int i = index; i < contactCount - 1; i++) {
            contacts[i] = contacts[i + 1];
        }
        contactCount--;
        cout << "\nContact with name '" << name << "' has been deleted." << endl;
    }
};

int main() {
    ContactManagementSystem cms;
    int choice;
    string name, phone, email, city;

    while (true) {
        cout << "\n--- Contact Management System Menu ---" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Display All Contacts" << endl;
        cout << "3. Search Contact by Name" << endl;
        cout << "4. Search Contacts by City" << endl;
        cout << "5. Delete Contact by Name" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Name: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, name);
                cout << "Enter Phone: ";
                cin >> phone;
                cout << "Enter Email: ";
                cin >> email;
                cout << "Enter City: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, city);
                cms.addContact(name, phone, email, city);
                break;

            case 2:
                cms.displayContacts();
                break;

            case 3:
                cout << "Enter Name to Search: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, name);
                cms.searchContact(name);
                break;

            case 4:
                cout << "Enter City to Search Contacts: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, city);
                cms.searchContactByCity(city);
                break;

            case 5:
                cout << "Enter Name to Delete: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, name);
                cms.deleteContact(name);
                break;

            case 6:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again!" << endl;
        }
    }

    return 0;
}
