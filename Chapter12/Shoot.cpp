#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

class Target; // Forward declaration for Target

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
    std::string texture;
    Subject* subject;

public:
    Target(std::string texture, Subject* subject) : texture(texture), subject(subject) {}

    void draw(int x, int y) {
        std::cout << "Drawing target at (" << x << ", " << y << ") with texture: " << texture << std::endl;
    }

    void hit() {
        subject->notifyObservers(this);
    }
};

class Weapon; // Forward declaration for Weapon

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
    static std::unordered_map<std::string, Target*> targets;

public:
    static Target* getTarget(std::string texture, Subject* subject) {
        if (targets.count(texture) == 0) {
            targets[texture] = new Target(texture, subject);
        }
        return targets[texture];
    }
};

std::unordered_map<std::string, Target*> TargetFactory::targets = {};

class GameManager : public Observer {
private:
    static GameManager* instance;
    GameManager() : score(0), gameSubject(nullptr) {} // Initialize score and gameSubject
    int score;
    Subject* gameSubject; // Store a reference to the Subject

public:
    static GameManager* getInstance() {
        if (instance == nullptr) {
            instance = new GameManager();
        }
        return instance;
    }

    void setGameSubject(Subject* subject) {
        gameSubject = subject;
    }

    void onTargetHit(Target* target) {
        score += 10;
        std::cout << "Target hit! Score: " << score << std::endl;
    }

    void startGame() {
        std::cout << "Starting the game...\n";
        gameSubject = new Subject(); // Create the Subject
        setGameSubject(gameSubject);
        Target* target = TargetFactory::getTarget("red", gameSubject);
        target->draw(10, 10);
        Weapon* weapon = WeaponFactory::createWeapon("Sword");
        weapon->use(target);
        delete weapon;
        delete gameSubject; // Clean up the Subject
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

GameManager* GameManager::instance = nullptr;

int main() {
    GameManager* gameManager = GameManager::getInstance();
    gameManager->startGame();
    gameManager->pauseGame();
    gameManager->resumeGame();
    gameManager->endGame();

    return 0;
}
