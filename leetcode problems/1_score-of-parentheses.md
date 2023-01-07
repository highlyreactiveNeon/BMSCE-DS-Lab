# Score of Parentheses

```c++
class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth = 0;
        int count = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '('){
                depth++;
                continue;
            } else {
                if(s[i-1] == '('){
                    count += pow(2,depth-1);
                    depth--;
                } else {
                    depth--;
                }
            }   
        }

        return count;
    }
};
```
