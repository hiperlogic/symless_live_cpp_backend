#include <string>
using namespace std;

class Client {
    public:
    Client(string username){}
    static string extract_username(const char * req_connect){
        return string("Username");
    }
    void update(string);
};