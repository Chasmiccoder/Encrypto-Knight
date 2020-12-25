/*
This file is responsible for taking a string and converting it to cipher-text using
the Dynamic Alcazar Algorithm.
Its explanation can be found in the README file.
*/

#include <stdio.h>
#include <string.h>

char* delimiter = " ";

char* char_to_ascii_string( char character ) {
    /*
    This function takes a character and returns a string containing the ASCII form of that character.
    Example: input = 'a', return value = '097'
    */
    int number = (int) character;
    static char num_in_str_format[3] = "---";
    int i = 2;

    while ( number > 0 ) {
        num_in_str_format[ i-- ] = number%10 + '0';
        number = number / 10;
    }

    if (num_in_str_format[ 0 ] == '-') {
        num_in_str_format[ 0 ] = '0';
    }
    
    return num_in_str_format;
}

int random_integer( ) {
    /*
    Function that returns a random integer from intger m, to integer n (both inclusive).
    Example: input = 3,6    output = 5
    */
}


char* tier_one_encryption( char* message, int len_message ) {
    /*
    Converting a string to its ascii form and separating each character's ascii string by white spaces.
    Example: input = 'hi', return value = '104 105 '
    */
    static char new_message[10000];
    char* character_ascii;
    int i = 0;
    
    for ( i = 0; i < len_message; i++ ) {
        char c = message[i];
        character_ascii = char_to_ascii_string( c );
        strcat( new_message, character_ascii );
        strcat( new_message, delimiter );
    }

    return new_message;
}

char* tier_two_encryption( char* message, int len_message ) {
    static char new_message[10000];


}

int main() {
    char* demo;
    char c = 'A';
    demo = char_to_ascii_string( c );
    printf( "%s\n", demo );

    char* message = "hi";
    char* tierOne;
    tierOne = tier_one_encryption( message, 2 );
    printf( "TierOneMessage: %s\n", tierOne );

    return 0;   
}
