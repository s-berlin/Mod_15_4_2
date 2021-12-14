#include "chat.h"
#include "iostream"
#include "string.h"

int main() {
    char _login[LOGINLENGTH];
    char _pass[20] = {};
    int pass_length = 0;

    setlocale(LC_ALL, "");

    Chat ch1;

    cout << "Регистрация: введите логин: ";
    cin >> _login;
    cout << endl << "Регистрация: введите пароль: ";
    cin >> _pass;
    pass_length = strlen(_pass);
    cout << "Регистрация: введены логин: " << _login << "   пароль: " << _pass << "   длиной: " << pass_length << endl;

    ch1.reg(_login, _pass, pass_length);

    cout << "Регистрация: введите логин: ";
    cin >> _login;
    cout << endl << "Регистрация: введите пароль: ";
    cin >> _pass;
    pass_length = strlen(_pass);
    cout << "Регистрация: введены логин: " << _login << "   пароль: " << _pass << "   длиной: " << pass_length << endl;

    ch1.reg(_login, _pass, pass_length);

    for (int i = 0; i < 10; i++)
        cout << "логин: " << ch1.data[i].login << "   пароль: " << ch1.data[i].pass_sha1_hash << endl;

    cout << "Авторизация: введите логин: ";
    cin >> _login;
    cout << endl << "Авторизация: введите пароль: ";
    cin >> _pass;
    pass_length = strlen(_pass);
    cout << "Авторизация: введены логин: " << _login << "   пароль: " << _pass << "   длиной: " << pass_length << endl;

    if (ch1.login(_login, _pass, pass_length)) cout << "OK" << endl;
    if (!ch1.login(_login, _pass, pass_length)) cout << "No" << endl;

    return 0;
}