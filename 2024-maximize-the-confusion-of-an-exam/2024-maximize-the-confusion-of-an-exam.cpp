class Solution {
public:
    int maxConsecutiveAnswers(string st, int k) {
     
        int len = 0;
        int left = 0;
        int right = 0;
        int shi = 0;
        int glt = 0;

        while(right < st.size()){

            if(st[right] == 'T')   //to count the current position
                shi++;
            else
                glt++;

            while(shi > k && glt > k){  //if it crosses max no of edits
                if(st[left] == 'T')   //make the window small so we can edit
                    shi--;
                else{
                    glt--;
                }
                left++;    //start closing from the left
            }
            len = max(len,right-left + 1);  //get the max len
            right++;
        }
        return len;
    }
};