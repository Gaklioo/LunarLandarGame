#include <iostream>
#include <time.h>
#include <string>

int main() {
	int distance = 10;
	int surface = 0;
	int x, y;
	bool doGame = true;
	srand(time(NULL));
	x = (rand() % 20) - 10;
	y = (rand() % 20) - 10;
	//Generate x and y random values -10, 10
	int res{}; // tilt tilt thruster nothing destruction sequence;
	int selfDestructInput{};
	int selfDestruct{(rand() % 9999)};
	system("CLS");
	std::cout << "-----             Welcome to the lunar lander simulator           -----" << std::endl;
	std::cout << "----- Get to the surface. If you have any tilt, you will explode. -----" << std::endl;
	while (doGame) {
		std::string Command = { "1: Tilt X Axis. 2: Tilt Y Axis. 3: Apply Thruster[+2 Distance From Surface]. 4: Do nothing. 5: Start Destruction sequence" };
		std::string lunarString = { "Lunar Moduel X is at distance " + std::to_string(distance) + " and surface is at " + std::to_string(surface) + " X Tilt: " + std::to_string(x) + " Y Tilt: " + std::to_string(y) + " Please Choose Command"};
		std::cout << lunarString << std::endl;
		std::cout << Command << std::endl;
		std::cout << "Please choose what you would like to do: ";
		std::cin >> res;
		switch (res)
		{
		case 1:
			distance -= 1;
			if (x > 0) { --x; }
			else { ++x; }
			system("CLS");
			if (distance == 0) break;
			break;
		case 2:
			distance -= 1;
			if (y > 0) { --y; }
			else { ++y; }
			system("CLS");
			if (distance == 0) break;
			break;
		case 3:
			distance += 2;
			system("CLS");
			if (distance == 0) break;
			break;
		case 4:
			distance -= 1;
			system("CLS");
			if (distance == 0) break;
			break;
		case 5:
			//Self Destruct
			system("CLS");
			std::cout << "Please Enter Self Destruct Sequence code: ";
			std::cin >> selfDestructInput;
			if (selfDestructInput != selfDestruct) {
				std::cout << "Incorrect Code Awnserd" << std::endl;
				std::cout << "Please enter 1 to try again or 2 to abort self destruct." << std::endl;
				std::cin >> selfDestruct;
				while (selfDestructInput != 2)
				{
					std::cin >> selfDestructInput;
					if (selfDestructInput != 1) {
						std::cout << "Please Enter Self Destruct Sequence code: ";
					}
				}
			}
			break;
		default:
			std::cout << "Incorrect Response. Try Again." << std::endl;
			while (res >= 6) {
				std::cout << Command << std::endl;
				std::cin >> res;
			}
			break;
		}
		if (x == 0 && y == 0 && distance == 0) {
			std::cout << "Congrats you have succesfully landed the lunar module!" << std::endl;
			std::cout << "Play Again? [Y/N]" << std::endl;
			char response;
			std::cin >> response;
			if (response == 'N') {
				doGame = false;
			}
			else {
				x = (rand() % 20) - 10;
				y = (rand() % 20) - 10;
				distance = 10;
				doGame = false;
				doGame = true;
			}
		}
		else if ((x != 0 || y != 0) && distance == 0) {
			std::cout << "You have blown up the lunar module." << std::endl;
			std::cout << "Play Again? [Y/N]" << std::endl;
			char response;
			std::cin >> response;
			if (response == 'N') {
				doGame = false;
			}
			else {
				x = (rand() % 20) - 10;
				y = (rand() % 20) - 10;
				distance = 10;
				doGame = false;
				doGame = true;
			}

		}
	}
}