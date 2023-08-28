class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int top=q1.front();
        q1.pop();
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
        return top;
    }
    
    int top() {
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        int top=q1.front();
        q2.push(top);
        q1.pop();
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
        return top;
    }
    
    bool empty() {
        if(q1.size()==0) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */