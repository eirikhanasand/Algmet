/**
 * Note from Eirik:
 * 
 * Self made map class. Contains some testing, but it has not been completed due
 * to lack of compability between char arrays and the string type. This was to
 * save time, as it is not the point of this course.
 * 
 * The code uses a pair of arrays of given length, one containing the key and
 * the other containing the value. I know map uses hashing, but that has not been
 * covered in the course yet, hence it is not the point of this task. Memory /
 * resizing the arrays has been abstracted away, thus giving a more map like
 * feeling than the first task, where you had to resize manually.
*/

#include <iostream>
#include <string>

template <typename K, typename V>
class Map {
    private:
        K*  key;
        V*  value;
        int used;
        int capacity;

    public:
        Map() {
            key = new K[1];
            value = new V[1]; 
            used = 0;
            capacity = 1;
        }

        ~Map() {
            delete[] key;
            delete[] value;
        }

        int size() const { return used; }

        void view() const {
            if (!used) {
                std::cout << "Nothing to view, the map is empty.\n";
                return;
            }

            std::cout << "Printing all content of map...\n\n";

            for (int i = 0; i < used; i++) {
                std::cout << key[i] << " " << value[i] << "\n";
            };
        };

        void add(K* newKey, V* newValue) {
            K* tempKey = new K[used+1];
            V* tempValue = new V[used+1];

            for(int i = 0; i < used; i++) {
                tempKey[i] = key[i];
                tempValue[i] = value[i];
            };

            key[used] = newKey;
            key[value] = newValue;

            delete[] key;
            delete[] value;

            key = tempKey;
            value = tempValue;

            capacity++;
            used++;
        }

        K* get(std::string term) {
            for(int i = 0; i < used; i++) {
                if (key[i] == term) {
                    return value[i];
                };
            };

            std::cout << "Unknown key, try something else.\n";
            return false;
        }

        void edit(K* term, V* newValue) {
            for(int i = 0; i < used; i++) {
                if (key[i] == term) {
                    value[i] = newValue;
                    return;
                };
            };

            std::cout << "Unknown key, no changes made.\n";
        }

        void remove(K* term) {
            int indexToRemove = -1;

            for(int i = 0; i < used; i++) {
                if (key[i] == term) {
                    indexToRemove = i;
                };
            };

            if (indexToRemove == -1) {
                std::cout << "Unknown key, could not remove.\n";
                return;
            }

            for (int i = indexToRemove; i < used; i++) {
                key[i] = key[i+1];
                value[i] = value[i+1];
            }

            used--;
        }

        bool find(K*term) {
            for(int i = 0; i < used; i++) {
                if (key[i] == term) {
                    return true;
                };
            };

            return false;
        }
};

int main() {
    Map <std::string, std::string> sMap;
    Map <std::string, int> iMap;

    sMap.view();
    iMap.view();

    // Not testing this cause char array
    // sMap.add("Hei", "Hei");
}