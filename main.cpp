#include <iostream>
#include "list.h"

using namespace std;

int main()
{
    Double_Linked_List list;
    string value, key;

    setlocale (LC_CTYPE, "ukr");

    while(true)
    {
        cout << "----------------------------------------------------------------------------" << endl;
        cout << "1.Додати на початок, 2.Додати в кінець, 3.Вміст списку, 4.Видалити з початку" << endl;
        cout << "5.Видалити з кінця, 6.Пошук, 7.Вставка в середину, 8.Видалити з середини" << endl;
        cout << "9.Відображення по індексу, 10.Вихід" << endl;
        cout << "----------------------------------------------------------------------------" << endl;
        int choose;
        cin >> choose;
        cin.ignore();

        switch (choose)
        {
        case 1: { cout << "Введіть елемент: "; getline(cin, value);
                  list.Add_begin(value);
                  break;
                }
        case 2: { cout << "Введіть елемент: "; getline(cin, value);
                  list.Add_end(value);
                  break;
                }
        case 3: { list.Show();
                  break;
                }
        case 4: { list.Del_begin();
                  break;
                }
        case 5: { list.Del_end();
                  break;
                }
        case 6: { cout << "Введіть ключ пошуку: "; getline(cin, key);
                  if(list.Search(key)) cout << "Eлемент існує в списку!" << endl;
                  break;
                }
        case 7: { cout << "Введіть ключ пошуку: "; getline(cin, key);
                  cout << "Введіть значення: "; getline(cin, value);
                  list.Add_mid(key, value);
                  break;
                }
        case 8: { cout << "Введіть ключ пошуку: "; getline(cin, key);
                  list.Del_mid(key);
                  break;
                }
//        case 9: { int index;
//                  cout << "Введіть індекс: "; cin >> index;
//                  cout << list[index] << endl;
//                  break;
//                }
        case 10: { exit(0);
                  break;
                }

        default: { break; }

        }

    }

    return 0;
}
