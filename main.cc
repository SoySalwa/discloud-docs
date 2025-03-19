#include <drogon/HttpAppFramework.h>
#include <drogon/drogon.h>

// Todo programa de C++ empieza con una funcion main.
int main() {
    //Set HTTP listener address and port
    drogon::app().addListener("0.0.0.0", 5555).setDocumentRoot("/home/salwa/Documents/MyProjects/discloud-docs/public");
    drogon::app().run();
    return 0;
}
