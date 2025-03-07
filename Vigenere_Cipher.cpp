#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void up_case(string &s){
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    for(auto &c : s){
        c = toupper(c);
    }
} 

/*----------ENCRYPTED----------*/
vector<string> user_input(){
        //Get user password and convert it into full uppercase
        string password;
        do{ 
            cout << "Enter your password: ";
            getline(cin, password);
     
            if(password.empty()){
                cout << "Password cannot be empty!" << endl;
            }
        } while(password.empty());
    
        up_case(password);
    
        //Get user key and convert it into full uppercase;
        string key;
        do{
            cout << "Enter your key: ";
            getline(cin, key);
    
            if(key.empty()){
                cout << "Key cannot be empty!" << endl;
            }
        } while(key.empty());
    
        up_case(key);

        return {password, key};
}

vector<char> ciphering(string password, string key){
    vector<char> pwd;
    for(int i = 0; i < password.length(); i++){
        if(password[i] != ' '){
            pwd.push_back(password[i]);
        }
    }

    vector<char> chain;
    for(int i = 0; i < pwd.size(); i++){
        chain.push_back(key[i%(key.size())]);
    }

    vector<char> cipher;
    for(int i = 0; i < pwd.size(); i++){
        int d = (pwd[i] + chain[i] - 2 * 'A') % 26;
        cipher.push_back('A' + d);
    }

    return cipher;
}

int main(){
    vector<string> user = user_input();
    vector<char> vigen = ciphering(user[0], user[1]);
    for(int i = 0; i < vigen.size();i++){
        if(i != 0 && i % 5 == 0){
            cout << " ";
        }
        cout << vigen[i];
    }

    return 0;
}