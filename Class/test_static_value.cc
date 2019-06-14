#include <iostream>
#include <include/game_player.h>
const int GamePlayer::Number;
int main() {
  GamePlayer gp;
  const int* gp_ptr = &GamePlayer::Number;
  std::cout << GamePlayer::Number << std::endl;
}