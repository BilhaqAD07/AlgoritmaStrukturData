#include <bits/stdc++.h>
using namespace std;
 
// Function to print the characters 
// in sorted order 
void printSorted(string s, int l)
{
     
    // Primary stack
    stack<char> Stack; 
     
    // Secondary stack
    stack<char> tempstack; 
       
    // Append first character  
    Stack.push(s[0]);
     
    // Iterate for all character in string 
    for(int i = 1; i < l; i++)
    {
         
        // i-th character ASCII 
        int a = s[i];
         
        // stack's top element ASCII 
        int b = Stack.top(); 
           
        // If greater or equal to top element 
        // then push to stack 
        if ((a - b) >= 1 or (a == b))
            Stack.push(s[i]); 
               
        // If smaller, then push all element 
        // to the temporary stack 
        else if ((b - a) >= 1)
        {
             
            // Push all greater elements 
            while ((b - a) >= 1)
            {
                 
                // Push operation 
                tempstack.push(Stack.top());
                Stack.pop();
                 
                // Push till the stack is not-empty 
                if (Stack.size() > 0)
                    b = Stack.top();
                else
                    break;
            }
                       
            // Push the i-th character 
            Stack.push(s[i]);
             
            // Push the tempstack back to stack 
            while (tempstack.size() > 0)
            {
                Stack.push(tempstack.top());
                tempstack.pop();
            }
        }
    }
     
    // Print the stack in reverse order
    string answer;
    while (Stack.size() > 0)
    {
        answer = Stack.top() + answer;
        Stack.pop();
    }
    cout << answer << endl;
}
 
// Driver Code   
int main()
{
    string input;
    getline(cin, input);
    int l = input.length();
     
    printSorted(input, l);
     
    return 0;
}
 