#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

char WHITE_BEAD = 'w';
char RED_BEAD   = 'r';
char BLUE_BEAD  = 'b';

// when i coded this whole thing,
// i assumed that any self-respecting
// string class would have a reverse()
// method. When my context help failed
// finding reverse(), this was the best
// I could find googling. I seriously
// hope that this is my inexperience
// with std::string, because not having
// a reverse() method in a standard
// container really sucks.
string reverse( const string& s )
{
    string result;

    for( string::const_iterator index = s.end() - 1; index != s.begin() - 1; index--)
    {
        result += *index;
    }

    return result;
}

// counts the number of beads of the same color
// that can be collected from the left of a necklace
int collect( const std::string& necklace )
{
    bool color_is_set = false;
    char color_to_collect;
    int count = 0;

    // iterate through all beads
    for( int index = 0 ; index < necklace.length() ; index++ )
    {
        char current_bead = necklace[index];

        if( current_bead == WHITE_BEAD )
        {
            // white beads can always be used
            count++;
        }
        else if( ! color_is_set )
        {
            // if the color was not yet determined,
            // set the current color as the color to collect
            color_to_collect = current_bead;
            color_is_set = true;

            // the first bead of a color is always collected
            count++;
        }
        else if( current_bead == color_to_collect )
        {
            // collect another bead of the same color
            count++;
        }
        else
        {
            // bead of a different color was found, stop collecting
            break;
        }
    }

    return count;
}

int main()
{
    /* INPUT FROM FILE HERE */

    string necklace = "brbrrrbbbrrrrrbrrbbrbbbbrrrrb";

    int            max_position_beads = 0;
    int            max_split_position = 0;
    string        max_split_necklace;

    int         beads_left = 0;
    int         beads_right = 0;
    int            currect_position_beads = 0;
    int            current_split_position = 0;
    string        current_split_necklace;

    for( current_split_position = 0 ; current_split_position < necklace.length() ; current_split_position++ )
    {
        // create the necklace at the current position
        current_split_necklace = necklace.substr( current_split_position ) + necklace.substr( 0, current_split_position );

        // collect beads from the left
        beads_left = collect( current_split_necklace );

        // collect beads from the right
        beads_right = collect( reverse( current_split_necklace ) );

        // count the collected beads
        currect_position_beads = beads_left + beads_right;

        cout << "Split the necklace at position " << current_split_position;
        cout << " as " << current_split_necklace;
        cout << " and collected " << currect_position_beads << " beads";

        // check if it's greater than all splits we collected before
        if( currect_position_beads > max_position_beads )
        {
            max_split_position = current_split_position;
            max_split_necklace = current_split_necklace;

            cout << " <- this is our new maximum";
        }

        cout << endl;
    }

    cout << "If the necklace is split at position " << max_split_position;
    cout << " resulting in  " << max_split_necklace;
    cout << " you can collect " << currect_position_beads << " beads." << endl;
    cout << "No other split will collect more beads. " << endl;

    /* OUTPUT TO FILE HERE */

    return 0;
}
