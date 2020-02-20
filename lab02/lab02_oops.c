/* Lab 2 - Instructions

   1.
   Copy this file into another file called lab2.c.
a
2.
Open another ssh/putty shell or terminal window so that you have two
  windows open.  In one window, open up lab2.c in an editor. In
  the other window compile lab2.c.

  In the window with lab2.c open, start fixing the errors according
  to the compile errors shown in the other window, leaving a comment
  before each line that contained errors.  In your comment, explain
  what the error was.

  3.
  You should always start at the top of the list of errors shown
    after compiling.  After each fix, save the file, and in the other
    window, re-compile again. You should see that list of errors
    get smaller each time you make some fixes and re-compile.
    Don't forget to use the -Wall option when compiling to see all
    the warnings that may be present:   gcc -Wall lab2.c

    There are 7 lines with errors that need to be fixed.

    4.
    Once you have all the errors fixed and comments preceding each
      line that contained an error, in the window where you did your
      compiling, open up errors.c.  Use this file to view these
      instructions in the big comment at the top. In lab2.c, you will
      get rid of this big comment at the top, so using errors.c, the
      original file, you will still have access to them.

      You want to have only your normal, proper header as required at
      the top of your program.

      5.
      Before you submit your work, you should always test your code with
      multiple test cases.  With this program, use 1 for the miles and
      see what output you get.  It should be 1.61 kilometers.
      Why is it incorrect??  Fix it so you get the correct output.

      Then test it with a couple more test cases:  2 miles should be
      3.22 km; 1000 miles should be 1609.34 km. You can use the internet
      to verify other correct answers as well.

      7.
      After you have done all these steps, and you have ensured that your
      program works, then you can submit your fixed lab2.c to Canvas.
      Your TA can help you if you have trouble doing that.
*/


#include <stdioh>

int main (void)

  int kilometers;
int miles;

// Read input from the user
printf("\n);
printf("Please enter the distance in miles: ");
scanf(%d", &miles):
print("\n");

// Calculate distance in kilometers from miles
kilometers = 1.432 * miles;

// Print the distances
printf("%d miles %is equal to ", miles);
printf("%.2d kilometers", &kilometers)
printf("\n\n");

return 0;
}
