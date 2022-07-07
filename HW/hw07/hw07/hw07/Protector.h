//
//  Protector.hpp
//  hw07
//
//  Created by Ziqian Zhang on 2022/4/13.
//

#ifndef Protector_hpp
#define Protector_hpp

#include <stdio.h>

#include <fstream>
#include <iostream>
#include <string>

namespace WarriorCraft {

    class Lord;

    // Simulate the behavior of Protector
    class Protector {
    public:
        // constructor
        Protector(const std::string& theName, int theStrength);

        // getters and setters
        const std::string& getName() const;
        int getStrength() const;
        void setStrength(int theStrength);
        void setLord(Lord* nobleptr);
        Lord* getLord() const;

        // let the Protector runaway
        bool runaway();

        // pure virtual defend method
        virtual void defend() const = 0;

    private:
        // private variables of Protector class
        std::string name;
        int strength;
        Lord* lord;
    };  // class Protector

    class Warrior : public Protector {
    public:
        using Protector::Protector;
        void defend() const override;
    };  // class Warrior

    class Wizard : public Protector {
    public:
        using Protector::Protector;
        void defend() const override;
    };  // class Wizard

    class Archer : public Warrior {
    public:
        using Warrior::Warrior;
        void defend() const override;
    };  // class Archer

    class Swordsman : public Warrior {
    public:
        using Warrior::Warrior;
        void defend() const override;
    };  // class Swordsmen

}  // namespace WarriorCraft

#endif /* Protector_hpp */
