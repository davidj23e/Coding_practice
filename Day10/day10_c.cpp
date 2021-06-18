class MinStack {
    struct node
    {
        int val;
        node *next;
        // node *min_till_now;
        node():val(0), next(nullptr){}
        node(int a, node *n):val(a), next(n){}

    };
public:
    /** initialize your data structure here. */
    node *stack;
    int minElem;
    node *minNode;
    MinStack() {
        stack = nullptr;
        minElem = INT_MAX;
    }
    
    void push(int val) {
        node * temp = new node(val, stack);
        if(!stack)
        {
            minNode = temp;
        }
        stack = temp;
        minElem = min(minElem, val);
    }
    
    void pop() {
        if(stack)
        {
            if(stack->val == minElem)
            {
                node *temp = stack->next;
                minElem = INT_MAX;
                while(temp)
                {
                    minElem = min(minElem, temp->val);
                    temp = temp->next;
                }
            }
            stack = stack->next;
        }

    }
    
    int top() {
        return stack->val;
    }
    
    int getMin() {
        return minElem;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */