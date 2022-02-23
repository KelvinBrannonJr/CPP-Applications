#include <iostream>
#include <string>
using namespace std;


int main(int argc, char const *argv[])
{
    string alphabet{" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string encrypt_key{"[QWERTYUIOPASDFGHJKLZXCVBNMzxcvbnmlkjhgfdsaqwertyuiop"};

    string secret_message{};
    cout << "Enter a secret message to encrypt : " << endl;
    getline(cin, secret_message);


    string encrypted_message{};

    cout << "\nEncrypting message..." << endl;

  //Encryption
    for(char c:secret_message){
      size_t position = alphabet.find(c);
      if(position != string::npos){
        char new_char{encrypt_key.at(position)};
        encrypted_message += new_char;
      } else{
        encrypted_message += c;
      }
    }
      cout << "\nEncrypted message: " << encrypted_message << endl;

  //Decryption
    string decrypted_message{}; 
    cout << "\nDecrypted message..." << endl;

    for(char c:encrypted_message){
      size_t position = encrypt_key.find(c);
      if(position != string::npos){
        char new_char{alphabet.at(position)};
        decrypted_message += new_char;
      }else{
        decrypted_message += c;
      }
    }     

    cout << "\nDecrypted message: " << decrypted_message << endl;     
return 0;
}




