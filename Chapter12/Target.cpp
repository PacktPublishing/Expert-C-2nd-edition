#include <iostream>
#include <string>
#include <unordered_map>

class Target {
private:
    std::string texture; // intrinsic state

public:
    Target(std::string texture) : texture(texture) {}

    void draw(int x, int y) {
        std::cout << "Drawing target at (" << x << ", " << y << ") with texture: " << texture << std::endl;
    }
};

class TargetFactory {
private:
    static std::unordered_map<std::string, Target*> targets; // flyweight pool

public:
    static Target* getTarget(std::string texture) {
        if (targets.count(texture) == 0) { // check if target exists in pool
            targets[texture] = new Target(texture); // create new target if it doesn't exist
        }
        return targets[texture]; // return existing or newly created target
    }
};

std::unordered_map<std::string, Target*> TargetFactory::targets = {}; // initialize flyweight pool

class Weapon {
private:
    std::string name;

public:
    Weapon(std::string name) : name(name) {}

    void use() {
        Target* target = TargetFactory::getTarget("red");
        target->draw(10, 10);
        std::cout << "Using " << name << "!\n";
    }
};

class WeaponFactory {
public:
    static Weapon* createWeapon(std::string name) {
        return new Weapon(name);
    }
};

class GameManager {
private:
    static GameManager* instance; // singleton instance
    GameManager() {} // private constructor to prevent direct instantiation

public:
    static GameManager* getInstance() {
        if (instance == nullptr) {
            instance = new GameManager(); // create singleton instance if it doesn't exist
        }
        return instance;
    }

    void startGame() {
        std::cout << "Starting the game...\n";
        Weapon* weapon = WeaponFactory::createWeapon("Sword");
        weapon->use();
        delete weapon;
    }

    void pauseGame() {
        std::cout << "Pausing the game...\n";
    }

    void resumeGame() {
        std::cout << "Resuming the game...\n";
    }

    void endGame() {
        std::cout << "Ending the game...\n";
    }
};

GameManager* GameManager::instance = nullptr; // initialize singleton instance to null

int main() {
    GameManager* gameManager = GameManager::getInstance(); // get singleton instance
    gameManager->startGame(); // start the game
    gameManager->pauseGame(); // pause the game
    gameManager->resumeGame(); // resume the game
    gameManager->endGame(); // end the game

    return 0;
}
