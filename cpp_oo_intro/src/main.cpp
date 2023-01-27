//This program illustrates the main object-oriented features of the C++ programming language:
//* classes, attributes, and methods
//* encapsulation
//* constructors and destructors
//* static attributes and methods
//* inheritance
//* runtime polymorphism (abstract vs concrete classes)

//including other code
#include <iostream>
#include <animals/Giraffe.h>
#include <animals/birds/Bird.h>
#include <animals/birds/Penguin.h>
#include <exceptions/FoodException.h>
#include "animals/Lion.h"

//including a namespace
using namespace std;

//the entry point of the program.
//the argc and argv parameters of the main function hold the arguments of the program, given through the command line:
//argc is the number of arguments, and argv is the array of strings for the arguments
int main(int argc, char *argv[]) {

    //this illustrates how to check for the program arguments
    if (argc > 1) {
        cout << "Program arguments were provided:" << endl;
        cout << "The 1st element is always the executable file: " << string(argv[0]) << endl;
        cout << "The 2nd element is the 1st program argument: " << string(argv[1]) << endl;
    } else
        cout << "No program arguments were provided:" << endl;

    cout << "---------------------------" << endl;
	
	//see the other code files to know how to declare/implement your own classes
	//the code below illustrates how to uses those classes (how to declare/use variables or instances of customized types/classes and how to use their operations/methods)

    //abstract classes must be initialized with instances of their subclasses that are not abstract (i.e., concrete classes),
    //and the variables should be pointers (in order to achieve polymorphic behavior)
    Animal *alex = new Lion("Alex", "feline");

    string *description = nullptr; //this is how null pointers are initialized
    description = new string(
            "Alex the lion, enjoys showing off for the public and his celebrity status as \"the king of New York\"...");
    //when instances of classes are pointers, methods and attributes of the class are accessed through -> rather than .
    alex->setWikipediaDescription(description);
    alex->setLocation("Africa");


    //notice that the virtual methods of Animal are being called here (i.e., eat and makeNoise), but
    // during the execution, the program actually calls the methods of the subclass, depending on the instance type (in this case a Lion)
    alex->whereIs();
    alex->makeNoise();
    string food = "a buffalo";
    alex->eat(food);
    alex->sleep();
    cout << *alex->getWikipediaDescription() << endl;

    cout << "---------------------------" << endl;

    //a concrete class can be instantiated without a pointer.
    //notice how at the termination of the program, the destructor of the Animal class is called, because this variable
    //is automatically deallocated (by the operating system) from the Stack when the program ends.
    Lion simba("simba");

    //--------------------------------

    //another polymorphic instantiation of an Animal (i.e, a Giraffe)
    Animal *melman = new Giraffe("Melman");
    melman->setWikipediaDescription(
            new string("Melman, a hypochondriac reticulated giraffe who is afraid of germs..."));


    melman->whereIs();
    melman->makeNoise();
    string food2 = "grass";
    melman->eat(food2);
    melman->sleep();
    cout << *melman->getWikipediaDescription() << endl;

    cout << "---------------------------" << endl;


    //a polymorphic instantiation of a Bird (i.e, a Penguin)
    Bird *skipper = new Penguin("Skipper");
    skipper->setWikipediaDescription(
            new string("Skipper, the leader of the penguins..."));


    skipper->whereIs();
    skipper->makeNoise();
    string food3 = "a squid";
    skipper->eat(food3);
    skipper->sleep();
    cout << *skipper->getWikipediaDescription() << endl;

    cout << "---------------------------" << endl;

    //notice here that this is an array of Animals, which contains a Lion, Giraffe, and a Bird (a Penguin).
    //all of these are Animals.
    Animal *madagascarCharacters[3] = {alex, melman, skipper};

    //this loop illustrates runtime polymorphism again.
    //the particular makeNoise is called depending on the type of the instance (i.e., a Lion, Giraffe, or Penguin)
    for (Animal *animal: madagascarCharacters) {
        animal->makeNoise();
    }

    cout << "---------------------------" << endl;

    //this illustrates how to access the static members from Animal.
    //notice that the kingdom is the same for all animals.
    cout << "All animals share the same kingdom: " << Animal::kingdom << " == " << skipper->kingdom << " == "
         << melman->kingdom
         << endl;
    Bird::printKingdom();


    cout << "---------------------------" << endl;

    //this illustrates the try-catch statement, which aims to catch and handle exceptions thrown by the program.
    //an exception is an interruption or unexpected behavior of the program (e.g., errors).
    //exceptions are thrown in different parts of the code, can be caught by the catch blocks (see below).

    try {
        food3 = "grass";
        skipper->eat(food3); //here, eat will throw an exception

        cout << "This statement is not executed if an exception is thrown above (within the try)" << endl;
    } catch (FoodException &ex) {
        //here, an exception of type FoodException is caught and is taken care of
        cerr << "An food exception occurred: " << ex.what() << endl;
    } catch (exception &ex) {
        //here, other exceptions of type "exception" are taken care of
        cerr << "An exception occurred: " << ex.what() << endl;
    } catch (...) {
        //if an exception is not caught by any of the other catch statements, it is caught here!
        cerr << "Unexpected error occurred" << endl;
    }

    //if a thrown exception is not caught (by a try-catch), the program will crash!!
    //try uncommenting this and running the program; it will crash
    //    food3 = "grass";
    //    skipper->eat(food3);

    cout << "---------------------------" << endl;

    //this part illustrates how to call the destructor of the Animal class, which happens when memory is deallocated.
    //failing to delete the pointers may cause memory leaks
    //NOTE: if the program is compiled with CLang, this loop may lead to a crash. Using GCC should work okay.
    //      Unfortunately, the C++ standard does specify how each compiler should handle calling a destructor by delete.
    for (auto &animal: madagascarCharacters)
        delete animal;

    cout << "Done!" << endl;

    return 0;
}
