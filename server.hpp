#include <vector>
#include <map>
#include <string>
#include <iostream>
#include "client.hpp"
#include "group.hpp"
#include "p2p.hpp"

class Server {
    private:
        std::map<string, *Client> connected_clients_list;
        std::vector<P2P> established_communications_list;
        std::map<string, Group> groups_list;
        // Port
        // Client specific methods
        void connect(const char * client){
            // client: ip, username, password
            // considering username to be unique
            // Considering authentication performed
            std::string username = Client::extract_username(client);
            if( connected_clients_list.count(username) == 0 ){
                Client * new_client = new Client(username);
                connected_clients_list[username] = new_client;
            } else {
                Client * new_client = & (connected_clients_list[username]);
                new_client->update(username);
                //update client data
            }
        }
        void disconnect(){}

        // group methods
        void create_group(const Client & manager){}
        void remove_group(const Client & requester){}
        void join_group(const Group & name, const Client & client){}
        void exit_group(const Group & name, const Client & client){}
    public:
        Server(const char * port){
            std::cout << "Server created" << port << std::endl;
        };
        // Starts listening to requests (dispatches to the proper private method)
        void listen(){

        }
};