//Credit to GeeksforGeeks.com on count digit function (https://www.geeksforgeeks.org/program-count-digits-integer-3-different-methods/)
//Credit to codecodex.com on calculating pi to 10 million digits function (http://www.codecodex.com/wiki/Calculate_digits_of_pi#C)

#include <iostream>
#include <sstream> //to declare the print out of digits of pi as a string
#include <iomanip> //to print out digits of pi neatly
using namespace std;

#define SCALE 10000
#define ARRINIT 2000

//Functions
string pi_digits(int digits) //Function that calculates pi to n number of digits
{
  stringstream ss; //stringstream declaration to associate a string object with the stream of digits of PI
    int carry = 0;
    int *arr = new int[digits + 1];  //Dynamic allocated array
    for (int i = 0; i <= digits; ++i)
        arr[i] = ARRINIT;
    for (int i = digits; i > 0; i-= 14)
    {
        int sum = 0;
        for (int j = i; j > 0; --j) {
            sum = sum * j + SCALE * arr[j];
            arr[j] = sum % (j * 2 - 1);
            sum /= j * 2 - 1;
        }
        ss << setw(4) << setfill('0') <<  carry + sum / SCALE; //when printing out digits of PI it sets the width of the field to 4 and doesnt not fill unused filed width with any characters

        carry = sum % SCALE;
    }
  return ss.str();
}

int count_digit(int number) //Function that counts how many digits are in a number by dividing it by 10
{
   int count = 0;
   while(number != 0) {
      number = number / 10;
      count++;
   }
   return count;
}


//DRIVER
int main(int argc, char** argv)
{
//Local variables
int zipcode;
int n = argc == 2 ? atoi(argv[1]) : 1000000;  //determines how many digits of pi to generate and search through

//n=10000; //test variable for printing out smaller digits of pi

cout<<"Enter a 5 digit zip code\n";
cin>>zipcode;

while(cin.fail()) //Error checking
{
    cin.clear();  //Clear previous input
    cin.ignore(1234345556564546, '\n');  //Discard previous input
    cout<<"ERROR: Enter a valid 5 digit zip code\n";
    cin>>zipcode;
}

while(count_digit(zipcode)!=5 || zipcode < 0) //5 digit integer validation
{
    cout<<"ERROR: Enter a valid 5 digit zip code\n";
    cin>>zipcode;
}

string zip = to_string(zipcode); //convert zip code to string to compare to digits of pi
string pi = pi_digits(n);
cout << "Digits of PI: " << pi << endl; //Output digits of PI to screen

size_t found = pi.find(zip); //size_t is an unsigned integer type of the sizeof operator. size_t is able to represent size of any object in bytes.
//pi.find() is used for finding a specified substring, in this case zipcode is the substring.

if (found != string::npos) //npos acts as null but defined in string. So if its null, that means not found.  If it is not null, then zip code is found.
//npos is a static member constant value with the greatest possible value for an element of type size_t.
//This value, when used as the value for a len (or sublen) parameter in string's member functions, means "until the end of the string".

    cout << "Zip code found at position " <<found<< " in PI"<< endl;

else
    cout << "Zip code was not found in PI." << endl;

    return 0;
}






