#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


bool is_palindrome(const std::string& s)
{
    std::queue<char>q;
    std::stack<char>st;

    // add all the string characters that are alpha to the bottom of the stack and back of the queue, convert result to uppercase

    for(char c: s)
        if(std::isalpha(c)){
        q.push(std::toupper(c)); 
        st.push(std::toupper(c));
        }    

        char c1{};
        char c2{};

        // remove and compare the front character with the back character
        // if they are not the same - return false since it cant be a palindrome
        // if you complete the loop then the string must be a palindrome so return true

        while(!q.empty()){
            c1 = q.front();
            q.pop();
            c2 = st.top();
            st.pop();
            
            if(c1 != c2)
                return false;
        }
        return true;

}

int main(int argc, char const *argv[])
{
    std::vector<std::string>test_strings{"a", "aa","aba", "abba","abbcbba","ab","abc","radar","bob","ana",
    "avid diva","Amore, Roma","A Toyota's a toyota","A Santa at NASA","C++",
    "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!","This is a palindrome","palindrome"};

    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s: test_strings){
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }

    std::cout << std::endl;
    
    return 0;
}
