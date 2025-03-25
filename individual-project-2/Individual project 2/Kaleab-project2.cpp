//1. Create a function that fills a string with 26 randomized lowercase letters, none of which repeat. In main, print the randomized lowercase letters.- done

//2. Create a replacement function that encrypts a string of any length with the randomized string of letters. (In other words 'a' in the original message is replaced with
//the first randomized lowercase letter from the string created above.)  In main, print the unencrypted string, and the encrypted string. Use the unencrypted string
//"theyre going to open the gate at azone at any moment amazing deep untracked powder meet me at the top of the lift"

//3. Create a function that takes an input string and counts the frequency that the letters of the alphabet occur.  (for example in the string "for example in the string", the frequency of 'a' is 1, e is 3, f is 1, g is 1, i is 2, l is 1 m is , n is 2, p is 1, r is 2, s is 1, t is 2, x is 1, and all the rest are 0.)

//4. Create a function that prints the frequency array created by the previous function like this: a: x

//5. Some frequently occurring  letters in the English language are "ETAONMH" in that order. Create a string with those letters. -done
//6.Using the string with those letters, the encrypted string you created, and the frequency count, substitute the most frequently occurring letter in the encrypted
//string with the first letter in the most frequent letter (E), the next most frequently occurring letter in the

//7. Print the "decrypted" string.  (It will not be completely decrypted)


#include <iostream> // main library file
#include <cctype> // char testing library
#include <string> //string library file
#include <ctime> //time initalizer
#include <cstdlib> //for srand and rand

using namespace std; //task simplfyer

//fills string with random non-repeating lowercase letters
void fillRandomLetter(string* letter, int size);
//fills string with random non-repeating lowercase letters
void replace(string* words, string letter, int size);
//counts the frequency of the repeating letters in string
int* countLetterFrequency(string words);
//prints the frequency count of the repeating letters
void printFrequency(int lFreq[]);
//replaces the most freq letters in encrypted string with ETANOMAH(most freequent words)
void decrypt(string* freqWords, string* words, int* lFreq);
//prints the dycrypted string from above
void printDecrypted(string* word);

int main()
{
    srand((unsigned)time(0)); // get the system time
    const int SIZE = 26; // initializing const size
    string letter; //declaring string
    string word = "theyre going to open the gate at azone at any moment amazing deep untracked powder meet me at the top of the lift"; //declaring and initalizing word
    int* count;
    string freqWords = "ETANOMAH"; //declaring and initalizing freqWords
    
    fillRandomLetter(&letter, SIZE); //calling function
    cout << "Printing random lowercase letters: \n";
    cout << letter << endl; //printing letter after being filled
    cout << endl;
    cout << "Printing unencrypted text: \n";
    cout << word << endl; //unecrypted text
    cout << endl;
    replace(&word, letter, SIZE);
    cout << "Printing encrypted text: \n";
    cout << word << endl; //ecrypted text
    count = countLetterFrequency(word);
    printFrequency(count);
    cout << endl;
    return 0; //ending program
}

void fillRandomLetter(string* letters, int size) //function declaration for fillRandomLetter-DONE
{
    bool unique; //declaring boolean unique
    char ch; //declaring char ch
    char lt[size]; //declaring char lt array
    string alpha; //declaring string alpha to hold lt
    
    for(int i=0;i<size;i++) //for loop to get to get value of lt array
    {
        do //do-while loop to verify and check whether the letter doesn't repeat
        {
            //initalize boolean unique
            unique=true;
            //initalizing ch with random letter
            ch = 'a' + rand()%26;
            //for loop to compare values with the first loop
            for(int j=0;j<i;j++)
            {
                if(lt[j] == ch) //if statement- to check whether ch element in array is already present
                {
                    // re-initalize unique to false so the do-while loop can check the values again
                    unique=false;
                    //break loop if the same letter
                    break;
                }
            }
        }while(!unique);//so it can stop if unique is true
        // initalize lt array
        lt[i] = ch;
    }
    //assigning lt elements in array to alpha string- size times
    alpha.append(lt,size);
    //assining alpha to pointer string letter
    *letters = alpha;
}

void replace(string* words, string letter, int size)
{
    char find = 'a';
    string wrds = *words ; //initalizing string to an indirection pointer to make the task easier
    int length = wrds.length(); //getting string length for wrds
    int length2 = letter.length(); //getting string length for letter
    string newWords;// to store the replaced string
    bool check; //to check validity
    
    // declaring then copying the strings to char to count through each character
    char original[length+1];
    strcpy(original, wrds.c_str());
    char ltr[length2+1];
    strcpy(ltr, letter.c_str());

    // loop to go through each character
    for(int i = 0; i < length; i++)
    {
            do // loops replace each char with randomized letter
            {
                check = true;
                find++;
                if(original[i] == find) // checks if letter is in original
                {
                    check = false; // returns false since the loop is done in reverse to continue looking for the letters
                    break; // breaks the loop to search again
                }
                else
                    check = true;// returns true if it isn't present
            }while(!check);
        original[i] = ltr[i];
            
        //find++;
    }
    //appending ff char to newWords(string)
    newWords.append(original,length);
    //assining newWords to pointer string words
    *words = newWords;
    
}

int* countLetterFrequency(string words) //counts freq of each letter in string
{
    int i = 0, j = 0; // will be used at iterators that aid in finding each letter
    int freq[26]={0};
    char* strPtr;
    strPtr = new char[words.length()]; //dynamically create a c-string array to hold words
    strcpy(strPtr, words.c_str()); //changing to C-string to make it easier to count freq
    
    while(strPtr[i] != '\0')
    {
        if(strPtr[i] >= 'a' & strPtr[i] <= 'z') //error checking
        {
            j = strPtr[i] - 'a'; // gets the position at which strPtr[i] - 'a' is
            ++freq[j]; //moving through the loop to find same letters
        }
        ++i;
    }
    int* ptrFreq; // declaring a pointer to hold freq
    ptrFreq = freq; // assigning freq to pointer
    return ptrFreq; // returning pointer(freq)
}

void printFrequency(int lFreq[]) //prints the frequency of each character
{
    cout << endl;
    char print = 'x'; //to show num of char occuring
     
    for( int j = 0; j < 26; j++) // actually works but string didnt work properly so all letters occur 2X
    {
        cout << char('a' + j) << ":";
        for( int i = 0; i < lFreq[i]; i++) // loop to print x
            cout << print; // prints x based on each letter frequency
        cout << endl;
    }
}

//6.Using the string with those letters, the encrypted string you created, and the frequency count, substitute the most frequently occurring letter in the encrypted
//string with the first letter in the most frequent letter (E), the next most frequently occurring letter in the


//7. Print the "decrypted" string.  (It will not be completely decrypted)

void decrypt(string* freqWords, string* words, int* lFreq) //replaces the most freq letters in encrypted string with ETANOMAH(most freequent words)
{
    
}
void printDecrypted(string* word) //prints the dycrypted string from above
{
    
}
