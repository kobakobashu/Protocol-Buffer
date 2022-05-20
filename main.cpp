#include <iostream>
#include "address_book.pb.h"
 
int main(int argc, char **v)
{
    PERSON::Person person01, person02, person03, person04;

    const std::string name1 = "person01";
    int ID1 = 01;
    const std::string email1 = "person01@xyz.com";

    const std::string name2 = "person02";
    int ID2 = 01;
    const std::string email2 = "person02@xyz.com";

    person01.set_name(name1);
    person01.set_id(ID1);
    person01.set_email(email1);

    person01.set_name(name2);
    person01.set_id(ID2);
    person01.set_email(email2);

    PERSON::AddressBook address_book;
    address_book.add_people()->CopyFrom(person01);
    address_book.add_people()->CopyFrom(person02);

    address_book.add_people()->set_id(100000);

    std::cout << "--------------------"<<std::endl;

    std::cout << "Person01 Name : " << address_book.people(0).name() << std::endl;
    std::cout << "Person02 Name : " << address_book.people(1).name() << std::endl;

    std::cout << "--------------------"<<std::endl;

    std::cout << "Address Book Size : " << address_book.people_size() << std::endl;
    std::cout << "\n-----------Address Book---------"<<std::endl;

    for (int i = 0; i < address_book.people_size(); i++) {
        std::cout << address_book.mutable_people(i)->DebugString()<<std::endl;
        std::cout << "-------------------------"<<std::endl;
    }

    return EXIT_SUCCESS;
}