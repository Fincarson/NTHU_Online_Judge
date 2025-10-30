#include <iostream>
#include <string>
#include <stack>
using namespace std;

class ArithmeticEvaluation{
public:
    // Constructor
    ArithmeticEvaluation(void){
        expression = "";
        index = 0;
        expression_length = 0;
        curNumber = 0;
        number_of_parantheses = 0;
        curChar = 'x';

        expect_number = true;
        number_is_negative = false;
    }

    // Destructor
    ~ArithmeticEvaluation(void){
        while(!numbers.empty()) numbers.pop();
        while(!operators.empty()) operators.pop();
    }

    // Default Setting
    inline void Default(string input){
        expression = input;
        expression_length = expression.size();

        index = 0;
        curNumber = 0;
        number_of_parantheses = 0;
        curChar = 'x';

        expect_number = true;
        number_is_negative = false;

        while(!numbers.empty()) numbers.pop();
        while(!operators.empty()) operators.pop();
    }

    // Check expression is valid or not
    inline bool CheckValid(void){
        for(index = 0; index < expression_length; index++){
            if(expression[index] == '(') ++number_of_parantheses;
            if(expression[index] == ')') --number_of_parantheses;
            if(number_of_parantheses < 0) return false;
        }
        return !number_of_parantheses;
    }

    // Check Operation Precedence
    inline bool ValidPrecedence(void){
        if(operators.empty()) return false;

        char op = operators.top();
        switch(curChar){
            case '+': case '-': return op == '+' || op == '-' || op == '*' || op == '/'; break;
            case '*': case '/': return op == '*' || op == '/'; break;
            default: return false; break;
        }
        return false;
    }

    // Calculate
    inline void Calculate(void){
        long num_right = numbers.top(); numbers.pop();
        long num_left  = numbers.top(); numbers.pop();
        char op = operators.top(); operators.pop();

        switch(op){
            case '+': numbers.push(num_left + num_right); break;
            case '-': numbers.push(num_left - num_right); break;
            case '*': numbers.push(num_left * num_right); break;
            case '/': numbers.push(num_left / num_right); break;
            default: break;
        }
    }

    // Evaluate
    inline long Evaluate(void){
        for(index = 0; index < expression_length; index++){
            curChar = expression[index];
            
            // Open Parantheses
            if(curChar == '('){
                operators.push(curChar);
                expect_number = true;
            }

            // Closing Parantheses
            else if(curChar == ')'){
                while(operators.top() != '(') Calculate();
                operators.pop();
                expect_number = false;
            }

            // Number
            else if(expect_number && (isdigit(curChar) || curChar == '-')){
                number_is_negative = curChar == '-' ? true : false;
                if(number_is_negative) ++index;

                curNumber = 0;
                while(isdigit(expression[index])){
                    curNumber = curNumber * 10 + (long)(expression[index] - '0');
                    ++index;
                }
                numbers.push(!number_is_negative? curNumber : -curNumber);
                expect_number = false;
                --index;
            }

            // Operator
            else if(curChar == '*' || curChar == '/' || curChar == '+' || curChar == '-'){
                while(ValidPrecedence()) Calculate();
                operators.push(curChar);
                expect_number = true;
            }
        }

        while(!operators.empty()) Calculate();
        return numbers.top();
    }



private:
    stack <long> numbers;
    stack <char> operators;
    string expression = "";

    int index = 0;
    int expression_length = 0;
    int number_of_parantheses = 0;
    long curNumber = 0;
    char curChar = 'x';

    bool expect_number = true;
    bool number_is_negative = false;
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ArithmeticEvaluation AE;
    int T = 0; cin >> T;
    string input = "";

    while(T--){
        cin >> input;
        AE.Default(input);
        if(!AE.CheckValid()) cout << "bad expression\n";
        else cout << AE.Evaluate() << '\n';
    }
    return 0;
}