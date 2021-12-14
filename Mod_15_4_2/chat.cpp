#include "chat.h"
#include "iostream"
#include "string.h"

Chat::Chat() {
    data_count = 0;
}
void Chat::reg(char _login[LOGINLENGTH], char _pass[], int pass_length) {

    strcpy_s(data[data_count].login, _login);
    data[data_count].pass_sha1_hash = sha1(_pass, sizeof(_pass) - 1);
    cout << "chat: data[data_count].pass_sha1_hash = " << data[data_count].pass_sha1_hash << endl;
    data_count++;

}
bool Chat::login(char _login[LOGINLENGTH], char _pass[], int pass_length) {
    for (int i = 0; i < data_count; i++) {
        bool eq = true;
        cout << "chat: data[i].login = " << data[i].login << "   _login = " << _login << endl;
        if (strlen(data[i].login) != strlen(_login)) eq = false;
        else {
            for (int k = 0; k < strlen(data[i].login); k++) if (data[i].login[k] != _login[k]) eq = false;
        }

        if (eq) {
            cout << "chat: data[i].pass_sha1_hash = " << data[i].pass_sha1_hash << "       sha1(_pass, sizeof(_pass) - 1) = " << sha1(_pass, sizeof(_pass) - 1) << "      delta = " << data[i].pass_sha1_hash - sha1(_pass, sizeof(_pass) - 1) << endl;
            if (data[i].pass_sha1_hash == sha1(_pass, sizeof(_pass) - 1))                 return true;
        }
    }
    return false;
}