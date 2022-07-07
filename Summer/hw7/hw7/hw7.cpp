//
//  main.cpp
//  hw7
//
//  Created by Ziqian Zhang on 2022/6/30.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int WORLDSIZE = 20;
const int INITIALANTS = 100;
const int INITIALBUGS = 5;
const int DOODLEBUG = 1;
const int ANT = 2;
const int ANT_BREED = 3;
const int DOODLE_BREED = 8;
const int DOODLESTARVE = 3;

class Organism;

class World{
    friend class Organism;
    friend class Doodlebug;
    friend class Ant;
public:
    World();
    ~World();
    Organism* getAt(int x, int y);
    void setAt(int x, int y, Organism *org);
    void Show();
    void SimulateOneStep();
private:
    Organism* grid[WORLDSIZE][WORLDSIZE];
};


class Organism{
    friend class World;
public:
    Organism();
    Organism(World *world, int x, int y);
    virtual ~Organism(){}
    virtual void breed() = 0;
    virtual void move() = 0;
    virtual int getType() = 0;
    virtual bool starve() = 0;
protected:
    int x, y;
    bool moved;
    int breedTicks;
    World* world;
};

World::World(){
    int i, j;
    for (i = 0; i < WORLDSIZE; i++){
        for (j = 0; j < WORLDSIZE; j++){
            grid[i][j] = NULL;
        }
    }
}

World::~World(){
    int i, j;
    for (i = 0; i < WORLDSIZE; i++){
        for (j = 0; j < WORLDSIZE; j++){
            if (grid[i][j] != NULL) delete (grid[i][j]);
        }
    }
}

Organism* World::getAt(int x, int y){
    if ((x >= 0) && (x < WORLDSIZE) && (y >= 0) && (y < WORLDSIZE))
        return grid[x][y];
    return NULL;
}

void World::setAt(int x, int y, Organism *org){
    if ((x >= 0) && (x < WORLDSIZE) && (y >= 0) && (y < WORLDSIZE)){
        grid[x][y] = org;
    }
}

void World::Show(){
    int i, j;
    cout << endl << endl;
    for (j = 0; j < WORLDSIZE; j++){
        for (i = 0; i < WORLDSIZE; i++){
            if (grid[i][j] == NULL)
                cout << ".";
            else if (grid[i][j]->getType() == ANT)
                cout << "o";
            else cout << "X";
        }
        cout << endl;
    }
}

void World::SimulateOneStep(){
    int i, j;
    for (i = 0; i < WORLDSIZE; i++)
        for (j = 0; j < WORLDSIZE; j++){
            if (grid[i][j] != NULL)
                grid[i][j]->moved = false;
        }
    for (i = 0; i < WORLDSIZE; i++)
        for (j = 0; j < WORLDSIZE; j++){
            if ((grid[i][j] != NULL) && (grid[i][j]->getType() == DOODLEBUG)){
                if (grid[i][j]->moved == false){
                    grid[i][j]->moved = true;
                    grid[i][j]->move();
                }
            }
        }

    for (i = 0; i < WORLDSIZE; i++)
        for (j = 0; j < WORLDSIZE; j++){
            if ((grid[i][j] != NULL) && (grid[i][j]->getType() == ANT)){
                if (grid[i][j]->moved == false){
                    grid[i][j]->moved = true;
                    grid[i][j]->move();
                }
            }
        }

    for (i = 0; i < WORLDSIZE; i++)
        for (j = 0; j < WORLDSIZE; j++){

            if ((grid[i][j] != NULL) && (grid[i][j]->getType() == DOODLEBUG)){
                if (grid[i][j]->starve()){
                    delete (grid[i][j]);
                    grid[i][j] = NULL;
                }

            }
        }


    for (i = 0; i < WORLDSIZE; i++)
        for (j = 0; j < WORLDSIZE; j++){
            if ((grid[i][j] != NULL) && (grid[i][j]->moved == true)){
                grid[i][j]->breed();
            }
        }
}


Organism::Organism(){
    world = NULL;
    moved = false;
    breedTicks = 0;
    x = 0;
    y = 0;
}

Organism::Organism(World *wrld, int x, int y){
    this->world = wrld;
    moved = false;
    breedTicks = 0;
    this->x = x;
    this->y = y;
    wrld->setAt(x, y, this);
}

class Ant : public Organism{
    friend class World;
public:
    Ant();
    Ant(World *world, int x, int y);
    void breed();
    void move();
    int getType();
    bool starve(){ return false;}
};

Ant::Ant() : Organism(){}

Ant::Ant(World *world, int x, int y) : Organism(world, x, y){}

void Ant::move(){
    int dir = rand() % 4;
    if (dir == 0){
        if ((y > 0) && (world->getAt(x, y - 1) == NULL)){
            world->setAt(x, y - 1, world->getAt(x, y));
            world->setAt(x, y, NULL);
            y--;
        }
    } else if (dir == 1){
        if ((y < WORLDSIZE - 1) && (world->getAt(x, y + 1) == NULL)){
            world->setAt(x, y + 1, world->getAt(x, y));
            world->setAt(x, y, NULL);
            y++;
        }
    } else if (dir == 2){
        if ((x > 0) && (world->getAt(x - 1, y) == NULL)){
            world->setAt(x - 1, y, world->getAt(x, y));
            world->setAt(x, y, NULL);
            x--;
        }
    } else {
        if ((x < WORLDSIZE - 1) && (world->getAt(x + 1, y) == NULL)){
            world->setAt(x + 1, y, world->getAt(x, y));
            world->setAt(x, y, NULL);
            x++;
        }
    }
}

int Ant::getType(){ return ANT; }

void Ant::breed(){
    breedTicks++;
    if (breedTicks == ANT_BREED){
        breedTicks = 0;
        if ((y > 0) && (world->getAt(x, y - 1) == NULL)){
            Ant* newAnt;
            newAnt = new Ant(world, x, y - 1);
        } else if ((y < WORLDSIZE - 1) && (world->getAt(x, y + 1) == NULL)){
            Ant* newAnt;
            newAnt  = new Ant(world, x, y + 1);
        } else if ((x > 0) && (world->getAt(x - 1, y)== NULL)){
            Ant* newAnt;
            newAnt  = new Ant(world, x - 1, y);
        } else if ((x < WORLDSIZE - 1) && (world->getAt(x + 1, y) == NULL)){
            Ant* newAnt;
            newAnt  = new Ant(world, x + 1, y);
        }
    }
}

class Doodlebug : public Organism{
    friend class World;
public:
    Doodlebug();
    Doodlebug(World *world, int x, int y);
    void breed();
    void move();
    int getType();
    bool starve();
private:
    int starveTicks;
};

Doodlebug::Doodlebug() : Organism(){ starveTicks = 0; }

Doodlebug::Doodlebug(World *world, int x, int y) : Organism(world, x, y){ starveTicks = 0;}

void Doodlebug::move(){
    if ((y > 0) && (world->getAt(x, y - 1) != NULL) && (world->getAt(x, y - 1)->getType() == ANT)){
        delete (world->grid[x][y - 1]);
        world->grid[x][y - 1] = this;
        world->setAt(x, y, NULL);
        starveTicks = 0;
        y--;
        return;
    } else if ((y < WORLDSIZE - 1) && (world->getAt(x, y + 1) != NULL) && (world->getAt(x, y + 1)->getType() == ANT)){
        delete (world->grid[x][y + 1]);
        world->grid[x][y + 1] = this;
        world->setAt(x, y, NULL);
        starveTicks = 0;
        y++;
        return;
    }   else if ((x > 0) && (world->getAt(x - 1, y) != NULL) && (world->getAt(x - 1, y)->getType() == ANT)){
        delete (world->grid[x - 1][y]);
        world->grid[x - 1][y] = this;
        world->setAt(x, y, NULL);
        starveTicks = 0;
        x--;
        return;
    } else if ((x < WORLDSIZE - 1) && (world->getAt(x + 1, y) != NULL) && (world->getAt(x + 1, y)->getType() == ANT)){
        delete (world->grid[x + 1][y]);
        world->grid[x + 1][y] = this;
        world->setAt(x, y, NULL);
        starveTicks = 0;
        x++;
        return;
    }
    int dir = rand() % 4;
    if (dir == 0){
        if ((y > 0) && (world->getAt(x, y - 1) == NULL)){
            world->setAt(x, y - 1, world->getAt(x, y));
            world->setAt(x, y, NULL);
            y--;
        }
    } else if (dir == 1){
        if ((y < WORLDSIZE - 1) && (world->getAt(x, y + 1)== NULL)){
            world->setAt(x, y + 1, world->getAt(x, y));
            world->setAt(x, y, NULL);
            y++;
        }
    } else if (dir == 2) {
        if ((x > 0) && (world->getAt(x - 1, y) == NULL)){
            world->setAt(x - 1, y, world->getAt(x, y));
            world->setAt(x, y, NULL);
            x--;
        }
    } else {
        if ((x < WORLDSIZE - 1) && (world->getAt(x + 1, y) == NULL)){
            world->setAt(x + 1, y, world->getAt(x, y));
            world->setAt(x, y, NULL);
            x++;
        }
    }
    starveTicks++;
}

int Doodlebug::getType(){ return DOODLEBUG; }

void Doodlebug::breed(){
    breedTicks++;
    if (breedTicks == DOODLE_BREED){
        breedTicks = 0;
        if ((y > 0) && (world->getAt(x, y - 1) == NULL)){
            Doodlebug* newDoodle;
            newDoodle = new Doodlebug(world, x, y - 1);
        } else if ((y < WORLDSIZE - 1) && (world->getAt(x, y + 1) == NULL)){
            Doodlebug* newDoodle;
            newDoodle  = new Doodlebug(world, x, y + 1);
        } else if ((x > 0) && (world->getAt(x - 1, y) == NULL)){
            Doodlebug* newDoodle;
            newDoodle  = new Doodlebug(world, x - 1, y);
        } else if ((x < WORLDSIZE - 1) && (world->getAt(x + 1, y) == NULL)){
            Doodlebug* newDoodle;
            newDoodle  = new Doodlebug(world, x + 1, y);
        }
    }
}

bool Doodlebug::starve(){
    if (starveTicks > DOODLESTARVE){
        return true;
    } else {
        return false;
    }
}

int main(){
    string str;
    srand(time(0));
    World w;
    int antcountValue = 0;
    while (antcountValue < INITIALANTS){
        int x = rand() % WORLDSIZE;
        int y = rand() % WORLDSIZE;
        if (w.getAt(x, y) == NULL){
            antcountValue++;
            Ant* a1;
            a1 = new Ant(&w, x, y);
        }
    }
    int doodlecountValue = 0;
    while (doodlecountValue < INITIALBUGS){
        int x = rand() % WORLDSIZE;
        int y = rand() % WORLDSIZE;
        if (w.getAt(x, y) == NULL){
            doodlecountValue++;
            Doodlebug* d1;
            d1 = new Doodlebug(&w, x, y);
        }
    }
    while (true){
        w.Show();
        w.SimulateOneStep();
        cout << endl << "Press enter for next step" << endl;
        getline(cin, str);
    }
}
