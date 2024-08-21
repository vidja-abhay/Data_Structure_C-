#include <iostream>
#include <string>

std::string findLargestWord(const std::string& str) {
    int maxLength = 0;
    std::string largestWord = "";
    std::string currentWord = "";

    for (char ch : str) {
        if (ch == ' ') {
            if (currentWord.length() > maxLength) {
                maxLength = currentWord.length();
                largestWord = currentWord;
            }
            currentWord = ""; // Reset currentWord for the next word
        } else {
            currentWord += ch; // Add character to currentWord
        }
    }

    // Check the last word
    if (currentWord.length() > maxLength) {
        largestWord = currentWord;
    }

    return largestWord;
}

int main() {
    std::string str = "Find the largest word in this string.";
    std::string largestWord = findLargestWord(str);
    
    std::cout << "The largest word is: " << largestWord << std::endl;
    return 0;
}
