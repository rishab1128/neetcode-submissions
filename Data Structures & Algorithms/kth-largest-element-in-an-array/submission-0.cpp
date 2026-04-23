//kth-largest ->minHeap of size k ->minHeap.top() returns ans
//kth-smallest ->maxHeap of size k ->maxHeap.top() return ans
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int , vector<int>, greater<>>pq; //minHeap

        for(auto &ele: nums)
        {
            if(pq.size() < k)
                pq.push(ele);
            else{
                if(ele > pq.top())
                {
                    pq.pop();
                    pq.push(ele);
                }
            }
        }

        return pq.top();
        
        
    }
};
