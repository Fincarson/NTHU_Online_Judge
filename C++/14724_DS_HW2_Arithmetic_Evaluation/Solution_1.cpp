#include <iostream>
#include <string>
#include <stack>
using namespace std;

class ArithmeticEvaluation{
public:
    //Contructor
    ArithmeticEvaluation(){
        input = "";
        curChar = 'x';

        index = 0;
        input_length = 0;
        number_of_open_paranthesis = 0;
    }

    // Destructor
    ~ArithmeticEvaluation() {}

    // Default
    inline void Default(string x){
        input.clear();
        input = x;
        curChar = 'x';
        index = 0;
        input_length = (int)input.length();

        expect_number = true;

        number_of_open_paranthesis = 0;

        while (!numbers.empty()) numbers.pop();
        while (!operands.empty()) operands.pop();
    }

    // Valid Check
    inline bool ValidCheck(){
        for(index = 0; index < input_length; ++index){
            if(input[index] == '(') number_of_open_paranthesis++;
            else if(input[index] == ')') number_of_open_paranthesis--;

            if(number_of_open_paranthesis < 0) return false;
        }
        return number_of_open_paranthesis == 0 ? true : false;
    }

    // Check Operand Precedence
    inline bool CheckPrecedence(char op){
        char op2 = operands.top();
        if(op == '*' || op == '/') return op2 == '*' || op2 == '/';
        else if(op == '+' || op == '-')
            return op2 == '+' || op2 == '-' || op2 == '*' || op2 == '/';
        return false;
    }

    //Calculate
    inline void Calculate(){
        if(numbers.size() < 2 || operands.empty()) return;
        long num_right = numbers.top(); numbers.pop();
        long num_left = numbers.top(); numbers.pop();
        char op = operands.top(); operands.pop();

        switch(op){
            case '+': numbers.push(num_left + num_right); break;
            case '-': numbers.push(num_left - num_right); break;
            case '*': numbers.push(num_left * num_right); break;
            case '/': numbers.push(num_left / num_right); break;
            default: break;
        }
    }

    // Evaluate
    inline long Evaluate(){
        for(index = 0; index < input_length; index++){
            curChar = input[index];
            if(curChar == '('){
                operands.push('(');
                expect_number = true;
                continue;
            }
            else if(curChar == ')'){
                while(!operands.empty() && operands.top() != '(') Calculate();
                if(!operands.empty() && operands.top() == '(') operands.pop();
                expect_number = false;
                continue;
            }
            else if(expect_number && curChar == '-' && input[index+1] == '('){
                numbers.push(0);
                operands.push('-');
                expect_number = false;
                continue;
            }
            else if(expect_number && (isdigit(curChar) || (curChar == '-' && isdigit(input[index+1])))){
                long num = 0;
                bool isNeg = false;
                if(curChar == '-'){
                    isNeg = true;
                    ++index;
                }
                while(expect_number && isdigit(input[index])){
                    num = num * 10 + long(input[index] - '0');
                    ++index;
                }
                --index;
                numbers.push(!isNeg ? num : -num);
                expect_number = false;
                continue;
            }
            else if(curChar == '+' || curChar == '-' || curChar == '*' || curChar == '/'){
                while(!operands.empty() && operands.top() != '(' && CheckPrecedence(curChar)){
                    Calculate();
                }
                operands.push(curChar);
                expect_number = true;
                continue;
            }
            
        }

        while(!operands.empty()){
            Calculate();
        }
        return numbers.top();
    }


private:
    stack <long> numbers;
    stack <char> operands;

    string input = "";
    
    bool expect_number = true;
    char curChar = 'x';

    int index = 0;
    int input_length = 0;
    int number_of_open_paranthesis = 0;
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ArithmeticEvaluation AE;
    string input;
    int T = 0; cin >> T;
    long result;

    while(T--){
        result = 0;
        cin >> input;
        AE.Default(input);

        if(!AE.ValidCheck()) cout << "bad expression" << '\n';
        else cout << AE.Evaluate() << '\n';
    }
    return 0;
}