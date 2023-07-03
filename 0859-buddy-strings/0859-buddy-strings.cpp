class Solution {
public:
    bool buddyStrings(string s, string goal) {
           
        int n = s.size();
        if(s == goal){ //if s and goal are identical store them is set
            set<char> st(s.begin(),s.end()); //after storing calculate the size of set
            if(st.size() < n) //if size of set is less then s that means there are identical char u can swap is greater it means all are distinct and that cant be swapped
                return true;
            else
                return false;
        }

        int i = 0;
        int j = n-1;

        while(i < j && s[i] == goal[i]){
            i++;
        }  //check from front if both string are equal or not if equal inc i else check from end

        while(j>=0 && s[j] == goal[j]){
            j--;
        }  //chk from end if they r equal we cant swap so dec

        if(i < j){  //if none then swap the i and j
            swap(s[i], s[j]);
        }
        return s == goal;  //if that makes them equal return true else false
    }
};