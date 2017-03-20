#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H

namespace communication {
    class Contact {
        char m_name[21];
        long long *m_phoneNumbers;
        int m_noOfPhoneNumbers;
    public:
        // TODO: add the default constructor here
        Contact();

        // TODO: add the constructor with parameters here
        Contact(char name[21], long long *phoneNumbers, int noOfPhoneNumbers);

        // Use the destructor to make sure that there aren't any memory leaks
        ~Contact();

        // TODO: add the display function here
        void display() const;

        // TODO: add the isEmpty function here
        bool isEmpty() const;

        // Parsing
        int numdigits(long long n) const;

        std::string getdigits(long long n, int startPosition, int numberOfDigits) const;

    public:
        Contact(const Contact &other) = delete;
        Contact &operator=(const Contact &other) = delete;
    };
}
#endif
