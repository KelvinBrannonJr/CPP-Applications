#include <iostream>
#include <fstream>


// return true if the string word_to_find is in the target string
bool find_substring(const std::string &word_to_find,const std::string &target){
    std::size_t found = target.find(word_to_find);
    if(found == std::string::npos)      // npos "No position"
        return false;
    else 
        return true;
}

int main(int argc, char const *argv[])
{
    std::ifstream in_file{};
    std::string word_to_find{};
    std::string word_to_read{};
    int word_count{0};
    int match_count{0};

    // Include any Text.txt file in your project folder
        // Reference the full file path inside the 'in_file.open()' 
    in_file.open("/ full Path to Your text.txt file in here /");
    if(!in_file){
        std::cerr << "File did not open.. " << std::endl;
            return 1;
    }else 
        std::cout << "File was sucessfully found and opened " << std::endl;

    std::cout <<  "Enter the substring to search for: " << std::endl;
    std::cin >> word_to_find;

    

    while(in_file >> word_to_read){
        ++ word_count;
        if(find_substring(word_to_find,word_to_read)){
            ++ match_count;
        }
    }
    std::cout << std::endl;
    std::cout << word_count << " total words have been searched.. " << std::endl;
    std::cout << "The substring: " << word_to_find << std::endl;
    std::cout << "was found: " << match_count << " times" << std::endl;

    in_file.close();
    return 0;
}
