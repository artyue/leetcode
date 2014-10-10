class Solution {
public:
    bool isScramble(string s1, string s2) {
        int size = s1.size();
        if(s1 == "" && s2 == "")
        	return true;

        if(s1.size() != s2.size())
        	return false;

        if(s1 == s2)
        	return true;

        string s11(s1), s22(s2);
    	sort(s11.begin(), s11.end()); 
    	sort(s22.begin(), s22.end());
    	if(s11 != s22)
      		return false;

        for(int i = 1; i < size; ++i) {
        	string s11, s12, s21, s22;
        	s11 = s1.substr(0, i);
        	s12 = s1.substr(i);

 			/* Don't swap s2 */
        	s21 = s2.substr(0, i);
        	s22 = s2.substr(i);
        	if(isScramble(s11, s21) && isScramble(s12, s22))
        		return true;
        	/* Do swap s2 */
        	s21 = s2.substr(size-i, i);
        	s22 = s2.substr(0,size-i);
        	if(isScramble(s11, s21) && isScramble(s12, s22))
        		return true;
        }
        
        return false;
    }
    
};
