#include "chat.h"
#include "iostream"
#include "string.h"

int main() {
    char _login[LOGINLENGTH];
    char _pass[20] = {};
    int pass_length = 0;

    setlocale(LC_ALL, "");

    Chat ch1;

    cout << "�����������: ������� �����: ";
    cin >> _login;
    cout << endl << "�����������: ������� ������: ";
    cin >> _pass;
    pass_length = strlen(_pass);
    cout << "�����������: ������� �����: " << _login << "   ������: " << _pass << "   ������: " << pass_length << endl;

    ch1.reg(_login, _pass, pass_length);

    cout << "�����������: ������� �����: ";
    cin >> _login;
    cout << endl << "�����������: ������� ������: ";
    cin >> _pass;
    pass_length = strlen(_pass);
    cout << "�����������: ������� �����: " << _login << "   ������: " << _pass << "   ������: " << pass_length << endl;

    ch1.reg(_login, _pass, pass_length);

    for (int i = 0; i < 10; i++)
        cout << "�����: " << ch1.data[i].login << "   ������: " << ch1.data[i].pass_sha1_hash << endl;

    cout << "�����������: ������� �����: ";
    cin >> _login;
    cout << endl << "�����������: ������� ������: ";
    cin >> _pass;
    pass_length = strlen(_pass);
    cout << "�����������: ������� �����: " << _login << "   ������: " << _pass << "   ������: " << pass_length << endl;

    if (ch1.login(_login, _pass, pass_length)) cout << "OK" << endl;
    if (!ch1.login(_login, _pass, pass_length)) cout << "No" << endl;

    return 0;
}