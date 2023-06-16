#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Target; // forward declaration

class Observer {
public:
    virtual void onTargetHit(Target* target) = 0;
};

class Subject {
private:
    std::vector<Observer*> observers;

public:
    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers(Target* target) {
        for (auto observer : observers) {
            observer->onTargetHit(target);
        }
    }
};

class Target {
private:
    std::string texture; // intrinsic state
    Subject* subject;

public:
    Target(std::string texture, Subject* subject) : texture(texture), subject(subject) {}

    void draw(int x, int y) {
        std::cout << "Drawing target at (" << x << ", " << y << ") with texture: " << texture << std::endl;
    }

    void hit() {
        subject->notifyObservers(this); // notify observers of target hit
    }
};

class GameManager : public Observer {
private:
    static GameManager* instance; // singleton instance
    GameManager() {} // private constructor to prevent direct instantiation
    int score;

public:
    static GameManager* getInstance() {
        if (instance == nullptr) {
            instance = new GameManager(); // create singleton instance if it doesn't exist
        }
        return instance;
    }

    void onTargetHit(Target* target) {
        score += 10; // add points for hitting a target
        std::cout << "Target hit! Score: " << score << std::endl;
    }

    void startGame() {
        std::cout << "Starting the game...\n";
        Weapon* weapon = WeaponFactory::createWeapon("Sword");
        Target* target = TargetFactory::getTarget("red", this);
        target->draw(10, 10);
        weapon->use(target);
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

class Weapon {
private:
    std::string name;

public:
    Weapon(std::string name) : name(name) {}

    void use(Target* target) {
        std::cout << "Using " << name << "!\n";
        target->hit();
    }
};

class WeaponFactory {
public:
    static Weapon* createWeapon(std::string name) {
        return new Weapon(name);
    }
};

class TargetFactory {
private:
    static std::unordered_map<std::string, Target*> targets; // flyweight pool

public:
    static Target* getTarget(std::string texture, Subject* subject) {
        if (targets.count(texture) == 0) { // check if target exists in pool
            targets[texture] = new Target(texture, subject); // create new target if it doesn't exist
        }
        return targets[texture]; // return existing or newly created target
    }
};

std::unordered_map<std::string, Target*> TargetFactory::targets = {}; // initialize flyweight pool

int main() {
    GameManager* gameManager = GameManager::getInstance(); // get singleton instance
    gameManager->startGame(); // start the game
    gameManager->pauseGame(); // pause the game
    gameManager->resumeGame(); // resume the game
    gameManager->endGame(); // end the game

    return 0;
}

