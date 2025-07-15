class Solution {
    func isValid(_ word: String) -> Bool {
        if word.count < 3 {
            return false
        }

        let vowels: Set<Character> = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]
        var hasVowel = false
        var hasConsonant = false

        for ch in word {
            if !ch.isLetter && !ch.isNumber {
                return false
            }

            if ch.isLetter {
                if vowels.contains(ch) {
                    hasVowel = true
                } else {
                    hasConsonant = true
                }
            }
        }

        return hasVowel && hasConsonant
    }
}
