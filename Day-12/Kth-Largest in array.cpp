class Solution {
public:
    int findKthLargest(vector<int>& vec, int k) {

    
    priority_queue<int>pq;

    for (int i = 0; i < vec.size(); i++)
    {
        pq.push(vec[i]);

    }

    int i = 0;
    while (i != k - 1)
    {
        pq.pop();
        i++;
    }

   return  pq.top();
        
    }
};
