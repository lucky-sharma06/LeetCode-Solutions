class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;

        // traverse the string
        for(char ch : s){
            if(ch == '('){
                minOpen++;
                maxOpen++;
            }
            else if(ch == ')'){
                minOpen--;
                maxOpen--;
            }
            else{
                // ch is an asterick(*)
                minOpen--; // * -> ')'
                maxOpen++; // * -> '('
            }
            if(minOpen < 0) minOpen = 0; // can't be negative
            if(maxOpen < 0) return false; // means more ) brackets...
        }
        // at end if minOpen == 0 then true;
        return minOpen == 0;
    }
};