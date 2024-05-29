#include<bits/stdc++.h>
using namespace std;

int calculate(string expression){
    int n = expression.size();
    stack<int> st;
    int sum = 0;
    int sign = 1;
    for (int i = 0; i < n; i++)
    {
        if(expression[i]>='0' && expression[i]<='9'){
            int num = 0;
            while (i<n && expression[i]>='0' && expression[i]<='9')
            {
                num = num*10 + (expression[i]-'0');
                i++;
            }
            sum += num*sign;
            i--; 
        }
        else if(expression[i]=='+'){
            sign = 1;
        }
        else if(expression[i]=='-'){
            sign = -1;
        }
        else if(expression[i]=='('){
            st.push(sum);
            st.push(sign);
            sum = 0;
            sign = 1;
        }
        else if(expression[i]==')'){
            sum*=st.top();
            st.pop();
            sum += st.top();
            st.pop();
        }
    }
    return sum;
}

int main()
{
    string expression = "(1+(4+5+2)-3)+(6+8)";
    int result = calculate(expression);
    cout<<"total: "<<result;
    return 0;
}