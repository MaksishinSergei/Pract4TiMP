#include "AlgAES.h"
#include "AlgGOST.h"

int main ()
{
    bool isTrue = true;
    string mode;
    string f_in, f_out,f_iv,password;
    cout << "Добро пожаловать! \nЧтобы узнать режимы работы программы введите \"Help\"" << endl;
    do {
        cout << "Выбирете режим работы: ";
        cin >> mode;
        if (mode == "Help") {
            cout << "Справки о режимах работы программы:" << endl;
            cout << " EG - шифрование с использованием алгоритма \"GOST\"" << endl;
            cout << " DeG - расшифрование с использованием алгоритма \"GOST\"" << endl;
            cout << " EA - шифрование с использованием алгоритма \"AES\"" << endl;
            cout << " DeA - расшифрование с использованием алгоритма \"AES\"" << endl;
            cout << " Exit - для выхода из программы" << endl;
        }
        if (mode == "EG") {
            cout << "Укажите путь до файла: ";
            cin >> f_in;
            cout << "Укажите путь до файла, где будет сохраняться результат: ";
            cin >> f_out;
            cout << "Укажите пароль: ";
            cin >> password;
            try {
                AlgorithmGost enc(f_in,f_out,password);
                enc.encodeGost(enc);
            }  catch (const CryptoPP::Exception & ex) {
                cerr << ex.what() << endl;
            }
        }
        if (mode == "EA") {
            cout << "Укажите путь до файла: ";
            cin >> f_in;
            cout << "Укажите путь до файла, где будет сохраняться результат: ";
            cin >> f_out;
            cout << "Укажите пароль: ";
            cin >> password;
            try {
                AlgorithmAES enc(f_in,f_out,password);
                enc.encodeAES(enc);
            }  catch (const CryptoPP::Exception & ex) {
                cerr << ex.what() << endl;
            }
        }
        if (mode == "DeG") {
            cout << "Укажите путь до файла: ";
            cin >> f_in;
            cout << "Укажите путь до файла, где будет сохраняться результат: ";
            cin >> f_out;
            cout << "Укажите путь до файла, в котором находится вектор инициализации: ";
            cin >> f_iv;
            cout << "Укажите пароль: ";
            cin >> password;
            try {
                AlgorithmGost dec(f_in,f_out,password,f_iv);
                dec.decodeGost(dec);
            }  catch (const CryptoPP::Exception & ex) {
                cerr << ex.what() << endl;
            } catch (const string & error) {
                cerr << error << endl;
            }
        }
        if (mode == "DeA") {
            cout << "Укажите путь до файла: ";
            cin >> f_in;
            cout << "Укажите путь до файла, где будет сохраняться результат: ";
            cin >> f_out;
            cout << "Укажите путь до файла, в котором находится вектор инициализации: ";
            cin >> f_iv;
            cout << "Укажите пароль: ";
            cin >> password;
            try {
                AlgorithmAES dec(f_in,f_out, password, f_iv );
                dec.decodeAES(dec);
            } catch (const CryptoPP::Exception & ex) {
                cerr << ex.what() << endl;
            } catch (const string & error) {
                cerr << error << endl;
            }
        }
        if (mode == "Exit") {
            cout << "Завершение работы!" << endl;
            isTrue = false;
            break;
        }
    } while (isTrue != false);

    return 0;
}
