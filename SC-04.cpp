// SC-04.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include <chrono>
#include "Graph.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    string usr1 = "Олег";
    string usr2 = "Никита";
    string usr3 = "Настя";
    string usr4 = "Ваня";
    string usr5 = "Женя";
    string usr6 = "Лена";

    Graph users;

    users.addUser(usr1);
    users.addUser(usr2);
    users.addUser(usr3);
    users.addUser(usr4);
    users.addUser(usr5);
    users.addUser(usr6);

    users.addEdge(usr1, usr2, 1);
    users.addEdge(usr2, usr3, 1);
    users.addEdge(usr3, usr4, 1);
    users.addEdge(usr4, usr5, 1);
    users.addEdge(usr5, usr6, 1);

    
    users.showFriends(3);
        return 0;
}

