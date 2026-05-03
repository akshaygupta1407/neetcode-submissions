class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dict(wordList.begin(), wordList.end());
        int ladder = 1;
        queue<string>todo;
        todo.push(beginWord);
        while(!todo.empty()) {
            int s = todo.size();
            while(s--) {
                string word = todo.front();
                if(word == endWord) return ladder;
                todo.pop();
                dict.erase(word);
                for(int i=0; i<word.length(); i++) {
                    string nextWord = word;
                    for(int j=0; j<26; j++) {
                        char c = 'a' + j;
                        nextWord[i] = c;
                        if(dict.find(nextWord) != dict.end()) {
                            todo.push(nextWord);
                        }
                    }
                }
            }
            ladder++;
        }
        return 0;
    }
};