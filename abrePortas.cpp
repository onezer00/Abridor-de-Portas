#include <iostream>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <error.h>
#include <string.h>

using namespace std;
struct sockaddr_in dest;

/**By: OneZer0
SCRIPT PARA ABRIR PORTAS DO ROTEADOR!!!
**/

void openPort(){
    int msocket, con, port;
    cout << "Entre com o número da porta: ";
    cin >> port;

    if((msocket = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        perror("socket");
        exit(1);
    }
    dest.sin_family = AF_INET;
    dest.sin_port = htons(port);
    bzero(dest.sin_zero, sizeof(dest.sin_zero));

    if((con = connect(msocket, (struct sockaddr *)&dest, sizeof(dest))) == -1){
        perror("connect");
        close(msocket);
        exit(1);
    }else{
        cout << "Porta aberta: " << port;
        exit(1);
    }
}

}

int main(){
    openPort();

    return 0;
}
