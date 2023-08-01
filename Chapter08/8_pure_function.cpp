#include <string>
#include <iostream>

struct User
{
    int age;
    std::string name;
    std::string phone_number;
    std::string email;
};

void update_age(User& u)
{
    u.age = u.age + 1;
}

User pure_update_age(const User& u) // cannot modify the input argument
{
    User tmp{ u };
    tmp.age = tmp.age + 1;
    return tmp;
}

int main()
{
    User john{.age = 21,.name = "John" };

    update_age(john); // Modify 'john' directly
    std::cout << john.age << std::endl; // prints 22

    User updated = pure_update_age(john); // Create a copy and modify it
    std::cout << updated.age << std::endl; // prints 23

    std::cout << john.age << std::endl; // prints 22, the original object 'john' remains unchanged

    return 0;
}
