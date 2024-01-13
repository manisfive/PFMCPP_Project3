/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




struct Guitar
{
    std::string makeModel = "Fender Telecaster";
    int numberOfStrings = 6;
    int numberOfPickups = 2;
    std::string acousticElectricNylon = "Electric";
    bool activePickups = false;
    int HP = 10;
    int audienceMood = 15;

    struct GuitarString
    {
        std::string brand = "D'addario";
        int gauge = 10;
        std::string material = "Nickel wound";
        bool flatwound = false;
        bool coated = false;
        int tuningOpen = 64;//open high E midi number
        float stringAge = 0;

        float bend(int whichString = 1, float distance = 0.0f); 
        void degrade(float time, std::string thisMaterial = "Nickel wound", bool coated = false); 
        void snap();
    };

    GuitarString stringPlaying;

    int emitNote(GuitarString string, int fret = 0);
    void feedback();
    void detachFromStrap();
};

float Guitar::GuitarString::bend(int whichString, float distance)
{
    float tension = 1 + static_cast<float>(whichString) * .2f;
    return distance * tension;
}

void Guitar::GuitarString::degrade(float time, std::string thisMaterial, bool isCoated)
{
    float multiplier;
    if(thisMaterial == "Nickel Wound")
    {
        multiplier = 1.f;
    }
    else if(thisMaterial == "Phospher Bronze")
    {
        multiplier = 1.5f;
    }
    else
    {
        multiplier = 2.0f;
    }
    if(isCoated == true)
    {
        multiplier *= .5f;
    }
    stringAge += time * multiplier;
}

void Guitar::GuitarString::snap()
{
    stringAge = 1;
}

int Guitar::emitNote(GuitarString thisString, int fret)
{
    stringPlaying = thisString;
    int note = stringPlaying.tuningOpen + fret;
    return note;
}

void Guitar::feedback()
{
    audienceMood -= 3;
}

void Guitar::detachFromStrap()
{
    HP -= 2;
}

struct Oven
{
    int numberOfBurners = 4;
    std::string glassCoilGas = "Gas";
    float rateOfTemperatureIncrease = 16.5f;
    float cubicFeetOfInterior = 9.8f;
    bool selfCleaning = true;
    int currentTemp = 70;
    
    void heatToDesiredTemperature(int temp);
    bool alertTimerExpired(int time); 
    void selfClean();
};

void Oven::heatToDesiredTemperature(int temp)
{
    while(Oven::currentTemp < temp)
    {
        ++currentTemp;
    }
}

bool alertTimerExpired(int time)
{
    while(time >= 0)
    {
        --time;
    }
    return time == 0;
}

void Oven::selfClean()
{
    heatToDesiredTemperature(1000);
}

struct Book
{
    float height = 7.9f;
    float width = 5.5f;
    bool hardcover = false;
    int numberOfPages = 350;
    std::string author = "Kieth, Sam";
    int currentPage = 0;
    float agedAmount = 0.f;

    void displayNextPage(); 
    void displayPreviousPage(); 
    void whiteToYellowProgress(float amount);
};

void Book::displayNextPage()
{
    if(0 <= currentPage < numberOfPages)
    {
        ++currentPage;
    }
}

void Book::displayPreviousPage()
{
    if(0 < currentPage <= numberOfPages)
    {
        --currentPage;
    }
}

void Book::whiteToYellowProgress(float amount)
{
    agedAmount = agedAmount + amount;
}

struct Bird
{
    float height = 7.0f;
    float altitude = 4800.0f;
    float wingspan = 15.0f;
    std::string type = "pigeon";
    bool isMale = true;

    struct Progeny
    {
        bool stillEgg = true;
        float percentToMaturity = 0.0f;
        float satedLevel = 0.0f;
        bool canFly = false;
        bool canForage = false;

        void flyTheNest();
        void eat(float maturePercent, std::string target);
        int chirp(bool parentPresent, float location, int timeOfDay);
    };

    Progeny fledgling;
    double fly(double x, double y);
    void sing();
    void eat(std::string target);
    void forage(Progeny progeny);
};

void Bird::Progeny::flyTheNest()
{
    float growUp = percentToMaturity + satedLevel;
    if(.80f < percentToMaturity || 1.f <= growUp)
    {
        std::cout << "Your Fledgling grew up!";
    }
    else if(.60f <= percentToMaturity)
    {
        std::cout << "Your Fledgling survived the attempt, but isn't ready to grow up.";
    }
    else
    {
        std::cout << "Your Fledgling didn't survive the attempt...";
    }
    
}

void Bird::Progeny::eat(float maturePercent, std::string target)
{
    std::cout << "Your Fledgling ate a " << target;
    percentToMaturity += maturePercent;
}

int Bird::Progeny::chirp(bool parentPresent, float location, int timeOfDay)
{
    int safety = 0;
    if (parentPresent == true)
    {
        safety += 45;
    }
    if(location >= 40.f)
    {
        safety += 20;
    }
    if(7 < timeOfDay && timeOfDay < 18)
    {
        safety += 35;
    }
    return safety;
}

double Bird::fly(double x, double y)
{
    return sqrt(pow(x, 2.) + pow(y, 2.));
}

void Bird::sing()
{
    std::cout << "The bird sings!";
}

void Bird::eat(std::string target)
{
    std::cout << "Your Bird ate a " << target;
}

void Bird::forage(Progeny progeny)
{
    fledgling = progeny;
    if(fledgling.percentToMaturity <= .2f)
    {
        std::cout << "Your fledglingneeds some seed!";
    }
    else if(.2f < fledgling.percentToMaturity && fledgling.percentToMaturity <= .6f)
    {
        std::cout << "Your fledgling needs a worm!";
    }
    else
    {
        std::cout << "Your fledgling needs a beetle!";
    }
}

struct CPU
{
    std::string manufacturer = "AMD";
    float temperature = 55.5f;
    float clockSpeed = 3.5f;
    int cores = 6;
    std::string socket = "AM4";

    float storeData(); 
    float outputResults(); 
    float compute(float x, float y);
};

float CPU::storeData()
{
    return 1.43667f * 2.44435f * temperature;
}

float CPU::outputResults()
{
    return 89.667f * .30741f * temperature;
}

float CPU::compute(float x, float y)
{
    return x * y * temperature;
}

struct Motherboard
{
    std::string manufacturer = "Gigabyte";
    bool wirelessLAN = false;
    int m2Slots = 2;
    int expansionSlots = 4;
    int maxRAM = 64;
    int AVSignals = 0;
    
    void dataToRAM();
    void generateAVSignals();
    void autoSuspend();
};

void Motherboard::dataToRAM()
{
    ++maxRAM;
}

void Motherboard::generateAVSignals()
{
    ++AVSignals;
}

void Motherboard::autoSuspend()
{
    maxRAM = 0;
    AVSignals = 0;
}

struct KeyboardAndMouse
{
    int numberOfMouseButtons = 3;
    bool mechanicalStyle = false;
    bool wireless = true;
    std::string language = "English";
    bool numpad = false;

    int transmitKeystrokeData();
    double transmitXYChange(double x, double y);
    bool toggleStatus(bool status);
};

int KeyboardAndMouse::transmitKeystrokeData()
{
    return 103;
}

double KeyboardAndMouse::transmitXYChange(double x, double y)
{
    return sqrt(pow(x, 2.) + pow(y, 2.));
}

bool KeyboardAndMouse::toggleStatus(bool status)
{
    if(status == true)
    {
        return false;
    }
        return true;
}

struct CoolingSystem
{
    bool liquid = false;
    int numberOfRGB = 5;
    int numberOfFans = 3;
    int fanSetting = 2;
    bool molex = false;
    std::string lightColor = "red";

    void setFanSpeed(int speed);   
    void setLightColor(std::string color);
    void springALeak();
};

void CoolingSystem::setFanSpeed(int speed)
{
    if(0 <= speed && speed >= 5)
    {
        fanSetting = speed;
    }
    else
    {
        std::cout << "Invalid Selection";
    }
}

void CoolingSystem::setLightColor(std::string color)
{
    if(color == "red" || color == "orange" || color == "blue" || color == "green")
    {
        lightColor = color;
    }
    else
    {
        std::cout << "Please Pick a Color";
    }
    
}

void CoolingSystem::springALeak()
{
    liquid = true;
}

struct GPU
{
    bool intel = false;
    int ram = 8;
    float clockSpeed = 1525.f;
    int numberOfFans = 3;
    int numberOfOutputs = 4;
    int AVSignals = 0;
    int currentRGB = 0;
    int fanSpeed = 3;

    void outputAVSignal();
    void cycleRGBDisplay(); 
    void adjustFanSpeed(int speed);
};

void GPU::outputAVSignal()
{
    ++AVSignals;
}

void GPU::cycleRGBDisplay()
{
    if(currentRGB < 8)
    {
        currentRGB += 1;
    }
    else
    {
        currentRGB = 0;
    }
}

void GPU::adjustFanSpeed(int speed)
{
    if(0 <= speed && speed >= 5)
    {
        fanSpeed = speed;
    }
    else
    {
        std::cout << "Invalid Selection";
    }
}

struct Computer
{
    CPU myCPU;
    Motherboard myMotherboard;
    KeyboardAndMouse myKeyboardAndMouse;
    CoolingSystem myCoolingSystem;
    GPU myGPU;
    
    void runProgram();
    void allocateRAM();
    void refreshDisplay();
};

void Computer::runProgram()
{
    std::cout << "You are running my program...";
}

void Computer::allocateRAM()
{
    myMotherboard.dataToRAM();
}

void Computer::refreshDisplay()
{
    myMotherboard.generateAVSignals();
    myGPU.outputAVSignal();
}

int main()
{
    Example::main();

    
    std::cout << "good to go!" << std::endl;
}
