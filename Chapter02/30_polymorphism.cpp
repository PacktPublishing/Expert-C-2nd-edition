#include<iostream>
#include<vector>

class Musician {
public:
    virtual void play() = 0;
};

class Guitarist : public Musician {
public:
    void play() override { std::cout << "Play a guitar" << std::endl; }
};

class Pianist : public Musician {
public:
    void play() override { std::cout << "Play a piano" << std::endl; }
};

std::vector<Musician*> get_musicians() {
    std::vector<Musician*> musicians;
    musicians.push_back(new Guitarist());
    musicians.push_back(new Pianist());
    return musicians;
}

int main() {
    auto all_musicians = get_musicians();
    for (const auto& m : all_musicians) {
        m->play();
    }

    // Clean up the dynamically allocated objects
    for (const auto& m : all_musicians) {
        delete m;
    }

    return 0;
}
