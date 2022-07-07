/*
  rec10_start.cpp
  Starting code 22S
 */

#include <iostream>
#include <vector>
using namespace std;

// 
// Musician class is provided to the students. Requires the Instrument class.
// 
/*
class Musician {
public:
    Musician() : instr(nullptr) {}

    // acceptInstr takes in an instrument for the Musician to later play.
    //  "loses" any instrument that it used to have.
    void acceptInstr(Instrument* instPtr) { instr = instPtr; }

    // giveBackInstr: gives the instrument that the Musicial was holding "back"
    Instrument* giveBackInstr() { 
        Instrument* result(instr); 
        instr = nullptr;
        return result;
    }

    // testPlay: testing out my instrument
    void testPlay() const {
        if (instr) instr->makeSound(); 
        else cerr << "have no instr\n";
    }

private:
    Instrument* instr;
};
*/

int main() {

    //
    // PART ONE
    //
    cout << "P A R T  O N E\n";

    cout << "Define some instruments --------------------------------------\n";
    // Drum drum;
    // Cello cello(673);
    // Cymbal cymbal;
    // Trombone tbone(4);
    // Trumpet trpt(12) ;
    // Violin violin(567) ;
  
    // use the debugger to look at the mill
    cout << "Define the MILL ----------------------------------------------\n";
    // MILL mill;
  
    cout << "Put the instruments into the MILL ----------------------------\n";
    // mill.receiveInstr(trpt);
    // mill.receiveInstr(violin);
    // mill.receiveInstr(tbone);
    // mill.receiveInstr(drum);
    // mill.receiveInstr(cello);
    // mill.receiveInstr(cymbal);
  
    cout << "Daily test ---------------------------------------------------\n"
	 << "dailyTestPlay()" << endl;
    // mill.dailyTestPlay();
    // cout << endl;
  
    cout << "Define some Musicians-----------------------------------------\n";
    // Musician harpo;
    // Musician groucho;
  	
    cout << "TESTING: groucho.acceptInstr(mill.loanOut());-----------------\n";
    // groucho.testPlay();	
    // cout << endl;
    // groucho.acceptInstr(mill.loanOut());
    // cout << endl;
    // groucho.testPlay();
    // cout << endl;
    // cout << "dailyTestPlay()" << endl;
    // mill.dailyTestPlay();
  
    // cout << endl << endl;
  
    // groucho.testPlay();	
    // cout << endl;
    // mill.receiveInstr(*groucho.giveBackInstr());
    // harpo.acceptInstr(mill.loanOut());
    // groucho.acceptInstr(mill.loanOut());
    // cout << endl;
    // groucho.testPlay();
    // cout << endl;
    // harpo.testPlay();
    // cout << endl;
    // cout << "dailyTestPlay()" << endl;
    // mill.dailyTestPlay();
  
    cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); --------\n";
  
    // // fifth
    // mill.receiveInstr(*groucho.giveBackInstr());
    cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ----------\n";
    // mill.receiveInstr(*harpo.giveBackInstr());

  
    // cout << endl;
    cout << "dailyTestPlay()" << endl;
    // mill.dailyTestPlay();
    // cout << endl;
 

    //
    // PART TWO
    //
    cout << "P A R T  T W O\n";
    
/*
    Musician bob;
    Musician sue;
    Musician mary;
    Musician ralph;
    Musician jody;
    Musician morgan;

    Orch orch;

    // THE SCENARIO

    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);

    //The orchestra performs
    cout << "orch performs\n";
    orch.play();

    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr(mill.loanOut());
    orch.addPlayer(sue);

    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr(mill.loanOut());

    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr(mill.loanOut());
    orch.addPlayer(mary);

    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr(*ralph.giveBackInstr());

    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr(mill.loanOut());
    orch.addPlayer(jody);

    // morgan gets an instrument from the MIL2
    morgan.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Ralph joins the orchestra.
    orch.addPlayer(ralph);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
	
    // bob gets an instrument from the MIL2
    bob.acceptInstr(mill.loanOut());

    // ralph gets an instrument from the MIL2
    ralph.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Morgan joins the orchestra.
    orch.addPlayer(morgan);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

*/
}
