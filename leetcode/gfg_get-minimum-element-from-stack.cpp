// by o(1) tc and o(1) sc 

class SpecialStack {
	public:
	
	// Define Stack
	stack < int > st1; // orignal stack
	stack <int > st2; // min stack
	SpecialStack() {
	}
	
	void push(int x) {
		// Add an element to the top of Stack
		if (st1.empty()) {
			st1.push(x);
			st2.push(x);
			
		}
		else {
			st1.push(x);
			st2.push(min(x, st2.top()));
		}
	}
	
	void pop() {
		// Remove the top element from the Stack
		st1.pop();
		st2.pop();
	}
	
	int peek() {
		// Returns top element of the Stack
		if (st1.empty()) {
			return - 1;
		}
		else {
			return st1.top();
		}
	}
	
	bool isEmpty() {
		// Check if stack is empty
		return st1.empty();
	}
	
	int getMin() {
		// Finds minimum element of Stack
		if (st2.empty())
			return - 1;
		else {
			return st2.top();
		}
	}
};


// now o(1) tc and with out extra stack or space works only in range

class SpecialStack {
	public:
	stack < int > st ;
	SpecialStack() {
		// Define Stack
	}
	
	void push(int x) {
		// Add an element to the top of Stack
		if (st.empty()) {
			st.push(x*101 + x);
		}
		else {
			st.push(x*101 +min (x,st.top()%101));
		}
	}
	
	void pop() {
		// Remove the top element from the Stack
		
		st.pop ();
	}
	
	int peek() {
		// Returns top element of the Stack
		if (st.empty()) {
			return - 1;
		}
		else {
			return st.top()/101;
		}
	}
	
	bool isEmpty() {
		// Check if stack is empty
		return st.empty();
	}
	
	int getMin() {
		// Finds minimum element of Stack
		if(st.empty()){
		    return -1;
		}
		else {
		 return    st.top() %101;
		}
	}
};
