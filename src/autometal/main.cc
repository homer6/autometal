#include <signal.h>
#include <string.h>

#include <stdexcept>
#include <iostream>

#include <string>
using std::string;

using std::cout;
using std::endl;
using std::cerr;



#include "autometal/operators/KubernetesOperator.h"
using ::autometal::operators::KubernetesOperator;

#include "autometal/operators/KafkaOperator.h"
using ::autometal::operators::KafkaOperator;

#include "autometal/operators/ZookeeperOperator.h"
using ::autometal::operators::ZookeeperOperator;




#include <unistd.h>


/**
 * @brief Signal termination of program
 */
static void stop( int /*sig*/ ){
    cout << "stopping" << endl;
}





int main (int argc, char **argv) {

    if( argc != 3 ){
        cerr << "Usage: " << argv[0] << " <command> <operators>" << endl;
        cerr << "See: https://github.com/homer6/autometal" << endl;
        return 1;
    }

    try{

        string command( argv[1] );
        string operators( argv[2] );

        /* Signal handler for clean shutdown */
        signal(SIGINT, stop);

        cout << command << endl;
        cout << operators << endl;

        size_t found = operators.find("kubernetes");
        if( found != std::string::npos ){

            KubernetesOperator kubernetes_operator;

            if( command == "install" ){
                kubernetes_operator.install();
            }
            if( command == "uninstall" ){
                kubernetes_operator.uninstall();
            }

        }


        found = operators.find("kafka");
        if( found != std::string::npos ){

            KafkaOperator kafka_operator;

            if( command == "install" ){
                kafka_operator.install();
            }
            if( command == "uninstall" ){
                kafka_operator.uninstall();
            }

        }


        

        found = operators.find("zookeeper");
        if( found != std::string::npos ){

            ZookeeperOperator zookeeper_operator;

            if( command == "install" ){
                zookeeper_operator.install();
            }
            if( command == "uninstall" ){
                zookeeper_operator.uninstall();
            }

        }


        

    }catch( std::exception& e ){

        cerr << "Exception caught: " << e.what() << endl;
        return 1;

    }

    return 0;

}

