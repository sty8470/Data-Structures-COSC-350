/*
 * A program to simulate a frog in a well.
 * It is written by Kevin Shin
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, const char **argv) {
    
    // Check that three command-line arguments are provided
    if (argc != 4) {
        cerr << "Usage: " << argv[0] << "<well-depth> <up-hops> <down-slide>" << endl;
        return 1;
    }
    
    
    // Convert the three command-line values to int values
    int well_depth = atoi(argv[1]);
    int up_hops = atoi(argv[2]);
    int down_slide = atoi(argv[3]);
    
    // STUB - display the three values
    cout << "Well depth: " << well_depth << endl;
    cout << "Hops up:    " << up_hops << endl;
    cout << "Slide down: " << down_slide << endl;
    
    // Track the day number and the frog's position on the wall
    // (the distance climbed so far)
    int day_number = 0;
    int position = 0;
    
    //    INPUT: well depth D, daytime up distance D↑, nighttime slide distance D↓
    //    OUTPUT: number of day on which escape from the well occurs or 0 if escape is impossible
    
    // REPEAT
    do {
        
        day_number += 1;     // ++day_number;
        //    position ← position + D↑
        position += up_hops;
        if ( position < well_depth) {
            // the frog is not out of the well
            //    THEN
            position -= down_slide;
        }
        //    UNTIL the frog is back at the bottom or the frog is out of the well
    } while(position > 0 and position < well_depth);
    
    if (position >= well_depth){
        //THEN
        cout << "It takes " << day_number << " days to get out of the well" << endl;
        return day_number;
    }
    else
        cout << "This frog is not able to get out of the well forever" << endl;
        return 0;
}
