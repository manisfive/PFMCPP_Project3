/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) do this for each class in this project: 
    initialize some of your member variables either in-class or in the Constructor member initializer list.
    Show me that you understand how to use these language features.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable that IS NOT initialized in-class
    float b { 2.f }; //a member variable that IS initialized in-class
    UDT() : a(0) { } // 'constructor-initializer-list' initializing the member that wasn't initialized in-class.
    void printAandB()  //the member function
    {
        std::cout << "UDT::printAandB() a:" << a << " b: " << b << std::endl;  //2) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printAandB(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()




struct Guitar
{
    Guitar();
    std::string makeModel;
    int numberOfStrings;
    int numberOfPickups;
    std::string acousticElectricNylon;
    bool activePickups;
    int HP;
    int audienceMood;

    struct GuitarString
    {
        GuitarString();
        std::string brand;
        int gauge;
        std::string material;
        bool flatwound;
        bool coated;
        int tuningOpen;
        float stringAge;

        float bend(int whichString = 1, float distance = 0.0f); 
        void degrade(float time, std::string thisMaterial = "Nickel wound", bool coated = false); 
        void snap();
    };

    GuitarString stringPlaying;

    int emitNote(GuitarString string, int fret = 0);
    void feedback();
    void detachFromStrap();
};

Guitar::GuitarString::GuitarString()
{
    brand = "D'addario";
    gauge = 10;
    material = "Nickel wound";
    flatwound = false;
    coated = false;
    tuningOpen = 64;//open high E midi number
    stringAge = 0;
    std::cout << "GuitarString has been constructed!" << std::endl;
}

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
    std::cout << "Time to change strings..." << std::endl;
}

Guitar::Guitar()
{
    makeModel = "Fender Telecaster";
    numberOfStrings = 6;
    numberOfPickups = 2;
    acousticElectricNylon = "electric";
    activePickups = false;
    HP = 10;
    audienceMood = 10;
    std::cout << "Guitar has been constructed!" << std::endl;
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
    std::cout << "Clunk!" << std::endl;
}

struct Oven
{
    Oven();
    int numberOfBurners;
    std::string glassCoilGas;
    float rateOfTemperatureIncrease;
    float cubicFeetOfInterior;
    bool selfCleaning;
    int currentTemp;
    
    void heatToDesiredTemperature(int temp);
    bool alertTimerExpired(int time); 
    void selfClean();
};

Oven::Oven()
{
    numberOfBurners = 4;
    glassCoilGas = "Gas";
    rateOfTemperatureIncrease = 16.5f;
    cubicFeetOfInterior = 9.8f;
    selfCleaning = true;
    currentTemp = 70;
    std::cout << "Oven has been constructed!" << std::endl;
}

void Oven::heatToDesiredTemperature(int temp)
{
    while(Oven::currentTemp < temp)
    {
        ++currentTemp;
    }
    std::cout << "Oven is ready!" << std::endl;
}

bool Oven::alertTimerExpired(int time)
{
    while(time >= 0)
    {
        --time;
    }
    std::cout << "Ding!" << std::endl;
    return time == 0;
}

void Oven::selfClean()
{
    heatToDesiredTemperature(1000);
}

struct Book
{
    Book();
    float height;
    float width;
    bool hardcover;
    int numberOfPages;
    std::string author;
    int currentPage;
    float agedAmount;

    void displayNextPage(); 
    void displayPreviousPage(); 
    void whiteToYellowProgress(float amount);
};

Book::Book()
{
    height = 7.9f;
    width = 5.5f;
    hardcover = false;
    numberOfPages = 350;
    author = "Kieth, Sam";
    currentPage = 0;
    agedAmount = 0.f;
    std::cout << "Book has been constructed!" << std::endl;
}

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
    Bird();
    float height;
    float altitude;
    float wingspan;
    std::string type;
    bool isMale;

    struct Progeny
    {
        Progeny();
        bool stillEgg;
        float percentToMaturity;
        float satedLevel;
        bool canFly;
        bool canForage;

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

Bird::Progeny::Progeny()
{
    stillEgg = true;
    percentToMaturity = 0.0f;
    satedLevel = 0.0f;
    canFly = false;
    canForage = false;
    std::cout << "Progeny has been constructed!" << std::endl;
}

void Bird::Progeny::flyTheNest()
{
    float growUp = percentToMaturity + satedLevel;
    if(.80f < percentToMaturity || 1.f <= growUp)
    {
        std::cout << "Your Fledgling grew up!" << std::endl;
    }
    else if(.60f <= percentToMaturity)
    {
        std::cout << "Your Fledgling survived the attempt, but isn't ready to grow up." << std::endl;
    }
    else
    {
        std::cout << "Your Fledgling didn't survive the attempt..." << std::endl;
    }
    
}

void Bird::Progeny::eat(float maturePercent, std::string target)
{
    std::cout << "Your Fledgling ate a " << target << std::endl;
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
    std::cout << "Chirp !!" << std::endl;
    return safety;
}

Bird::Bird()
{
    height = 7.0f;
    altitude = 4800.0f;
    wingspan = 15.0f;
    type = "pigeon";
    isMale = true;
    std::cout << "Bird has been constructed!" << std::endl;
}

double Bird::fly(double x, double y)
{
    return sqrt(pow(x, 2.) + pow(y, 2.));
}

void Bird::sing()
{
    std::cout << "Tweet !!" << std::endl;
}

void Bird::eat(std::string target)
{
    std::cout << "Your Bird ate a " << target << std::endl;
}

void Bird::forage(Progeny progeny)
{
    fledgling = progeny;
    if(fledgling.percentToMaturity <= .2f)
    {
        std::cout << "Your Fledgling needs some seed!" << std::endl;
    }
    else if(.2f < fledgling.percentToMaturity && fledgling.percentToMaturity <= .6f)
    {
        std::cout << "Your Fledgling needs a worm!" << std::endl;
    }
    else
    {
        std::cout << "Your Fledgling needs a beetle!" << std::endl;
    }
}

struct CPU
{
    CPU();
    std::string manufacturer;
    float temperature;
    float clockSpeed;
    int cores;
    std::string socket;

    float storeData(); 
    float outputResults(); 
    float compute(float x, float y);
};

CPU::CPU()
{
    manufacturer = "AMD";
    temperature = 55.5f;
    clockSpeed = 3.5f;
    cores = 6;
    socket = "AM4";
    std::cout << "CPU has been constructed!" << std::endl;
}

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
    Motherboard();
    std::string manufacturer;
    bool wirelessLAN;
    int m2Slots;
    int expansionSlots;
    int maxRAM;
    int AVSignals;
    
    void dataToRAM();
    void generateAVSignals();
    void autoSuspend();
};

Motherboard::Motherboard()
{
    manufacturer = "Gigabyte";
    wirelessLAN = false;
    m2Slots = 2;
    expansionSlots = 4;
    maxRAM = 64;
    AVSignals = 0;
    std::cout << "Motherboard has been constructed!" << std::endl;
}

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
    KeyboardAndMouse();
    int numberOfMouseButtons;
    bool mechanicalStyle;
    bool wireless;
    std::string language;
    bool numpad;

    int transmitKeystrokeData();
    double transmitXYChange(double x, double y);
    bool toggleStatus(bool status);
};

KeyboardAndMouse::KeyboardAndMouse()
{
    numberOfMouseButtons = 3;
    mechanicalStyle = false;
    wireless = true;
    language = "English";
    numpad = false;
    std::cout << "KeyboardAndMouse has been constructed!" << std::endl;
}
    
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
    
    CoolingSystem();
    bool liquid;
    int numberOfRGB;
    int numberOfFans;
    int fanSetting;
    bool molex;
    std::string lightColor;

    void setFanSpeed(int speed);   
    void setLightColor(std::string color);
    void springALeak();
};

CoolingSystem::CoolingSystem()
{
    liquid = false;
    numberOfRGB = 5;
    numberOfFans = 3;
    fanSetting = 2;
    molex = false;
    lightColor = "red";
    std::cout << "CoolingSystem has been constructed!" << std::endl;
}
    
void CoolingSystem::setFanSpeed(int speed)
{
    if(0 <= speed && speed >= 5)
    {
        fanSetting = speed;
    }
    else
    {
        std::cout << "Invalid Selection" << std::endl;//the if and else are both executed ???
    }
    std::cout << "Speed is " << fanSetting << std::endl;
}

void CoolingSystem::setLightColor(std::string color)
{
    if(color == "red" || color == "orange" || color == "blue" || color == "green")
    {
        lightColor = color;
    }
    else
    {
        std::cout << "Please Pick a Color" << std::endl;
    }
    
}

void CoolingSystem::springALeak()
{
    liquid = true;
}

struct GPU
{
    GPU();
    bool intel;
    int ram;
    float clockSpeed;
    int numberOfFans;
    int numberOfOutputs;
    int AVSignals;
    int currentRGB;
    int fanSpeed;

    void outputAVSignal();
    void cycleRGBDisplay(); 
    void adjustFanSpeed(int speed);
};

GPU::GPU()
{
    intel = false;
    ram = 8;
    clockSpeed = 1525.f;
    numberOfFans = 3;
    numberOfOutputs = 4;
    AVSignals = 0;
    currentRGB = 0;
    fanSpeed = 3;
    std::cout << "GPU has been constructed!" << std::endl;
}

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
        std::cout << "Invalid Selection" << std::endl;
    }
    std::cout << "Speed is " << fanSpeed << std::endl;
}

struct Computer
{
    Computer();
    CPU myCPU;
    Motherboard myMotherboard;
    KeyboardAndMouse myKeyboardAndMouse;
    CoolingSystem myCoolingSystem;
    GPU myGPU;

    void runProgram();
    void allocateRAM();
    void refreshDisplay();
};

Computer::Computer()
{
    std::cout << "Computer has been constructed!" << std::endl;
}

void Computer::runProgram()
{
    std::cout << "You are running my program..." << std::endl;
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
    Guitar tele;
    Guitar::GuitarString tele1;
    Oven oven;
    Book book;
    Bird bird;
    Bird::Progeny progeny;
    CPU ryzen;
    Motherboard motherboard;
    KeyboardAndMouse logitech;
    CoolingSystem noctua;
    GPU nvidia;
    Computer dell;
    
    tele.emitNote(tele1, 7);    
    tele.detachFromStrap();
    tele.feedback();
    tele1.bend(2, 0.3f);
    tele1.degrade(20.5f);
    tele1.snap();    
    oven.alertTimerExpired(12);
    oven.heatToDesiredTemperature(450);
    oven.selfClean();    
    book.displayNextPage();
    book.displayPreviousPage();
    book.whiteToYellowProgress(.43f);   
    bird.eat("worm");
    bird.fly(20.66, 80.5);
    bird.sing();
    bird.forage(progeny);
    progeny.flyTheNest();
    progeny.eat(.67f, "worm");
    progeny.chirp(true, .788f, 12);    
    ryzen.storeData();
    ryzen.compute(46.7866f, 30027.11111f);
    ryzen.outputResults();    
    motherboard.autoSuspend();
    motherboard.dataToRAM();
    motherboard.generateAVSignals();    
    logitech.toggleStatus(false);
    logitech.transmitKeystrokeData();
    logitech.transmitXYChange(753.22, 966.80);    
    noctua.setFanSpeed(2);
    noctua.setLightColor("orange");
    noctua.springALeak();    
    nvidia.adjustFanSpeed(3);
    nvidia.cycleRGBDisplay();
    nvidia.outputAVSignal();
    dell.allocateRAM();
    dell.refreshDisplay();
    dell.runProgram();
    std::cout << "Progeny's percent to maturity is " << progeny.percentToMaturity << "." << std::endl;
    std::cout << "The Result of Ryzen's computation is " << ryzen.outputResults() << "." << std::endl;
    std::cout << "Oven's current temperature is " << oven.currentTemp << "." << std::endl;
    std::cout << "Noctua's RGB color is " << noctua.lightColor << "." << std::endl;
    std::cout << "The book has " << book.numberOfPages << " pages." << std::endl;
    std::cout << "good to go!" << std::endl;
}
