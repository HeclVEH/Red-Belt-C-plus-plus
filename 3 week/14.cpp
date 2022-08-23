//Вариант 1
//Составить программу, которая содержит динамическую информацию о наличии
//автобусов в автобусном парке.Сведения о каждом автобусе включают :
//1. номер автобуса;
//2. фамилию и инициалы водителя;
//3. номер маршрута.
//Программа должна обеспечивать :
//1. начальное формирование данных обо всех автобусах в парке в виде
//односвязного списка;
//2. вывод всех автобусов;
//3. добавление автобуса в начало списка;
//4. добавление автобуса перед определенным автобусом;
//5. по запросу выдаются сведения об автобусах, находящихся в парке, или об
//автобусах, находящихся на маршруте.
//6. при выезде каждого автобуса из парка вводится номер автобуса, и
//программа удаляет данные об этом автобусе из списка автобусов, находящихся в парке,
//и записывает эти данные в список автобусов, находящихся на маршруте;
//7. при въезде каждого автобуса в парк вводится номер автобуса, и программа
//удаляет данные об этом автобусе из списка автобусов, находящихся на маршруте, и
//записывает эти данные в список автобусов, находящихся в парке;

#include <iostream>
#include <string>

using namespace std;

struct Node {
    int nym_bus, nym_rout;
    bool condit;
    string name_driv;
    Node* next;
};
typedef Node* PNode;
PNode Head = nullptr;

void correct_cin_int(int& z) {
    while (!(cin >> z) || (cin.peek() != '\n')) {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Error!!! Try again!" << endl;
    }
}

PNode CreateNode() {
    PNode NewNode = new Node; // указатель на новый узел
    cout << "Enter name driver: ";
    cin >> NewNode->name_driv;
    cout << "Enter nymber bus: ";
    correct_cin_int(NewNode->nym_bus);
    NewNode->nym_rout = NewNode->condit = 0;
    NewNode->next = NULL; // следующего узла нет
    return NewNode; // результат функции – адрес узла
}

void AddFirst(PNode& Head, PNode NewNode) {
    NewNode->next = Head;
    Head = NewNode;
}

void AddAfter(PNode p, PNode NewNode) {
    NewNode->next = p->next;
    p->next = NewNode;
}


void AddBefore(PNode& Head, PNode p, PNode NewNode) {
    PNode q = Head;
    if (Head == p) {
        AddFirst(Head, NewNode); // вставка перед первым узлом
        return;
    }
    while (q && q->next != p) // ищем узел, за которым следует p
        q = q->next;
    if (q) // если нашли такой узел,
        AddAfter(q, NewNode); // добавить новый после него
}


void add_bus_info(Node*& bus_park) {
    PNode ptr = CreateNode();    
    cout << "-----------------------------------------------------------------------\n";
    cout << "How you want to add the info about bus?\nInput 1 in the start of list\nInput 2 in the end of the list\n"
        << "Input 3 in front of a specific bus\n";
    int query;
    correct_cin_int(query);
    switch (query) {
    case 1: {
        AddFirst(bus_park, ptr);       
    }
          break;
    case 2: {
        if (bus_park) {
            for (auto ptr2 = bus_park;; ptr2 = ptr2->next)
                if (!ptr2->next) {
                    ptr2->next = ptr;
                    break;
                }
        }
        else {
            bus_park = ptr;
        }
    }
          break;
    case 3: {
        int y;
        cout << "Enter nymber bus: "; correct_cin_int(y);
        auto tmp = bus_park;
        for (; tmp; tmp = tmp->next) {
            if (tmp->nym_bus == y) {
                break;
            }
            else if (!tmp->next) {
                cout << "Nymber bus " << y << " not found...\n";                
            }
        }       
        AddBefore(bus_park, tmp, ptr);        
    }
        break;   
    }
}


void send_return(Node& bus_park, int x) {
    int y;
    cout << "Enter nymber bus: "; correct_cin_int(y);
    auto* time_ptr = &bus_park;
    for (; time_ptr; time_ptr = time_ptr->next) {
        if (time_ptr->nym_bus == y) {
            break;
        }
        else if (!time_ptr->next) {
            cout << "Nymber bus " << y << " not found...\n";
            return;
        }
    }
    if (x == 2 && time_ptr->condit || x == 3 && !time_ptr->condit) {
        if (x == 2) {
            cout << "Error!!! The bus is on the route.\n";
        }
        else {
            cout << "Error!!! The bus is in park.\n";
        }
        return;
    }
    else {
        if (x == 3) {
            time_ptr->condit = 0;
            cout << "The bus return in park.\n";
        }
        else {
            time_ptr->condit = 1;
            time_ptr->nym_rout = rand() % 100;
        }
    }
}

void show_bus_info(Node*& bus_card) {
    int c;
    cout << "For show bus in route input: 1\nTo show bus in park enter: 2\n";
    correct_cin_int(c);
    for (auto time_ptr(bus_card); time_ptr; time_ptr = time_ptr->next)
        if (c == 1 && time_ptr->condit)
            cout << "\nBus nymber " << time_ptr->nym_bus <<
            "\nDriver " << time_ptr->name_driv <<
            "\nRoute nymber " << time_ptr->nym_rout << endl;
        else if (c == 2 && !time_ptr->condit)
            cout << "\nBus nymber " << time_ptr->nym_bus <<
            "\nDriver " << time_ptr->name_driv << endl;
}

int main() {
    Node* bus_park(nullptr);
    int x(1);
    while (x) {
        cout << "-----------------------------------------------------------------------\n";
        cout << "To add a driver info input: 1\nTo send bus" <<
            " input: 2\nTo return bus input: 3\nTo show buses input: 4\nTo exit enter: 0\n";
        correct_cin_int(x);
        cout << "-----------------------------------------------------------------------\n";
        switch (x) {
        case 1:
            add_bus_info(bus_park);
            break;
        case 2: case 3:
            if (bus_park) send_return(*bus_park, x);
            else cout << "To start, add a record about buses!\n";
            break;
        case 4:
            if (bus_park) show_bus_info(bus_park);
            else cout << "To start, add a record about buses!\n";
            break;
        default:
            if (x)
                cout << "To enter nymber 1 of 2 or 3 or 4 or 0...\n";
        }
    }
    return 0;
}