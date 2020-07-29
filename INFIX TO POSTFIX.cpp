#include<bits/stdc++.h>
using namespace std;

void intopost(string s)
{
    stack <char> st;
    st.push(']');
    string a;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==')')
        {
            while(st.top()!='(')
            {
                char c=st.top();
                a+=c;
                st.pop();
            }
            st.pop();
        }
        else if (s[i]=='(')
        st.push(s[i]);
        else if(s[i]=='^')
        {
            st.push(s[i]);
        }
        else if(s[i]=='/' || s[i]=='*')
        {
                while(st.top()!='+' && st.top()!='-' && st.top()!=']' && st.top()!='(')
                {
                    char c=st.top();
                    a+=c;
                    st.pop();
                }
                st.push(s[i]);
            
        }
        else if(s[i]=='+' || s[i]=='-')
        {
            while(st.top()!='(' && st.top()!=']')
            {
                char c=st.top();
                a+=c;
                st.pop();
            }
            st.push(s[i]);
        }
        else 
        {
            char c=s[i];
            a+=c;
        }
    }
    while(st.top()!=']')
    {
        char c=st.top();
        a+=c;
        st.pop();
    }
    cout<<a;
}

int main()
{
    string s="a+b*(c^d-e)^(f+g*h)-i";
    intopost(s);
    
}
