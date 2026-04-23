class KthLargest {
public:
    priority_queue<int , vector<int>, greater<>>pq; //minHeap
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i=0; i<(int)nums.size(); i++){
            if(pq.size()<k)
                pq.push(nums[i]);
            else
            {
                if(nums[i] > pq.top()){
                    pq.pop();
                    pq.push(nums[i]);
                }
            }
        }
    }
    
    int add(int val) {
        if(pq.size()==k && val > pq.top()){
            pq.pop();
            pq.push(val);
        }else if(pq.size() < k){
            pq.push(val);
        }
        return pq.top();
    }
};
