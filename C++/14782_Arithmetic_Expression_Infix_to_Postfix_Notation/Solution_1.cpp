#include <iostream>
#include <string>
#include <stack>
using namespace std;

class InfixToPostfix{
public:
    // Constructor
    inline InfixToPostfix(void){
        expression.empty();
        output.empty();

        curChar = 'x';

        expression_length = 0;
        index = 0;
    }

    //Destructor
    inline ~InfixToPostfix(void){
        while(!operators.empty()) operators.pop();
    }

    // Default Setting
    inline void Default(string input){
        while(!operators.empty()) operators.pop();
        expression = input;
        output = "";

        expression_length = expression.size();
        index = 0;
    }

    // Check Operator Precedence
    inline bool ValidPrecedence(char op){
        char op2 = operators.top();
        switch(op){
            case '+': case '-': return op2 == '+' || op2 == '-' || op2 == '*' || op2 == '/'; break;
            case '*': case '/': return op2 == '*' || op2 == '/'; break;
            default: return false; break;
        }
    }

    // Change Form from Infix to Postfix
    inline string ChangeForm(void){
        for(index = 0; index < expression_length; index++){
            curChar = expression[index];

            // Open parantheses
            if(curChar == '('){
                operators.push(curChar);
            }

            // Closing parantheses
            else if(curChar == ')'){
                while(operators.top() != '('){
                    if(!output.empty()) output += ' ';
                    output += operators.top();
                    operators.pop();
                }
                operators.pop();
            }

            // Handle Digits
            else if(isdigit(curChar)){
                if(!output.empty()) output += ' ';
                while(isdigit(expression[index])){
                    output += expression[index];
                    ++index;
                }
                --index;
            }

            // Handle Operators
            else if(curChar == '+' || curChar == '-' || curChar == '*' || curChar == '/'){
                while(!operators.empty() && ValidPrecedence(curChar)){
                    if(!output.empty()) output += ' ';
                    output += operators.top();
                    operators.pop();
                }
                operators.push(curChar);
            }
        }
        while(!operators.empty()){
            output += ' ';
            output += operators.top();
            operators.pop();
        }
        return output;
    }

private:
    stack <char> operators;
    string expression;
    string output;
    
    char curChar = 'x';
    int expression_length = 0;
    int index = 0;
};


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    InfixToPostfix ITP;
    string input;
    
    int T = 0; cin >> T;
    while(T--){
        cin >> input;
        ITP.Default(input);
        cout << ITP.ChangeForm() << '\n';
    }
    return 0;
}