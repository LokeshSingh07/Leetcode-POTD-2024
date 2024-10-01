// 1381. Design a Stack With Increment Operation

class CustomStack {
public:
    vector<int> arr;
    int size;
    int top = -1;

    CustomStack(int maxSize) {
        size = maxSize;
        arr.resize(maxSize);
        top = -1; 
    }
    
    void push(int x) {
        if(top != size-1){
            top++;
            arr[top] = x;
        }
    }
    
    int pop() {
        if(top != -1){
            int temp = arr[top];
            arr[top] = -1;
            top--;
            return temp;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        for(int i=0; i<min(size, k); ++i){
            arr[i] += val;
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