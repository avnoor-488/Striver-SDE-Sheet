class Solution {
public:
    vector<int> topKFrequent(vector<int>& vec, int k) {
        unordered_map<int,int>mp;
        vector<int>output(k);
        for(int  i = 0;i<vec.size();i++)
            mp[vec[i]]++;
        
        priority_queue<pair<int,int>>pq;
        
        for(auto it:mp)
            pq.push(make_pair(it.second,it.first));
        
        int i = 0;
        while(!pq.empty() and k!=0)
        {
            output[i++]  = pq.top().second;
            k--;
            pq.pop();
        }
    
        sort(output.begin(),output.end());
        return output;        
    }
};
