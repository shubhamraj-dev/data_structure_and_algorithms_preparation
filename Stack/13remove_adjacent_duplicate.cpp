//problem: from a string remove all the adjacent duplicates. there should not be any 
// duplicates in the final string
//solution: using stack if top is same then pop untill different comes up and then discard that element also.
//very important : this algorithm is called in-place stack


#include<iostream>
#include<stack>
using namespace std;

string remove_adjacent(string input)
{
    int len = input.size();
    int stkptr = -1,i =0;
    while(i<len)
    {
        if(stkptr == -1 || input[stkptr]!= input[i])
        {
            stkptr++;
            input[stkptr] = input[i];
            i++;
        }
        else
        {
            while(i<len && input[stkptr] == input[i])i++;
            stkptr--;
        }
        
    }
    input[stkptr + 1] = '\0';
    return input;
}

int main()
{
    string input = "careermonk";
    input = remove_adjacent(input);
    cout<<input<<endl;
    
    return 0;
}