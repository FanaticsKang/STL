#include "StringBad.h"
#include <iostream>
#include <memory>
#include <string>
using std::cout;

void callme1(StringBad &rsb){
  cout << "String passed by reference: \n";
  cout << "      \"" << rsb << "\"\n";
}

void callme2(StringBad sb){
  cout << "String passed by value: \n";
  cout << "      \"" << sb << "\"\n";
}




int main() {
  using std::endl;
  {
    cout << "Starting an inner block. \n";
    StringBad headline1("Celery Stalks at Midnight");
    StringBad headline2("Lettuce Prey");
    StringBad sports("Spinach Leaves Bowl for Dollars");
    
    StringBad headline3(headline1);
    
    cout << "headline1: " << headline1 << endl;
    cout << "headline2: " << headline2 << endl;
    cout << "sports: " << sports << endl;
    cout << "headline3: " << headline1 << endl;
    
    callme1(headline1);
    cout << "headline1: " << headline1 << endl;
    
    callme2(headline2);
    cout << "headline2: " << headline2 << endl;
    
    cout << "Initialize one project to anothers\n";
    StringBad sailor = sports;
    cout << "sailor: " << sailor << endl;
    cout << "Assign one project to another: \n";
    StringBad knot;
    knot = headline1;
    cout  << "Knot: " << knot << endl;
    cout <<"Existing the block.\n";
    
  }
  cout << "End of main()" << endl;
}