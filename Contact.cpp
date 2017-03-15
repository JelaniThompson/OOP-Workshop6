#include <iostream>
#include <regex>
#include "Contact.h"

using namespace std;

namespace communication {
    // Set the instance to a safe empty state
    Contact::Contact() {
        m_name[0] = 0;
        m_phoneNumbers[0] = 0;
        m_noOfPhoneNumbers = 0;
    }

    Contact::Contact(char name[21], long long *phoneNumbers, int noOfPhoneNumbers) {
        // Validate arguments
        if (name != nullptr && std::strcmp(name, "") != 0) {
            std::strcpy(name, m_name);
        }

        if (phoneNumbers != nullptr && phoneNumbers > 0) {
            // Parse string in (+COUNTRY_CODE) AREA_CODE NNN-NNNN format
            for (int i = 0; i < noOfPhoneNumbers; i++) {
                if (phoneNumbers[i] <= 1000000000000 && phoneNumbers[i] > 10000000000) {
                    m_phoneNumbers[i] = phoneNumbers[i];
                }
            }
        }

        for (int i = 0; i < noOfPhoneNumbers; i++) {
            if (phoneNumbers[i] == -1) {}
            else {
                // Allocate enough space and copy the valid phone numbers
                m_phoneNumbers = new long long[noOfPhoneNumbers];
                phoneNumbers[i] = m_phoneNumbers[i];
            }
        }
    }

    // Destructor
    Contact::~Contact() {
        // if m_phoneNumbers doesn't equal nullptr, delete m_phoneNumbers
        if (m_phoneNumbers != nullptr) {
            delete m_phoneNumbers;
        }
    }

    // Check if contact information exists or is in a safe empty state
    bool Contact::isEmpty() const {
        if (m_name[0] == 0 || m_phoneNumbers[0] == 0 || m_noOfPhoneNumbers == 0) { return true; }
        else { return false; }
    }

    // Display information about the contact
    void Contact::display() const {
        if (isEmpty()) { cout << "Empty contact!" << endl; }
        else {
            // Print out relevant contact info
            cout << m_name << endl;
            // Output the valid phone numbers
            for (int i = 0; i < m_noOfPhoneNumbers; i++) {
                cout << m_phoneNumbers[i] << endl;
            }
        }
    }
}
