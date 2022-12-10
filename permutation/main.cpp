#include <iostream>
#include <fstream>
#include <cstring>
#include <set>

using namespace std;

void RecPermute( string soFar , string rest , set < string >& s )
{
    if ( rest == "" )
        s.insert( soFar );
    else
    {
        for ( int i = 0; i < (int)rest.length(); i++ )
        {
            string next = soFar + rest[i];
            string remaining = rest.substr( 0 , i ) + rest.substr( i+1 );
            RecPermute( next , remaining , s );
        }
    }
}

void listPermuations( string s , set < string > & _set )
{
    RecPermute( "" , s , _set );
}

int main()
{
    string s = "";
    cout << "Enter the string : "; cin >> s;

    set < string > PermutationSet;
    listPermuations( s , PermutationSet );

    string choice;
    while ( true )
    {
        cout << "1- Print all permutation on the screen\n";
        cout << "2- Print all permutation on file \n";
        cout << "Choice : "; cin >> choice;

        if ( choice == "1" || choice == "2" ) break;
        else
        {
            cout << "Invalid input\n";
            system( "Pause" ); system( "CLS" );
        }
    }

    if ( choice == "2" )
    {
        string fileName;
        cout << "Enter the name of the file : "; cin >> fileName;

        freopen( fileName.c_str() , "w" , stdout );

        for ( auto str : PermutationSet )
            cout << str << "\n";
    }
    else
    {
        for ( auto str : PermutationSet )
            cout << str << "\n";
        system( "Pause" );
    }
    return 0;
}



/**
void listPermuations_2( int index , string s , set < string >& st )
{
    if ( index == (int)s.length() )
    {
        st.insert( s );
        return;
    }

    for ( int i = index; i < (int)s.length(); i++ )
    {
        swap( s[ index ] , s[ i ] );
        listPermuations_2( index + 1 , s , st );
        swap( s[ index ] , s[ i ] );
    }
}
**/

