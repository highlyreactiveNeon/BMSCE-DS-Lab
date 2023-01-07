# Number of visible persons in queue

## My first Naive Solution

```c++
vector<int> canSeePersonsCount(vector<int>& heights) {
    vector<int> result;
    result.resize(heights.size());

    int highest;
    for(int i = 0; i < heights.size(); i++){
        int currentHeight = heights[i];

        highest = heights[i+1];
        for(int j = i + 1; j < heights.size(); j++){
            if(heights[j] > currentHeight){
                result[i]++;
                break;
            }

            if(heights[j] >= highest) {
                result[i]++;
            }

            if(heights[j] > highest)
                highest = heights[j];
        }
    }

    return result;
}
```

## Optimized Solution

```c++
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> result;
        result.resize(heights.size());

        stack<int> stk;
        stk.push(heights.back());

        int count;
        for(int i = heights.size() - 2; i >= 0; i--) {
            count = 0;
            while(!stk.empty() && heights[i] >= stk.top()) {
                stk.pop();
                count++;
            }
            if(stk.empty())
                count--;
            count++;
            stk.push(heights[i]);
            result[i] = count;
        }

        return result;
    }
};
```
