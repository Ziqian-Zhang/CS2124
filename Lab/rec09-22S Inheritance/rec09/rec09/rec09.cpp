//
//  main.cpp
//  rec09
//
//  Created by Ziqian Zhang on 2022/4/1.
//

// task 4: tester code failed to compile, inherited constructors need parameter, subclass cannot be initialized
#include <iostream>
using namespace std;

//class PrintedMaterial {
//public:
//    PrintedMaterial(unsigned numPages)
//    : numOfPages(numPages)
//    {}
//private:
//    unsigned numOfPages;
//};
//
//class Magazine : public PrintedMaterial {
//public:
//private:
//};
//
//class Book : public PrintedMaterial {
//public:
//private:
//};
//
//class TextBook : public Book {
//public:
//private:
//};
//
//class Novel : public Book {
//public:
//private:
//};
//
//// tester/modeler code
//int main() {
//    TextBook text;
//    Novel novel;
//    Magazine mag;
//}

// task 5

//    class PrintedMaterial {
//    public:
//        PrintedMaterial(unsigned numPages)
//        : numOfPages(numPages)
//        {}
//    private:
//        unsigned numOfPages;
//    };
//
//    class Magazine : public PrintedMaterial {
//    public:
//        Magazine(unsigned numPages)
//        : PrintedMaterial(numPages)
//        {}
//    private:
//    };
//
//    class Book : public PrintedMaterial {
//    public:
//        Book(unsigned numPages)
//        : PrintedMaterial(numPages)
//        {}
//    private:
//    };
//
//    class TextBook : public Book {
//    public:
//        TextBook(unsigned numPages)
//        : Book(numPages)
//        {}
//    private:
//    };
//
//    class Novel : public Book {
//    public:
//        Novel(unsigned numPages)
//        : Book(numPages)
//        {}
//    private:
//    };
//
//    // tester/modeler code
//    int main() {
//        TextBook t(5430);
//        Novel n(213);
//        Magazine m(6);
//    }

// task 6: void displayNumPages() const { cout << numberOfPages; } should be in the base class

//    class PrintedMaterial {
//    public:
//        void displayNumPages() const { cout << numOfPages; }
//    private:
//        unsigned numOfPages;
//    };
//
//    class Magazine : public PrintedMaterial {
//    public:
//    private:
//    };
//
//    class Book : public PrintedMaterial {
//    public:
//    private:
//    };
//
//    class TextBook : public Book {
//    public:
//    private:
//    };
//
//    class Novel : public Book {
//    public:
//    private:
//    };
//
//    // tester/modeler code
//    int main() {
//        TextBook text;
//        Novel novel;
//        Magazine mag;
//
//        text.displayNumPages();
//        novel.displayNumPages();
//        mag.displayNumPages();
//        cout << "===========\n";
//    }

// task 7

//    #include <iostream>
//    using namespace std;
//
//    class PrintedMaterial {
//    public:
//        PrintedMaterial(unsigned numPages)
//        : numOfPages(numPages)
//        {}
//        void displayNumPages() const { cout << numOfPages; }
//    private:
//        unsigned numOfPages;
//    };
//
//    class Magazine : public PrintedMaterial {
//    public:
//        Magazine(unsigned numPages)
//        : PrintedMaterial(numPages)
//        {}
//    private:
//    };
//
//    class Book : public PrintedMaterial {
//    public:
//        Book(unsigned numPages)
//        : PrintedMaterial(numPages)
//        {}
//    private:
//    };
//
//    class TextBook : public Book {
//    public:
//        TextBook(unsigned numPages, unsigned numIndxPgs )
//        : Book(numPages),
//          numOfIndexPages(numIndxPgs)
//        {}
//        void displayNumPages() const {
//        cout << numOfIndexPages << endl;
//        cout << numOfPages;     // 'numOfPages' is a private member of 'PrintedMaterial'
//        }
//    private:
//        unsigned numOfIndexPages;
//    };
//
//    class Novel : public Book {
//    public:
//        Novel(unsigned numPages)
//        : Book(numPages)
//        {}
//    private:
//    };
//
//    // tester/modeler code
//    int main() {
//        TextBook text(5430, 23);
//        Novel novel(213);
//        Magazine mag(6);
//
//        text.displayNumPages();
//        novel.displayNumPages();
//        mag.displayNumPages();
//        cout << "===========\n";
//    }

// task 8

//    class PrintedMaterial {
//    public:
//        PrintedMaterial(unsigned numPages)
//        : numOfPages(numPages)
//        {}
//        void displayNumPages() const { cout << numOfPages << endl; }
//    private:
//        unsigned numOfPages;
//    };
//
//    class Magazine : public PrintedMaterial {
//    public:
//        Magazine(unsigned numPages)
//        : PrintedMaterial(numPages)
//        {}
//    private:
//    };
//
//    class Book : public PrintedMaterial {
//    public:
//        Book(unsigned numPages)
//        : PrintedMaterial(numPages)
//        {}
//    private:
//    };
//
//    class TextBook : public Book {
//    public:
//        TextBook(unsigned numPages, unsigned numIndxPgs )
//        : Book(numPages),
//          numOfIndexPages(numIndxPgs)
//        {}
//        void displayNumPages() const {
//        cout << "Pages: ";
//        PrintedMaterial::displayNumPages();
//        cout << "Index pages: ";
//        cout << numOfIndexPages << endl;
//        }
//    private:
//        unsigned numOfIndexPages;
//    };
//
//    class Novel : public Book {
//    public:
//        Novel(unsigned numPages)
//        : Book(numPages)
//        {}
//    private:
//    };
//
//    // tester/modeler code
//    int main() {
//        TextBook text(5430, 23);
//        Novel novel(213);
//        Magazine mag(6);
//
//        text.displayNumPages();
//        novel.displayNumPages();
//        mag.displayNumPages();
//        cout << "===========\n";
//    }

// task 9
// PrintedMaterial pm = text; kind of like copying
// text into a vector of PrintedMaterials
// pm.displayNumPages();
// the index data member of the text object (Textbook) is being sliced off
// when it's being copied into its base type object, since pm doesn't have
// a data member for index (specific to general), so what gets called is the pm display method

//    class PrintedMaterial {
//    public:
//        PrintedMaterial(unsigned numPages)
//        : numOfPages(numPages)
//        {}
//        void displayNumPages() const { cout << numOfPages << endl; }
//    private:
//        unsigned numOfPages;
//    };
//
//    class Magazine : public PrintedMaterial {
//    public:
//        Magazine(unsigned numPages)
//        : PrintedMaterial(numPages)
//        {}
//    private:
//    };
//
//    class Book : public PrintedMaterial {
//    public:
//        Book(unsigned numPages)
//        : PrintedMaterial(numPages)
//        {}
//    private:
//    };
//
//    class TextBook : public Book {
//    public:
//        TextBook(unsigned numPages, unsigned numIndxPgs )
//        : Book(numPages),
//          numOfIndexPages(numIndxPgs)
//        {}
//        void displayNumPages() const {
//        cout << "Pages: ";
//        PrintedMaterial::displayNumPages();
//        cout << "Index pages: ";
//        cout << numOfIndexPages << endl;
//        }
//    private:
//        unsigned numOfIndexPages;
//    };
//
//    class Novel : public Book {
//    public:
//        Novel(unsigned numPages)
//        : Book(numPages)
//        {}
//    private:
//    };
//
//    // tester/modeler code
//    int main() {
//        TextBook text(5430, 23);
//        Novel novel(213);
//        Magazine mag(6);
//
//        text.displayNumPages();
//        novel.displayNumPages();
//        mag.displayNumPages();
//        cout << "===========\n";
//
//        cout << "\nA PrintedMaterial material object!\n";
//        PrintedMaterial pm(2345);
//        pm.displayNumPages();
//
//        cout << "\nA PrintedMaterial variable containing a TextBook value\n";
//        pm = text; // like putting a Textbook into a PrintedMaterial
//        pm.displayNumPages();
//
//    }

// task 10
// instead of putting an actual PrintedMaterial object into the vector, we put the address of a PrintedMaterial object (text) into a vector of pointers-to-PrintedMaterial (that is, pointers to the Base class)
// we'll be "managing" our objects by using pointers to PrintedMaterial values.

//    class PrintedMaterial {
//    public:
//        PrintedMaterial(unsigned numPages)
//        : numOfPages(numPages)
//        {}
//        void displayNumPages() const { cout << numOfPages << endl; }
//    private:
//        unsigned numOfPages;
//    };
//
//    class Magazine : public PrintedMaterial {
//    public:
//        Magazine(unsigned numPages)
//        : PrintedMaterial(numPages)
//        {}
//    private:
//    };
//
//    class Book : public PrintedMaterial {
//    public:
//        Book(unsigned numPages)
//        : PrintedMaterial(numPages)
//        {}
//    private:
//    };
//
//    class TextBook : public Book {
//    public:
//        TextBook(unsigned numPages, unsigned numIndxPgs )
//        : Book(numPages),
//          numOfIndexPages(numIndxPgs)
//        {}
//        void displayNumPages() const {
//        cout << "Pages: ";
//        PrintedMaterial::displayNumPages();
//        cout << "Index pages: ";
//        cout << numOfIndexPages << endl;
//        }
//    private:
//        unsigned numOfIndexPages;
//    };
//
//    class Novel : public Book {
//    public:
//        Novel(unsigned numPages)
//        : Book(numPages)
//        {}
//    private:
//    };
//
//    // tester/modeler code
//    int main() {
//        TextBook text(5430, 23);
//        Novel novel(213);
//        Magazine mag(6);
//
//        text.displayNumPages();
//        novel.displayNumPages();
//        mag.displayNumPages();
//        cout << "===========\n";
//
//        cout << "\nA PrintedMaterial material object!\n";
//        PrintedMaterial pm(2345);
//        pm.displayNumPages();
//
//        cout << "\nA PrintedMaterial variable containing a TextBook value\n";
//        pm = text; // like putting a Textbook into a PrintedMaterial
//        pm.displayNumPages();
//
//        cout << "Try using pointer to base type\n";
//        PrintedMaterial* pmPtr;
//        pmPtr = &text;
//
//        pmPtr->displayNumPages();
//    }


// task 11
// add virtual mechanism to call the method from derived class

//    class PrintedMaterial {
//    public:
//        PrintedMaterial(unsigned numPages)
//        : numOfPages(numPages)
//        {}
//        virtual void displayNumPages() const { cout << numOfPages << endl; }
//    private:
//        unsigned numOfPages;
//    };
//
//    class Magazine : public PrintedMaterial {
//    public:
//        Magazine(unsigned numPages)
//        : PrintedMaterial(numPages)
//        {}
//    private:
//    };
//
//    class Book : public PrintedMaterial {
//    public:
//        Book(unsigned numPages)
//        : PrintedMaterial(numPages)
//        {}
//    private:
//    };
//
//    class TextBook : public Book {
//    public:
//        TextBook(unsigned numPages, unsigned numIndxPgs )
//        : Book(numPages),
//          numOfIndexPages(numIndxPgs)
//        {}
//        void displayNumPages() const {
//        cout << "Pages: ";
//        PrintedMaterial::displayNumPages();
//        cout << "Index pages: ";
//        cout << numOfIndexPages << endl;
//        }
//    private:
//        unsigned numOfIndexPages;
//    };
//
//    class Novel : public Book {
//    public:
//        Novel(unsigned numPages)
//        : Book(numPages)
//        {}
//    private:
//    };
//
//    // tester/modeler code
//    int main() {
//        TextBook text(5430, 23);
//        Novel novel(213);
//        Magazine mag(6);
//
//        text.displayNumPages();
//        novel.displayNumPages();
//        mag.displayNumPages();
//        cout << "===========\n";
//
//        cout << "\nA PrintedMaterial material object!\n";
//        PrintedMaterial pm(2345);
//        pm.displayNumPages();
//
//        pm = text; // like putting a Textbook into a PrintedMaterial
//        pm.displayNumPages();
//
//        cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
//        cout << "Now with the virtual mechanism involved\n";
//        // should work now that the virtual mechanism is being invoked
//        PrintedMaterial* pmPtr;
//        pmPtr = &text;
//        pmPtr->displayNumPages();
//    }

// task 12

//    class PrintedMaterial {
//    public:
//        PrintedMaterial(unsigned numPages)
//        : numOfPages(numPages)
//        {}
//        virtual void displayNumPages() const { cout << numOfPages << endl; }
//    private:
//        unsigned numOfPages;
//    };
//
//    class Magazine : public PrintedMaterial {
//    public:
//        Magazine(unsigned numPages)
//        : PrintedMaterial(numPages)
//        {}
//    private:
//    };
//
//    class Book : public PrintedMaterial {
//    public:
//        Book(unsigned numPages)
//        : PrintedMaterial(numPages)
//        {}
//    private:
//    };
//
//    class TextBook : public Book {
//    public:
//        TextBook(unsigned numPages, unsigned numIndxPgs)
//        : Book(numPages),
//          numOfIndexPages(numIndxPgs)
//        {}
//        void displayNumPages() const {
//        cout << "Pages: ";
//        PrintedMaterial::displayNumPages();
//        cout << "Index pages: ";
//        cout << numOfIndexPages << endl;
//        }
//    private:
//        unsigned numOfIndexPages;
//    };
//
//    class Novel : public Book {
//    public:
//        Novel(unsigned numPages)
//        : Book(numPages)
//        {}
//    private:
//    };
//
//
//    // note that here, reference to PrintedMaterial is the parameter type
//    // so now we can use the dot member operator (the .)  if use the ->
//    // operator, that's not going to work (try it!)
//    void displayNumberOfPages(const PrintedMaterial& anyPM) {
//        anyPM.displayNumPages();
//    }
//
//
//    // tester/modeler code
//    int main() {
//        TextBook text(5430, 23);
//        Novel novel(213);
//        Magazine mag(6);
//
//        text.displayNumPages();
//        novel.displayNumPages();
//        mag.displayNumPages();
//        cout << "===========\n";
//
//        cout << "\nA PrintedMaterial material object!\n";
//        PrintedMaterial pm(2345);
//        pm.displayNumPages();
//
//        pm = text; // like putting a Textbook into a PrintedMaterial
//        pm.displayNumPages();
//
//        cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
//        cout << "Now with the virtual mechanism involved\n";
//        // should work now that the virtual mechanism is being invoked
//        PrintedMaterial* pmPtr;
//        pmPtr = &text;
//        pmPtr->displayNumPages();
//
//        // print some stuff by calling a generic function
//        cout << "\nUse a generic functino for printing\n";
//        displayNumberOfPages(mag);
//        displayNumberOfPages(novel);
//        displayNumberOfPages(text);
//
//    }

// task 13
// cannot compile because without overriden the pure virtual method in the base class in all its children classes, the children would be marked abstract and thus cannot initialize an instance of that class. They need to provide the definition for the pure virtual method

//    class PrintedMaterial {
//    public:
//        PrintedMaterial(unsigned numPages)
//        : numOfPages(numPages)
//        {}
//
//        //               LOOK AT THE = 0
//        virtual void displayNumPages() const = 0;
//    private:
//        unsigned numOfPages;
//    };
//
//    void PrintedMaterial::displayNumPages() const {
//        cout << numOfPages << endl;
//    }
//
//    class Magazine : public PrintedMaterial {
//    public:
//        Magazine(unsigned numPages)
//        : PrintedMaterial(numPages)
//        {}
//    };
//
//    class Book : public PrintedMaterial {
//    public:
//        Book(unsigned numPages)
//        : PrintedMaterial(numPages)
//        {}
//    };
//
//    class TextBook : public Book {
//    public:
//        TextBook(unsigned numPages, unsigned numIndxPgs)
//        : Book(numPages),
//          numOfIndexPages(numIndxPgs)
//        {}
//        void displayNumPages() const {
//        cout << "Pages: ";
//        PrintedMaterial::displayNumPages();
//        cout << "Index pages: ";
//        cout << numOfIndexPages << endl;
//        }
//    private:
//        unsigned numOfIndexPages;
//    };
//
//    class Novel : public Book {
//    public:
//        Novel(unsigned numPages)
//        : Book(numPages)
//        {}
//    };
//
//
//    // note that reference to PrintedMaterial is the parameter type
//    // now we can use the dot member operator
//    // if use the -> operator, thats not going to work (try it!)
//    void displayNumberOfPages(const PrintedMaterial& anyPM) {
//        anyPM.displayNumPages();
//    }
//
//
//    // tester/modeler code
//    int main() {
//        TextBook text(5430, 23);
//        Novel novel(213);
//        Magazine mag(6);
//
//        text.displayNumPages();
//        novel.displayNumPages();
//        mag.displayNumPages();
//        cout << "===========\n";
//
//        cout << "\nA PrintedMaterial material object!\n";
//        PrintedMaterial pm(2345);
//        pm.displayNumPages();
//
//        pm = text; // like putting a Textbook into a PrintedMaterial
//        pm.displayNumPages();
//
//        cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
//        cout << "Now with the virtual mechanism involved\n";
//        // should work now that the virtual mechanism is being invoked
//        PrintedMaterial* pmPtr;
//        pmPtr = &text;
//        pmPtr->displayNumPages();
//
//        // print some stuff by calling a generic function
//        cout << "\nUse a generic functino for printing\n";
//        displayNumberOfPages(mag);
//        displayNumberOfPages(novel);
//        displayNumberOfPages(text);
//    }

// task 14

//    #include <iostream>
//    #include <vector>
//    using namespace std;
//
//    class PrintedMaterial {
//    public:
//        PrintedMaterial(unsigned numPages)
//        : numOfPages(numPages)
//        {}
//
//        virtual void displayNumPages() const = 0;
//
//    private:
//        unsigned numOfPages;
//    };
//
//    void PrintedMaterial::displayNumPages() const {
//        cout << numOfPages << endl;
//    }
//
//    class Magazine : public PrintedMaterial {
//    public:
//        Magazine(unsigned numPages)
//        : PrintedMaterial(numPages)
//        {}
//
//        // virtual - NOTE even without writing "virtual"
//        // again, this overriden method IS virtual
//        // viruality cannot be removed once installed
//        // Also note that the = 0 has is not there
//        void displayNumPages() const {
//        cout << "Hi, I'm a Magazine object stored\n"
//             << "(but I can't know that I am being\n"
//             << "stored (by pointer) in a vector of\n"
//             << "PrintedMaterial pointers!\n";
//        PrintedMaterial::displayNumPages();
//        cout << "(and I'm very glossy!\n";
//        }
//
//    private:
//    };
//
//    class Book : public PrintedMaterial {
//    public:
//        Book(unsigned numPages)
//        : PrintedMaterial(numPages)
//        {}
//
//    private:
//    };
//
//    class TextBook : public Book {
//    public:
//        TextBook(unsigned numPages, unsigned numIndxPgs)
//        : Book(numPages),
//          numOfIndexPages(numIndxPgs)
//        {}
//
//        void displayNumPages() const {
//        cout << "\nThis is a textbook.\n";
//        cout << "It is a very boring textbook.\n";
//        cout << "Pages: ";
//        PrintedMaterial::displayNumPages();
//        cout << "Index pages: ";
//        cout << numOfIndexPages << endl;
//        }
//
//    private:
//        unsigned numOfIndexPages;
//    };
//
//    class Novel : public Book {
//    public:
//        Novel(unsigned numPages)
//        : Book(numPages)
//        {}
//        void displayNumPages() const {
//        cout << "\nThis is the story of a very\n"
//             << " interesting programmer's quest\n"
//             << "  to understand inheritance.\n"
//             << "   The journey is just beginning\n"
//             << "    and already the journeyman\n"
//             << "      hacker, no - not a hacker! -\n"
//             << "         a programmer who reads, and\n"
//             << "             studies and understands code\n"
//             << "                 Hackers steal and don't even\n"
//             << "                      try to understand what they stole\n"
//             << "                           before using it.\n"
//             << "\n       ...But I digress.\n"
//             << "\nThis novel is quite long, there\n"
//             << "being this number of pages:\n"
//             << "=====================================\n"
//             << "                 ";
//        PrintedMaterial::displayNumPages();
//        cout << "=====================================\n"
//             << "Whew!\n"
//             << " but there is an exciting\n"
//             << "  programming adventure on every\n"
//             << "   single one of them!\n"
//             << "    And now, let's let the quest continue..."
//             << endl << endl << endl;
//        }
//
//    private:
//    };
//
//
//    // tester/modeler code
//    int main() {
//        TextBook text(5430, 23);
//        Novel novel(213);
//        Magazine mag(6);
//
//        text.displayNumPages();
//        novel.displayNumPages();
//        mag.displayNumPages();
//        cout << "===========\n";
//
//        cout << "\nUsing PrintedMaterial* to \"store\" a TextBook object\n";
//        cout << "Now with the virtual mechanism involved\n";
//        PrintedMaterial* pmPtr;
//        pmPtr = &text; // like putting t into a vector but
//        // we are actually putting the address of t
//        // into a vector pointers of pointers to
//        // PrintedMaterials. We'll "say" we are putting
//        // t into the vector
//        // (that is, pointers to the Base class)
//        pmPtr->displayNumPages();
//    }

// task 15

#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial {
public:
    PrintedMaterial(unsigned numPages)
    : numOfPages(numPages)
    {}

    virtual void displayNumPages() const = 0;

private:
    unsigned numOfPages;
};

void PrintedMaterial::displayNumPages() const {
    cout << numOfPages << endl;
}

class Magazine : public PrintedMaterial {
public:
    Magazine(unsigned numPages)
    : PrintedMaterial(numPages)
    {}

    // virtual NOTE even without writing "virtual"
    // again, this overriden method IS virtual
    // viruality cannot be removed once installed
    // Also note that the = 0 has is not there
    void displayNumPages() const {
    cout << "Hi, I'm a Magazine object stored\n"
         << "(but I can't know that I am being\n"
         << "stored (by pointer) in a vector of\n"
         << "PrintedMaterial pointers!\n";
    PrintedMaterial::displayNumPages();
    cout << "(and I'm very glossy!\n";
    }

private:
};

class Book : public PrintedMaterial {
public:
    Book(unsigned numPages)
    : PrintedMaterial(numPages)
    {}

private:
};

class TextBook : public Book {
public:
    TextBook(unsigned numPages, unsigned numIndxPgs)
    : Book(numPages),
      numOfIndexPages(numIndxPgs)
    {}

    void displayNumPages() const {
    cout << "\nThis is a textbook.\n";
    cout << "It is a very boring textbook.\n";
    cout << "Pages: ";
    PrintedMaterial::displayNumPages();
    cout << "Index pages: ";
    cout << numOfIndexPages << endl;
    }

private:
    unsigned numOfIndexPages;
};

class Novel : public Book {
public:
    Novel(unsigned numPages)
        : Book(numPages)
    {}
    void displayNumPages() const
    {
        cout << "\nThis is the story of a very\n"
             << " interesting programmer's quest\n"
             << "  understand inheritance.\n"
             << "   The journey is just beginning\n"
             << "    and already the journeyman\n"
             << "      hacker, no - not a hacker! -\n"
             << "         a programmer who reads, and\n"
             << "             studies and understands code\n"
             << "                 Hackers steal and don't even\n"
             << "                      try to understand what they stole\n"
             << "                           before using it.\n"
             << "\n       ...But I digress.\n"
             << "\nThis novel is quite long, there\n"
             << "being this number of pages:\n"
             << "=====================================\n"
             << "                 ";
        PrintedMaterial::displayNumPages();
        cout << "=====================================\n"
             << "Whew!\n"
             << " but there is an exciting\n"
             << "  programming adventure on every\n"
             << "   single one of them!\n"
             << "    And now, let's let the quest continue..."
             << endl << endl << endl;
    }

private:
};


// tester/modeler code
int main() {
    TextBook text(5430, 23);
    Novel novel(213);
    Magazine mag(6);

    // as direct method calls
    cout << "\nEach will now be asked directly,\n"
     << "using the dot member operator to\n"
     << "display its number of pages:\n";
    text.displayNumPages();
    novel.displayNumPages();
    mag.displayNumPages();
    cout << "===========\n";

    // Storing generic objects in a vector
    cout << "\n\nNow we'll use a container. Yea!!!\n\n";
    vector< PrintedMaterial* > allThemPrinties;
    allThemPrinties.push_back(&text);
    allThemPrinties.push_back(&novel);
    allThemPrinties.push_back(&mag);
    for(size_t ndx=0; ndx < allThemPrinties.size(); ++ ndx) {
    allThemPrinties[ndx]->displayNumPages();
    cout << endl;
    }
    cout << "===========\n";
    for (const PrintedMaterial* pmPtr : allThemPrinties) {
    pmPtr->displayNumPages();
    cout << endl;
    }
}
