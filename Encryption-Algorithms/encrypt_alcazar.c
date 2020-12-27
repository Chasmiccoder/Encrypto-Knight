/*
This file is responsible for taking a string and converting it to cipher-text using
the Alcazar Algorithm.
Its explanation can be found in the README file.
*/


#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


char* delimiter = " ";
int seed = 12345;

// len_message will have the number of characters in the original plain-text message


char* char_to_ascii_string( char character ) {
    /*
    This function takes a character and returns a string containing the ASCII form of that character.
    Example: input = 'a', return value = "097"
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


int random_integer( int lower, int upper ) {
    /*
    Function that returns a random integer from intger m (lower), to integer n(upper) [both inclusive].
    Example: input = 3,6    output = 5
    */
    int m = lower, n = upper;

    srand( time(0)+seed );
    int num = (rand() % ( n+1 - m )) + m;
    seed += num;

    return num;
}


char** char_array_to_word_list( char* message, int len_message ) {
    /*
    Convert character array to a character pointer array that holds the pointers to the words.
    Example: input = "104 105 ",    output = { "104", "105" }
    */
    static char** words;
    words = (char**)malloc(sizeof(char*) * 4*len_message);

    int i = 0, j = 0;
    int last = 0, first = 0;
    
    for ( last = 0; last < len_message*4; last++ ) {

        if ( message[ last ] == ' ' ) {
            for ( i = 0; i < last-first; i++ ) {
            
                words[ j ][ i ] = message[ i + first ];
            }
            j++;        
            first = last+1;
        } 
    }
    return words;
}

char* word_list_to_char_array( char** message ) {
    /*
    Converts a 2D character array of strings, to a single string separated by delimiter.
    */
    
}


char** generate_reordered_list( char* message, int len_message ) {
    /*
    Takes a character array of length 3 (as a pointer), and then shuffles that array and
    stores all possible permutations ( 3! = 6 ) in a character array of strings, which gets returneds
    */
    
    //static char reordered_list[ 6 ][ 3 ];
    static char** reordered_list;
    reordered_list = (char**)malloc(sizeof(char*) * 6);
    //DUNNO IF THIS WORKS OR NOT

    int ordering[ 18 ] = { 0, 1, 2,
                           0, 2, 1,
                           1, 0, 2,
                           1, 2, 0,
                           2, 0, 1,
                           2, 1, 0 };

    int i = 0, j = 0, k = 0;
    for ( i = 0; i < 6; i++ ) {
        for ( j = 0; j < 3; j++ ) {
            reordered_list[ i ][ j ] = message[ ordering[ k++ ] ];
        }
    }

    return reordered_list;                                   
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
    /*
    Takes a string as an argument (via its pointer) and then shuffles each triplet of that 
    string according to a randomly generated integer. The permutation that it got shuffled
    according to gets appended to its beginning (with which we can decrypt it later).
    */
    
    static char new_message[10000];
    int i = 0;

    char** word_list = char_array_to_word_list( message, len_message );
    char** new_list;

    for ( i = 0; i < len_message; i++ ) {
        int r = random_integer( 1, 6 );

        //reordered_list = encrypt list
        char** reordered_list = generate_reordered_list( word_list[ i ], len_message );
        
        char* new_string;
        sprintf( new_string, "%d", r);
        strcat( new_string, reordered_list[ r - 1 ] );
        strcat( new_string, delimiter );
    }

    //FINISH word_list_to_char_array( ) function and return the value.

}

int main() {

    //char* demo;
    //char c = 'A';
    //demo = char_to_ascii_string( c );
    //printf( "%s\n", demo );

    char* message = "hi";
    
    char* tierOne;
    tierOne = tier_one_encryption( message, 2 );
    printf( "TierOneMessage: %s\n", tierOne );

    //for ( int k = 0; k < 12; k++ ) {
    //   printf( "%d\n", random_integer(1,6) );
    //}

    //char* tierTwo;
    //tierTwo = tier_two_encryption( tierOne );
    //printf( "TIER TWO: %s\n", tierTwo );

    char* testo = "104 105 ";
    
    char** newguy;
    newguy = char_array_to_word_list( tierOne, 2 );
    printf( "NEWGUY: %s\n", newguy[0] );
    printf( "NEWGUY2: %s\n", newguy[1] );

    int r = 1;
    char* new_string;
    sprintf( new_string, "%d", r);
    
    printf( "YE BOII: %s\n", new_string );






    return 0;   
}
