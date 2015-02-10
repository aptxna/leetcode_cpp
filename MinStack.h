/**
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 *
 * push(x) -- push element x onto stack.
 * pop() -- removes the element on top of the stack.
 * top() -- get the top element.
 * getMin() -- retrive the minimum element in the stack.
 */

class MinStack {
public:
	struct minunit {
		int count;
		int value;
		minunit(int count,int value):count(count),value(value) {};
	};

	stack<int> mystack;
	stack<minunit*> minstack;

	void push(int x) {
		mystack.push(x);
		if (minstack.empty() || x<minstack.top()->value) {
			minunit* punit = new minunit(1,x);
			minstack.push(punit);
		}
		else if (x == minstack.top()->value) {
			minstack.top()->count++;
		}
	}

	void pop() {
		if (mystack.top() == minstack.top()->value) {
			if (minstack.top()->count == 1) {
				minunit* punit = minstack.top();
				minstack.pop();
				delete punit;
			}
			else {
				minstack.top()->count--;
			}
		}
		mystack.pop();
	}

	int top() {
		return mystack.top();
	}

	int getMin() {
		return minstack.top()->value;
	}
};

