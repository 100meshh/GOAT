class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) return false;

        bool hasVowel = false;
        bool hasConsonant = false;
        string vowels = "aeiouAEIOU";

        for (char ch : word) {
            if (!isalnum(ch)) return false; // Not a letter or digit

            if (isalpha(ch)) {
                if (vowels.find(ch) != string::npos) {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
        }

        return hasVowel && hasConsonant;
    }
};
