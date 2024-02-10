#include <iostream>
#include <demolib.h>

using FuncPointer = void(*)();

enum CreatureType{
    HUMAN =0,
    ANIMAL
};

class Creature{
public:
    virtual ~Creature() = default;
    virtual CreatureType getType ()  = 0;
    virtual void printName() const = 0;
    virtual std::string getName() const = 0;
};

class Human : public Creature{
public:

    Human() : name("humanio"){}

    CreatureType getType () override {return HUMAN;}
    void printName () const override{
        std::cout <<"we are dealign with human:" << std::endl;;
    }
    std::string getName() const override {return name;}
private:
    std::string name;
};

class Animal : public Creature{
public:
    Animal() : name("animalio"){}
    CreatureType getType () override {return ANIMAL;}
    void printName () const override {
        std::cout <<"we are dealign with animal:" <<  std::endl;;
    }
     std::string getName() const override{return name;}
private:
    std::string name;
};

void addAnimalCount(){
    std::cout << "adding animal count" << std::endl;
}

void addHumanCount(){
    std::cout << "adding human count" << std::endl;
}

class CreatureFactory{
public:

    static std::unique_ptr<Creature> create(CreatureType type){

        switch (type)
        {
        case HUMAN: return std::make_unique<Human>();
        case ANIMAL: return std::make_unique<Animal>();
        default: return nullptr;
        }
    }
};

using funcptr = std::string(*)(const std::unique_ptr<Creature>& creature);

std::string printNom(const std::unique_ptr<Creature>& creature){
    return creature->getName();
};

void execute(FuncPointer func) {
    func(); // Correctly invoke the function pointer
}

std::string processCreature(funcptr fptr, const std::unique_ptr<Creature>& creature)
{
    return fptr(creature);
}

int main(){

    Core::DemoLib<Creature> lib;
    // Create a list of creatures
    std::vector<std::unique_ptr<Creature>> creatures;

    creatures.push_back(CreatureFactory::create(HUMAN));
    creatures.push_back(CreatureFactory::create(ANIMAL));
    creatures.push_back(CreatureFactory::create(HUMAN));

    for (const auto& creature: creatures)
    {
        creature->printName();
        if (creature->getType() == HUMAN)
        {
            execute(addHumanCount);
            processCreature(printNom, creature);
            // addHumanCount();
        } else{
            continue;
        }
    }
    for (auto& creature: creatures)
    {
        lib.addToStorage(std::move(creature));
    }

    return 0;
};





