/**
 * Note:
 * This is my solution to oblig 4 in the Algmet course. The task is pushed to
 * Github for my own accessability and version control, and should only be used
 * as a resource, not copied as an alternative to doing the oblig yourself.
*/

#include <iostream>
#include <iomanip>
#include <cctype>

/**
 * Enum for hashtable-type (linear probing or double hashing).
 */
enum HashType { LinearProbing, DoubleHashing };

/**
 * Container-class Hasing.
 *
 * Contains a char-array ('table'), max. number of elements in
 * array ('length'), and the type table is of ('hType').
 */
class Hashing {
    private:
        // Hash-table
        char* table;
        // Table length
        int length;
        // Table type used to hash
        HashType hType;

        // Returns k % M:
        int hash1(const int modValue, const int kValue) {
            return (kValue % modValue);
        }

        // Returns H - (k % H):
        int hash2(const int hashValue, const int kValue) {
            return (hashValue - (kValue % hashValue));
        }

        // Translate letter A-Z to number 1-26:
        int kValue(char letter) {
            letter = toupper(letter);
            // Is a letter
            if (letter >= 'A' && letter <= 'Z') {
                return (static_cast <int> (letter - 'A') + 1);
            // Is not a letter
            } else {
                return 0;
            }
        }

    public:
        Hashing(const HashType hT, const int len) {
            // Initiates members
            length = len;
            hType = hT;
            // Creates hash-table
            table = new char[len];
            // Resets
            for (int i = 0; i < length; i++) {
                table[i] = '-';
            }
        }

        ~Hashing() {delete [] table; }

        // Prints content
        void display() const {
            for (int i = 0; i < length; i++) {
                std::cout << std::setw(3) << i << ":  " << table[i] << '\n';
            }
        }

        // Inserts data in the hash table
        void insert(const int hashValue, const char data) {
            // Translates data to 'k'.
            int dataToK = kValue(data);
            // Finds hash1-value
            int index = hash1(length, dataToK);
            // Finds hash2-value
            int val = hash2(hashValue, dataToK);
            
            std::cout << data << " k: " << dataToK << " h1: " << index << " h2: " << val << '\n';

            // Loops till available spot
            while (table[index] != '-') {
                // Jumps one index (linear probing) or val (d.hash):
                index = (hType == LinearProbing) ? (index + 1) : (index + val);
                // Wraps to start if outside limits
                index %= length;
            }

            // Places in available position
            table[index] = data;
            display();
        }
};

/**
 * Main program:
 */
int main() {

    char taskTwo[] = "ALGORITMERERLIVET";

    Hashing hashTable(DoubleHashing, 17);

    // Hashes text for double hashing
    for (int i = 0; i <= 13; i++) {
        hashTable.insert(4, taskTwo[i]);
    }

    std::cout << "\n\n";
    return 0;
}