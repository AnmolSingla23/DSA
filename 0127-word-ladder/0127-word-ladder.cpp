class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string,int>> q; //first stores str and second stores max steps
        q.push({beginWord,1}); //push the first word
        unordered_set<string> st(wordList.begin(),wordList.end());  //add the the whole list in the set
        
        st.erase(beginWord);  //remove the first word if it exists
        
        while(!q.empty()){
            auto fnode = q.front();
            q.pop();
            
            string curr = fnode.first;
            int count = fnode.second;
            //if we have reached the end word return it
            if(curr == endWord)
                return count;
            
            //traverse the words char wise and change the index char
            for(int index = 0;index<curr.length();index++){
                //store the original char
                char original = curr[index];
                for(char ch='a';ch<='z';ch++){
                    curr[index] = ch;  //try each alhpabet at each index
           //if we have found that word push that in queue and increase the count          
                    if(st.find(curr) != st.end()){
                        q.push({curr,count+1});
                        st.erase(curr); //remove that from set so that we do not revisit it again
                    }
                }
                //we do not loose the original word so replace it with the original
                curr[index] = original;
            }
        }
        return 0;
    }
};