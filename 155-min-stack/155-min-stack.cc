class MinStack {
public:
    void push(int x) {
        stack_.push(x);
        if (mins_.empty()) {
            mins_.push(x);
        } else {
            int now_min = mins_.top();
            if (x <= now_min) mins_.push(x);
        }
    }

    void pop() {
        int x = stack_.top();
        stack_.pop();
        int now_min = mins_.top();
        if (x == now_min) mins_.pop();
    }

    int top() {
        return stack_.top();
    }

    int getMin() {
        return mins_.top();
    }
private:
    stack<int> mins_;
    stack<int> stack_;
};
