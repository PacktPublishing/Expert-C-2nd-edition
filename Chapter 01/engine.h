#ifndef ENGINE_H
#define ENGINE_H

class Engine {
public:
    Engine() = default;
    Engine(int horsepower);
    int getHorsepower() const;

private:
    int horsepower_;
};

#endif // ENGINE_H
