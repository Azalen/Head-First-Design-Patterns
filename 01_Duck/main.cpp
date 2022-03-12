#include "duck.h"

/**     DESIGN PRINCIPLE : Identify aspects of your application that vary and separate them from what stays the same
 *      DESIGN PRINCIPLE : Program to an interface, not an implementation
 * 
 *      => DELEGATE flying and quacking behaviour to separate classes instead of trying to implement them on Duck itself
 *      => Use pointer/references to access an object of that delegated class and perform the needed function
 *  
 * */

int main() {

    Stockente * se = new Stockente();

    se->fliegen();
    se->quack();
    se->schwimmen();

    FliegenNichtMoeglich * fnm = new FliegenNichtMoeglich;
    se->setzeFlugverhalten(fnm);

    se->fliegen();

    return 0;
}