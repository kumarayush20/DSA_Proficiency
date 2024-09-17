class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        stringstream ss(s1 + " " + s2);  // Combine both sentences and process them together
        string word;
        unordered_map<string, int> wordCount;

        // Count the occurrence of each word from both sentences
        while (ss >> word) {
            wordCount[word]++;
        }

        vector<string> result;
        // Find words that appear exactly once in total
        for (auto& [key, count] : wordCount) {
            if (count == 1) {
                result.push_back(key);
            }
        }
        return result;
    }
};
