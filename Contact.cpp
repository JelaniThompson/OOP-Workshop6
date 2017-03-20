#include <iostream>
#include <regex>
#include <stdio.h>
#include <string.h>
#include "Contact.h"
#include <string>

using namespace std;

namespace communication {
    // Set the instance to a safe empty state
    Contact::Contact() {
        m_name[0] = '\0';
        m_phoneNumbers = nullptr;
        m_noOfPhoneNumbers = 0;
    }

    int Contact::numdigits(long long n) const {
        string s = to_string(n);
        return s.length();
    }

    std::string Contact::getdigits(long long n, int startPosition, int numberOfDigits) const {
        std::string s = std::to_string(n);
        return s.substr(startPosition, numberOfDigits);
    }

    Contact::Contact(char name[21], long long *phoneNumbers, int noOfPhoneNumbers) {
        // Validate arguments
        if (name != nullptr && strcmp(name, "") != 0) {
            // If name longer than 20 characters, only output what you can (A contact with a ver)
            for (int i = 0; i < 20; i++) {
                m_name[i] = name[i];
            }
            m_name[20] = '\0';
        }

        else { m_name[0] = '\0'; }

        if (phoneNumbers != nullptr && phoneNumbers > 0 && noOfPhoneNumbers > 0) {
            m_phoneNumbers = new long long[noOfPhoneNumbers];

            for (int i = 0; i < noOfPhoneNumbers; i++) {
                // Allocate enough space and copy the valid phone numbers + valid phone number
                //if (phoneNumbers[i] <= sizeof(long long) && phoneNumbers[i] >= sizeof(long long)) {
                m_phoneNumbers[i] = phoneNumbers[i];
                // }
            }
            m_noOfPhoneNumbers = noOfPhoneNumbers;
        } else {
            m_phoneNumbers = nullptr;
            m_noOfPhoneNumbers = 0;
        }
    }

    // Destructor
    Contact::~Contact() {
        // Prevent memory leak by checking any instance of the Contact type (have to be initialized with new first)
        if (m_phoneNumbers != nullptr) { delete [] m_phoneNumbers; }
        // if (m_name[0] != '\0') { m_name[0] = '\0'; }
        // if (m_noOfPhoneNumbers != 0) { m_noOfPhoneNumbers = 0; }
    }

    // Check if contact information exists or is in a safe empty state
    bool Contact::isEmpty() const {
        if (m_name[0] == '\0' && m_phoneNumbers == nullptr && m_noOfPhoneNumbers == 0) { return true; }
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
                if (numdigits(m_phoneNumbers[i]) == 11) {
                    cout << "(+" << getdigits(m_phoneNumbers[i], 0, 1) << ") "
                         << getdigits(m_phoneNumbers[i], 1, 3) << " "
                         << getdigits(m_phoneNumbers[i], 4, 3)
                         << "-" << getdigits(m_phoneNumbers[i], 7, 4) << endl;
                }
                else if (numdigits(m_phoneNumbers[i]) == 12) {
                    cout << "(+" << getdigits(m_phoneNumbers[i], 0, 2) << ") " << getdigits(m_phoneNumbers[i], 2, 3)
                         << " " << getdigits(m_phoneNumbers[i], 5, 3) << "-"
                            << getdigits(m_phoneNumbers[i], 8, 4) << endl;
                }
            }
        }
    }
}
