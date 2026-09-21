class MinStack {
public:

    vector<int> pilha;
    vector<int> minPilha;

    MinStack() {

        vector<int> pilha = {};
        vector<int> minPilha = {};

    }
    
    void push(int val) {
        pilha.push_back(val);

        if(minPilha.empty() || val < minPilha.back()){
            minPilha.push_back(val);
        }else{
            int minVal = minPilha.back();
            minPilha.push_back(minVal);
        }
    }
    
    void pop() {

        pilha.pop_back();
        minPilha.pop_back();
        
    }
    
    int top() {

        return pilha.back();
        
    }
    
    int getMin() {
        return minPilha.back();
    }
};
