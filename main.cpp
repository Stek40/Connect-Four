#include <iostream>
#include "Game.h"

int main()
{
    Game game1 = Game();
    Game game2 = Game(10, 15);
    
    game2.play();

    return 0;
}
