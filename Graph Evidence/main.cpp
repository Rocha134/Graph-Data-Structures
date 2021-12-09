//Francisco Rocha Juarez
//Aldo Mauricio Cruz Lozada
//Iker Guerrero
#include <bits/stdc++.h>
using namespace std;

struct Register {
    string port;
    string text;
    string date;
    string time_hour;
    Register* nextRegi;
};

struct Host {
    string host;
    Host* nextHost;
    Register* headRegis;
    int numRegis;
};

struct Network {
    string network;
    Network* nextNet;
    Host* headHost;
    int quantity_host;
};

//O(n)
//Function to avoid repeated Networks
Network* available_network(string thisNetwork, Network* head) {
   while (head != NULL) {
     if(head -> network == thisNetwork){
       return head;
     }
      head = head -> nextNet;
  }
  return NULL;
}

//O(n)
//Function to avoid repeated Hosts
Host* availableHost(string thisHost, Host* head) {
  while (head != NULL) {
    if(head -> host == thisHost) {
      return head;
    }
    head = head -> nextHost;
  }
  return NULL;
}

//O(n)
vector<string> ip_separation(string thisIP) {
  string IP_separator1 = ".";
  string IP_separator2 = ":";
  int position = 0;
  string aux;

  vector<string> IP_list;
  vector<string> final_IP;

  while ((position = thisIP.find(IP_separator1)) != string::npos) {
    aux = thisIP.substr(0, position);
    thisIP.erase(0, position + IP_separator1.length());
    IP_list.push_back(aux);
  }

  position = 0;

  while ((position = thisIP.find(IP_separator2)) != string::npos) {
    aux = thisIP.substr(0, position);
    thisIP.erase(0, position + IP_separator2.length());
    IP_list.push_back(aux);
  }
  IP_list.push_back(thisIP);

  final_IP.push_back(IP_list[0]+"."+IP_list[1]);
  final_IP.push_back(IP_list[2]+"."+IP_list[3]);
  final_IP.push_back(IP_list[4]);

  return final_IP;
}

//O(n)
void add_new_register(string thisPort, string thisDate, string thisTimeHour, string thisText, Register* &head) {
  Register* newRegister = new Register();
  Register* last = head;
  newRegister -> port = thisPort;
  newRegister -> text = thisText;
  newRegister -> date = thisDate;
  newRegister -> time_hour = thisTimeHour;
  newRegister -> nextRegi = NULL;

  if(head == NULL) {
    head = newRegister;
  } else {
    while(last -> nextRegi != NULL){
      last = last -> nextRegi;
    }
    last -> nextRegi = newRegister;
  }
}

// O(n)
void add_new_host(string thisHost, string thisPort, string thisDate, string thisTimeHour, string thisText, Host* &head){
  Host* new_host = new Host();
  Host* last = head;
  new_host -> host = thisHost;
  new_host -> nextHost = NULL;
  new_host -> headRegis = NULL;
  new_host -> numRegis = 0;
  add_new_register(thisPort, thisDate, thisTimeHour, thisText, new_host -> headRegis);
  if(head == NULL) {
    head = new_host;
  } else {
    while(last -> nextHost != NULL){
      last = last -> nextHost;
    }
    last -> nextHost = new_host;
  }
}

//O(n)
void add_new_network(string thisNetwork, string thisHost, string thisPort, string thisDate, string thisTimeHour, string thisText, Network* &head) {
  Network* newNetwork = new Network();
  Network* last = head;
  newNetwork -> network = thisNetwork;
  newNetwork -> nextNet = NULL;
  newNetwork -> headHost = NULL;
  newNetwork -> quantity_host = 0;
  add_new_host(thisHost, thisPort, thisDate, thisTimeHour, thisText, newNetwork -> headHost);

  if(head == NULL) {
    head = newNetwork;
  } else {
    while(last -> nextNet != NULL){
      last = last -> nextNet;
    }
    last -> nextNet = newNetwork;
  }
}

//O(n)
void printNetwork(Network* aNetwork) {
  Network* thisNetwork = aNetwork;
  int maximum_hosts = 0;
  while(thisNetwork != NULL) {
    if(maximum_hosts < thisNetwork -> quantity_host) {
      maximum_hosts = thisNetwork -> quantity_host;
    }
    thisNetwork = thisNetwork -> nextNet;
  }
  thisNetwork = aNetwork;
  while(thisNetwork != NULL) {
    if(maximum_hosts == thisNetwork -> quantity_host) {
      cout << thisNetwork -> network << endl;
    }
    thisNetwork = thisNetwork -> nextNet;
  }
}

//O(n^2)
void printNetworkHost(Network* aNetwork) {
  Network* thisNetwork = aNetwork;
  int maxRegisters = 0;
  while(thisNetwork != NULL) {
    Host* thisHost = thisNetwork -> headHost;
    while(thisHost != NULL) {
      if(maxRegisters < thisHost -> numRegis) {
        maxRegisters = thisHost -> numRegis;
      }
      thisHost = thisHost -> nextHost;
    }
    thisNetwork = thisNetwork -> nextNet;
  }

  thisNetwork = aNetwork;

  while(thisNetwork != NULL) {
    Host* thisHost = thisNetwork -> headHost;
    while(thisHost != NULL) {
      if(maxRegisters == thisHost -> numRegis) {
        cout << thisNetwork -> network << "." << thisHost -> host << endl;
      }
      thisHost = thisHost -> nextHost;
    }
    thisNetwork = thisNetwork -> nextNet;
  }
}

//O(1)
void network_counter(Network* &aNetwork) {
  aNetwork -> quantity_host ++;
}

//O(1)
void host_counter(Host* &aHost) {
  aHost -> numRegis ++;
}

int main() {

  string month_in, day_in, hour_in, ip_in, message_in;
  Network* head = NULL;
  ifstream input("bitacora2.txt");

  while(!input.eof()) {
    getline(input,month_in,' ');
    getline(input,day_in,' ');
    getline(input,hour_in,' ');
    getline(input,ip_in,' ');
    getline(input,message_in);
    string date = month_in + " " + day_in;
    vector<string> ipAct = ip_separation(ip_in);
    Network* newNetwork = available_network(ipAct[0], head);
    if(newNetwork == NULL) {
      add_new_network(ipAct[0], ipAct[1], ipAct[2], date, hour_in, message_in, head);
    } else {
      Host* new_host = availableHost(ipAct[1], newNetwork -> headHost);
      if(new_host == NULL) {
        add_new_host(ipAct[1], ipAct[2], date, hour_in, message_in, newNetwork -> headHost);
        network_counter(newNetwork);
      } else {
        add_new_register(ipAct[2], date, hour_in, message_in, newNetwork -> headHost -> headRegis);
        host_counter(new_host);
      }
    }
  }

  printNetwork(head);

  printNetworkHost(head);

  return 0;
}
