#include <signal.h>
#include <string.h>

#include <stdexcept>
#include <iostream>

#include <string>
using std::string;

using std::cout;
using std::endl;
using std::cerr;



#include "autometal/operators/kubernetes/KubernetesOperator.h"
using ::autometal::operators::KubernetesOperator;




#include <unistd.h>


/**
 * @brief Signal termination of program
 */
static void stop( int /*sig*/ ){
    cout << "stopping" << endl;
}





int main (int argc, char **argv) {

    if( argc != 2 ){
        cerr << "Usage: " << argv[0] << " <command>" << endl;
        cerr << "See: https://github.com/homer6/autometal" << endl;
        return 1;
    }

    try{

        string command( argv[1] );

        /* Signal handler for clean shutdown */
        signal(SIGINT, stop);

        cout << command << endl;

        KubernetesOperator k8s_operator;
        

    }catch( std::exception& e ){

        cerr << "Exception caught: " << e.what() << endl;
        return 1;

    }

    return 0;

}

