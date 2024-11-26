#include "Human.h"
#include <iostream>

Human::Human(std::shared_ptr<Player>p) {
    this->player = p;
}
int Human::overbid()
{
    int number = 9;
        while (number < 0 or number > 4) {
            std::cout << "Quel est votre choix ?";
            std::cin >> number;

    }
        return number;

}
