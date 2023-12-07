#include <stdio.h>
#include <iostream>

char firstSingleLetter(char* text, const int n) {
    bool duplicate = false;

    for (int i = 0; i < n; i++) {
        duplicate = false;
        for (int j = 0; j < n; j++) {
            if (text[i] == text[j] && i != j) {
                duplicate = true;
            }
        }

        if (!duplicate) {
            std::cout << text[i] << '\n';
            return text[i];
        }
    }

    return ' ';
}

char firstSingleLetterFaster(char* text, const int n) {
    int seen[26] = {0};

    for (int i = 0; i < n; i++) {        
        seen[text[i] - 'A']++;
    }

    for (int i = 0; i < n; i++) {
        if (seen[text[i] - 'A'] == 1) {
            std::cout << text[i] << '\n';
            return text[i];
        }
    }

    return ' ';
}

int main() {
    char text[] = "AAABYBCHEDEFGHIJKBB";
    firstSingleLetter(text, strlen(text));
    firstSingleLetterFaster(text, strlen(text));
    return 0;
}
