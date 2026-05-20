class Solution {
public:
    bool valid_move(string& s1, string& s2){
        if(s1.length() != s2.length()) return false;
        int n = s1.length();
        int mismatches =0;
        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]) mismatches++;
            if(mismatches == 2) return false; 
        }
        return true;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //I can get stuck in infinite recursion so DP is not the right move because it is 
        //definitely not a DAG

        //make a queue of valid words from the start and then iterate over them
        int n = beginWord.length();
        wordList.erase(remove(wordList.begin(), wordList.end(), beginWord), wordList.end());

        unordered_map<string, bool> visited;

        queue<string> qt;
        for(int i= 0; i<wordList.size(); i++){
            if(valid_move(beginWord, wordList[i])){
                qt.push(wordList[i]);
                if(wordList[i] == endWord) return 2;
                visited[wordList[i]] = true;
            }
        }

        int distance = 2;
        while(!qt.empty()){
            int size = qt.size();
            for(int i=0; i<size; i++){
                string top = qt.front();  qt.pop();
                cout << "Current Length of the path : " << distance << " Word " << top << endl;
                for(int k=0; k< wordList.size(); k++){
                    string nextWord = wordList[k];
                    if(visited.find(nextWord) == visited.end() && valid_move(top, nextWord)){
                        if(nextWord == endWord) return (distance + 1);
                        qt.push(nextWord);
                        visited[nextWord] = true;
                    }
                }
            }
            if(!qt.empty()) distance++;
        }
        return 0;

    }
};