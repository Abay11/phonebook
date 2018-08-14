#include <iostream>
#include <stdio.h>
#include <map>

#include <unistd.h>

#define cout(a) std::cout<<a<<std::endl
#define wcout(a,b) std::cout<<a<<" "<<b<<std::endl
#define coutenter() std::cout<<"Input Enter to return..."<<std::endl

void init(std::multimap<std::string, std::string>&map)
{
   map.insert(std::pair<std::string, std::string>("Ivan Ivanov", "35 555"));
   map.insert(std::pair<std::string, std::string>("Petr Petrov", "65 555"));
   map.insert(std::pair<std::string, std::string>("Semen Semenov", "85 555"));
   map.insert(std::pair<std::string, std::string>("Ivan Ivanov", "95 555"));
}

void add(std::multimap<std::string, std::string>&map)
{
   system("clear");

   std::string name, phone;

   std::cout<<"Enter name: ";
   std::cin.ignore();
   getline(std::cin, name);

   std::cout<<"Enter phone: ";
   getline(std::cin, phone);

   map.insert(std::make_pair(name, phone));
   cout("Information saved");
   coutenter();
   getchar();
}

void del(std::multimap<std::string, std::string>&map)
{
    system("clear");
    std::string name;
    cout("Enter name: ");
    std::cin.ignore();
    getline(std::cin, name);
    auto pos=map.find(name);

    if(pos!=map.end())
    {
        auto range=map.equal_range(name);
        if(std::distance(range.first, range.second)>1)
        {
           cout("There are two or more items with this name. Please enter a number: ");
           std::string phone;
           getline(std::cin, phone);
           for(auto it=range.first; it!=range.second; ++it)
           {
               if(it->second==phone)
               {
                   pos=it;
                   break;
               }
               else if(it==std::prev(range.second))
                  goto not_found;
           }
        }
        map.erase(pos);
        cout("Operation status: OK");
    }
    else
    {
        not_found:
        cout("Operation status: Not found");
    }
    coutenter();
    getchar();
}

void print(std::multimap<std::string, std::string>&map)
{
    system("clear");
    std::cout<<"Name\t\t\tPhone\n";
    for(auto iter:map)
    {
        std::cout<<iter.first<<"\t\t"<<iter.second<<std::endl;
    }
    coutenter();
    std::cin.ignore();
    std::cin.ignore();
}

void search(std::multimap<std::string, std::string>&map)
{
    system("clear");
    std::string name;
    cout("Enter name: ");
    std::cin.ignore();
    getline(std::cin, name);
    auto range=map.equal_range(name);

    cout("\nAll results---");
    std::cout<<"Name\t\t\tPhone\n";

    for(auto it=range.first; it!=range.second; ++it)
    {
        std::cout<<it->first<<"\t\t"<<it->second<<std::endl;
    }
    coutenter();
    getchar();
}

int main()
{
    char input;
    bool b=true;
    std::multimap<std::string, std::string> map;

    init(map);

    while(b)
    {
    cout("YOUR PERSONAL PHONEBOOK v1.0\n");
    cout("1. Add person");
    cout("2. Delete person");
    cout("3. Print all persons");
    cout("4. Search person(s)");
    cout("\n0. Exit");
    cout("Enter command: ");

    input=static_cast<char>(getchar());

    switch(input)
    {
    case'1': add(map);break;
    case'2': del(map); break;
    case'3': print(map);break;
    case'4': search(map); break;
    case'0': b=false; break;
    default: break;
    }
    system("clear");
    }

    return 0;
}
