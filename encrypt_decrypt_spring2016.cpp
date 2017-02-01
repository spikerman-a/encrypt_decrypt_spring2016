
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;

int const LETTERS = 26;
int const ASCII_VARIABLE = 65;
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


/*
 encryption function
    takes in a string (plaintext message to be encrypted) an an 
    integer (the seed value) and encrypts the plaintext message
 */
string encrypt(string m, int s)
{
    srand(s);                    //sets the seed for the random function to be s input
    
    string mess_encrypt;
    string final = "";
    
    int en, convert_algo, m_algo;            //declares integer variables for function
    char alpha, char_encrypt;              //decalres character variables for function
    
    for (int i = 0; i < m.length(); i++)
    {
        int variable = rand()%LETTERS;
        
        for (int j = 0; j < alphabet.length(); j++)
        {
            if (alphabet[j] == m[i])
            {
                alpha = alphabet[j];                 //the character alpha is equal to
                //the character of the alphabet that satisfies
                //the if statement
                en = (int)alpha - ASCII_VARIABLE;             //converts the character
                //into an integer based off of the ASCII table
                //and then subtracts the ASCII number to set A to int 0
                m_algo = (en + variable)%LETTERS;
                //begins algorithim for the conversion (encryption)
                //adds the random variable to the ASCII int
                //mod letters to get the letter value between 0 and 25
                
                convert_algo = m_algo + ASCII_VARIABLE;
                //converts the new int to an ASCII table usable int
                
                char_encrypt = static_cast<char>(convert_algo);
                //converts the int to a character using
                //the ASCII Table
                
                stringstream char_mess;                //assigns this category to this
                //variable to create a medium
                //to switch from char to string
                char_mess << char_encrypt;               //stores encrypted characters
                //into stringstream
                char_mess >> mess_encrypt;               //assigns stringstream values
                //to the string
                
                final = final + mess_encrypt;            //stores previous loop values
                //(mess_encrypt) into the variable 'final'
            }
        }
    }
    return final;                                     //returns final to main function
}


/*
 decryption function
    takes in a string (ciphertext message) an an integer (the seed value)
    and decrypts the plaintext message using the seed value
 ** NOTE ** 
    seed value for decryption must be same seed value used for encryption
 */
string decrypt(string m, int s)
{
    srand(s);                    //sets the seed for the random function to be s input
    
    string mess_decrypt;
    string final = "";

    int en, convert_algo, m_algo;            //declares integer variables for function
    char alpha, char_decrypt;              //decalres character variables for function
    
    for (int i = 0; i < m.length(); i++)
    {
        int variable = rand()%LETTERS;
        
        for (int j = 0; j < alphabet.length(); j++)
        {
            if (alphabet[j] == m[i])
            {
                alpha = alphabet[j];                 //the character alpha is equal to
                //the character of the alphabet that satisfies
                //the if statement
                en = (int)alpha - ASCII_VARIABLE;             //converts the character
                //into an integer based off of the ASCII table
                //and then subtracts the ASCII number to set A to int 0
                m_algo = (en - variable)%LETTERS + LETTERS;
                //begins algorithim for the conversion
                //subtracts (decrypt) the random variable
                //from the ASCII int mod letters to get a
                //variable number and adds letters back to
                //assure non-negative integer
                
                convert_algo = m_algo%LETTERS + ASCII_VARIABLE;
                //takes mod again to assure int between 0
                //and 25 and adds ASCII table variable
                //back to prepare for conversion to char
                
                char_decrypt = static_cast<char>(convert_algo);
                //converts int to character letter
                
                stringstream char_mess;                //assigns this category to this
                //variable to create a medium
                //to switch from char to string
                char_mess << char_decrypt;          //stores decrypted characters into
                //stringstream for conversion to string
                char_mess >> mess_decrypt;    //stores stringstream values into string
                
                final = final + mess_decrypt;            //stores previous loop values
                //(mess_decrypt) into the variable 'final'
            }
        }
    }
    return final;                                      //returns final string variable
}


int main()                                                      //main function to run
{
    int seed;                         //seed value will affect random function outputs
    cout << "PLEASE ENTER A SEED VALUE: ";                      //program prompts user
    cin >> seed;                                                    //user inputs seed
    
    string instruction;      //instruction string will decide encryption or decryption
    cout << "WOULD YOU LIKE TO ENCRYPT OR DECRYPT A MESSAGE? "; //program prompts user
    cin >> instruction;                                      //user inputs instruction
    
    string message;                                           //declares message input
    
    if (instruction == "ENCRYPT")                                      //if encryption
    {
        cout << "PLEASE ENTER A MESSAGE TO ENCRYPT: ";          //program prompts user
        cin.ignore(100,'\n');                       //allows the getline(cin, message)
                                                            //function to retain value
        getline(cin, message);                                   //user inputs message
        
        string encryption = encrypt(message, seed); //encrypt function runs and return
                                                   //value stored in string for output
        
        cout << encryption << endl;                              //output return value
    }
    if (instruction == "DECRYPT")                                      //if decryption
    {
        cout << "PLEASE ENTER A MESSAGE TO DECRYPT: ";          //program prompts user
        cin.ignore(100,'\n');                       //allows the getline(cin, message)
                                                            //function to retain value
        getline(cin, message);                                   //user inputs message
        
        string decryption = decrypt(message, seed); //decrypt function runs and return
                                                   //value stored in string for output
        
        cout << decryption << endl;                              //output return value
    }
    
    return 0;
}




