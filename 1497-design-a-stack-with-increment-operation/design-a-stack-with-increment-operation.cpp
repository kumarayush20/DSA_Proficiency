// Approach - 01
class CustomStack {
private:
    vector<int> v;
    int curInd = -1, mxCapacity;
public:
    CustomStack(int maxSize) {
        v = vector<int> (maxSize);
        mxCapacity = maxSize;
    }
    
    void push(int x) {
        if(curInd == mxCapacity-1){return;}
        curInd++;
        v[curInd] = x;
    }
    
    int pop() {
        if(curInd==-1){return -1;}
        int ans = v[curInd];
        v[curInd] = -1;
        curInd--;

        return ans;
    }
    
    void increment(int k, int val) {
        int n = min(k,curInd+1);
        for(int i=0;i<n;i++){
            v[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */