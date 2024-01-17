/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.

 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
#include <cmath>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            ++bar.num;                    //2a), 5)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()


struct Guitar
{
    Guitar();
    std::string makeModel;
    int numberOfStrings;
    int numberOfPickups{2};
    std::string acousticElectricNylon;
    bool activePickups{false};
    int HP;
    int audienceMood;

    struct GuitarString
    {
        GuitarString();
        std::string brand;
        int gauge;
        std::string material = "Nickel wound";
        bool flatwound = false;
        bool coated;
        int tuningOpen;
        float stringAge;

        float bend(int whichString = 1, float distance = 0.0f); 
        void degrade(float time, std::string thisMaterial = "Nickel wound", bool coated = false); 
        void snap();
        void printMaterialCoated();
        void microwave(int time);
    };

    GuitarString stringPlaying;

    int emitNote(GuitarString string, int fret = 0);
    void feedback();
    void detachFromStrap();
    void printPickupsStrings();
    void polish();
};

Guitar::GuitarString::GuitarString() :
coated(false),
tuningOpen(64) //open high E midi number
{
    brand = "D'addario";
    gauge = 10;
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

void Guitar::GuitarString::microwave(int time)
{
    if(stringAge == 0.f)
    {
        stringAge = 0.0003f;
    }
    while(time > 0)
    {
        std::cout << "He's cooking now!" << std::endl;
        stringAge *= 3.0f;
        --time;
    }
    std::cout << "That string is cooked! String age: " << stringAge << std::endl;
}


void Guitar::GuitarString::printMaterialCoated()
{
    std::cout << "Guitar::GuitarString::printMaterialCoated() material:" << material << " coated: " << coated << std::endl; 
}

Guitar::Guitar() : 
numberOfStrings(6),
acousticElectricNylon("electric")
{
    makeModel = "Fender Telecaster";
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

void Guitar::printPickupsStrings()
{
    std::cout << "Guitar::printPickupsStrings() pickups:" << numberOfPickups << " strings: " << numberOfStrings << std::endl; 
}

void Guitar::polish()
{
    while(HP < 10)
    {
        std::cout << "Polishing the guitar..." << std::endl;
        ++HP;
    }
    std::cout << "Your guitar is good as new!" << std::endl;
}

struct Oven
{
    Oven();
    int numberOfBurners;
    std::string glassCoilGas;
    float rateOfTemperatureIncrease{16.5f};
    float cubicFeetOfInterior;
    bool selfCleaning;
    int currentTemp = 70;

    void heatToDesiredTemperature(int temp);
    bool alertTimerExpired(int time); 
    void selfClean();
    void printRateOfIncreaseAndCubicFeet();
};

Oven::Oven() :
cubicFeetOfInterior{9.8f},
selfCleaning(true)
{
    numberOfBurners = 4;
    glassCoilGas = "Gas";
    std::cout << "Oven has been constructed!" << std::endl;
}

void Oven::heatToDesiredTemperature(int temp)
{
    while(Oven::currentTemp < temp)
    {
        std::cout << "Oven is " << currentTemp << "!" << std::endl;
        currentTemp += static_cast<int>(rateOfTemperatureIncrease);
    }
    std::cout << "Oven is ready!" << std::endl;
    currentTemp = 0;
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

void Oven::printRateOfIncreaseAndCubicFeet()
{
    std::cout << "Oven::printRateOfIncreaseAndCubicFeet() rate of increase:" << rateOfTemperatureIncrease << " cubic feet: " << cubicFeetOfInterior << std::endl; 
}

struct Book
{
    Book();
    float height;
    float width;
    bool hardcover;
    int numberOfPages = 350;
    std::string author;
    int currentPage;
    float agedAmount;

    void displayNextPage(); 
    void displayPreviousPage(); 
    void whiteToYellowProgress(float amount);
    void printNumberOfPagesAndCurrentPage();
    void readPages(int pages);
};

Book::Book() :
currentPage(0),
agedAmount{0.f}
{
    height = 7.9f;
    width = 5.5f;
    hardcover = false;
    author = "Kieth, Sam";
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

void Book::printNumberOfPagesAndCurrentPage()
{
    std::cout << "Book::printNumberOfPagesAndCurrentPage() numner of pages:" << numberOfPages << " current page: " << currentPage << std::endl; 
}

void Book::readPages(int pages)
{
    for(int i = pages; i > 0; --i)
    {    
        if(currentPage >= numberOfPages)
        {
            std::cout << "What a good book!" << std::endl; 
            return;
        }
        else
        {
            std::cout << "What an interesting page " << currentPage << " is..." <<std::endl;
            ++currentPage;
        }
    }
    std::cout << "It was so fun reading " << pages << " pages!" << std::endl; 
}

struct Bird
{
    Bird();
    float height;
    float altitude;
    double wingspan;
    std::string type;
    bool isMale = true;
    double distance = 0.;

    struct Progeny
    {
        Progeny();
        bool stillEgg;
        float percentToMaturity;
        float satedLevel{0.f};
        bool canFly = false;
        bool canForage;

        void flyTheNest();
        void eat(float maturePercent, std::string target);
        int chirp(bool parentPresent, float location, int timeOfDay);
        void printSatedEgg();
        void hatch();
    };

    Progeny fledgling;
    void fly(double x, double y);
    void sing();
    void eat(std::string target);
    void forage(Progeny progeny);
    void printMaleWingspan();
    void howManyFlaps();
};

Bird::Progeny::Progeny() :
stillEgg(true),
percentToMaturity{0.f}
{
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

void Bird::Progeny::printSatedEgg()
{
    std::cout << "Bird::Progeny::printSatedEgg() satedLevel:" << satedLevel << " stillEgg: " << stillEgg << std::endl; 
}

void Bird::Progeny::hatch()
{
    if(stillEgg)
    {
        for(int i = 1; i < 20; ++i)
        {
            std::cout << "Embryo is growing..." << std::endl;
        }
        std::cout << "Fledgling has hatched!" << std::endl;
        stillEgg = false;
    }
}


Bird::Bird() :
wingspan{15.0},
type("pigeon")
{
    height = 7.0f;
    altitude = 4800.0f;
    std::cout << "Bird has been constructed!" << std::endl;
}

void Bird::fly(double x, double y)
{
    distance += sqrt(pow(x, 2.) + pow(y, 2.));
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

void Bird::printMaleWingspan()
{
    std::cout << "Bird::printMaleWingspan() male?:" << isMale << " wingspan: " << wingspan << std::endl; 
}

void Bird::howManyFlaps()
{
    double i = distance;
    int j = 0;
    while(i > 0)
    {
        ++j;
        i -= wingspan;
    }
    std::cout << "Your bird has flappped " << j << " times so far!" << std::endl;
}

struct CPU
{
    CPU();
    std::string manufacturer;
    float temperature;
    float clockSpeed;
    int cores;
    std::string socket = "AM4";

    float storeData(); 
    float outputResults(); 
    float compute(float x, float y);
    void printClockSpeedAndSocket();
    void overheat();
};

CPU::CPU() :
clockSpeed{3.5f},
cores(6)
{
    manufacturer = "AMD";
    temperature = 55.5f;
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

void CPU::printClockSpeedAndSocket()
{
    std::cout << "CPU::printClockSpeedAndSocket() clock speed:" << clockSpeed << " socket: " << socket << std::endl; 
}

void CPU::overheat()
{
    while(temperature < 210)
    {
        std::cout << "Add another insert reverb!" << std::endl;
        temperature += 15;
    }   
    std::cout << "Overheated! Shutting down..." << std::endl;
    temperature = 55;
}

struct Motherboard
{
    Motherboard();
    std::string manufacturer;
    bool wirelessLAN;
    int m2Slots;
    int expansionSlots;
    int maxRAM = 64;
    int AVSignals;

    void dataToRAM();
    void generateAVSignals();
    void autoSuspend();
    void printMaxRAMAndManufacturer();
    void badSectors();
};

Motherboard::Motherboard() :
manufacturer("Gigabyte"),
m2Slots(2)
{
    wirelessLAN = false;
    expansionSlots = 4;
    AVSignals = 0;
    std::cout << "Motherboard has been constructed!" << std::endl;
}

void Motherboard::dataToRAM()
{
    maxRAM += 5;
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

void Motherboard::printMaxRAMAndManufacturer()
{
    std::cout << "Motherboard::printMaxRAMAndManufacturer() max RAM:" << maxRAM << " manufacturer: " << manufacturer << std::endl; 
}

void Motherboard::badSectors()
{
    while(maxRAM > 0)
    {
        std::cout << "RAM corrupted!" << std::endl; 
        --maxRAM;
    }
}


struct KeyboardAndMouse
{
    KeyboardAndMouse();
    int numberOfMouseButtons;
    bool mechanicalStyle;
    bool wireless;
    std::string language;
    bool numpad = false;

    int transmitKeystrokeData();
    double transmitXYChange(double x, double y);
    bool toggleStatus(bool status);
    void printNumpadAndLanguage();
    void typing(int words);
};

KeyboardAndMouse::KeyboardAndMouse() :
wireless(true),
language("English")
{
    numberOfMouseButtons = 3;
    mechanicalStyle = false;
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

void KeyboardAndMouse::printNumpadAndLanguage()
{
    std::cout << " KeyboardAndMouse::printNumpadAndLanguage() numpad:" << numpad << " language: " << language << std::endl; 
}

void KeyboardAndMouse::typing(int words)
{
    int check = 1;
    for(int i = words * 6; i > 0; --i)
    {
        if(check == 1)
        {
            std::cout << "Click!" << std::endl;
            check = 0;      
        }
        else
        {
            std::cout << "Clack!" << std::endl;
            check = 1;
        }
    }
}

struct CoolingSystem
{

    CoolingSystem();
    bool liquid;
    int numberOfRGB;
    int numberOfFans = 3;
    int fanSetting;
    bool molex;
    std::string lightColor;

    void setFanSpeed(int speed);   
    void setLightColor(std::string color);
    void springALeak();
    void printFansRGB();
    void powerStatus(int hours);

};

CoolingSystem::CoolingSystem() :
liquid(false),
numberOfRGB(5)
{
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

void CoolingSystem::printFansRGB()
{
    std::cout << "CoolingSystem::printFansRGB() number of fans:" << numberOfFans << " number of RGB: " << numberOfRGB << std::endl; 
}

void CoolingSystem::powerStatus(int hours)
{
    int jigawatts = 8;
    for(int i = hours* 60; i > 0; --i)
    {
        std::cout << "Cooling has consumed " << jigawatts << " jigawatts!" << std::endl; 
        jigawatts += 8;
    }
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
    int fanSpeed = 3;
    int model = 1;

    void outputAVSignal();
    void cycleRGBDisplay(); 
    void adjustFanSpeed(int speed);
    void printFanSpeedRGBCycle();
    void upgrade();

};

GPU::GPU() :
AVSignals(0),
currentRGB(0)
{
    intel = false;
    ram = 8;
    clockSpeed = 1525.f;
    numberOfFans = 3;
    numberOfOutputs = 4;
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

void GPU::printFanSpeedRGBCycle()
{
    std::cout << "GPU::printFanSpeedRGBCycle() fan speed:" << fanSpeed << " RGB cycle: " << currentRGB << std::endl; 
}

void GPU::upgrade()
{
    while(model < 5)
    {
        if(model == 1)
        {
            std::cout << "You got a GTX 1660!" << std::endl;
            ++model;
        }
        if(model == 2)
        {
            std::cout << "You got a RTX 2070!"<< std::endl;
            ++model;
        }
        if(model == 3)
        {
            std::cout << "You got a RTX 3070!"<< std::endl;
            ++model;
        }
        if(model == 4)
        {
            std::cout << "You got a RTX 4090!"<< std::endl;
            ++model;
        }
    }
model = 1;
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
    void printStats();
    void typingAndPowerStatus(int a, int b);
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

void Computer::printStats()
{
    myMotherboard.printMaxRAMAndManufacturer();
    myGPU.printFanSpeedRGBCycle();
}

void Computer::typingAndPowerStatus(int a, int b)
{
    myKeyboardAndMouse.typing(a);
    myCoolingSystem.powerStatus(b);
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
    bird.fly(6348.22, 81000.2);
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

    tele.printPickupsStrings();
    tele1.printMaterialCoated();
    oven.printRateOfIncreaseAndCubicFeet();
    book.printNumberOfPagesAndCurrentPage();
    bird.printMaleWingspan();
    progeny.printSatedEgg();
    ryzen.printClockSpeedAndSocket();
    motherboard.printMaxRAMAndManufacturer();
    logitech.printNumpadAndLanguage();
    noctua.printFansRGB();
    nvidia.printFanSpeedRGBCycle();
    dell.printStats();

    tele.polish();
    tele1.microwave(4);
    oven.heatToDesiredTemperature(500);
    book.readPages(400);
    bird.howManyFlaps();
    progeny.hatch();
    ryzen.overheat();
    motherboard.badSectors();
    logitech.typing(7);
    noctua.powerStatus(2);
    nvidia.upgrade();
    dell.typingAndPowerStatus(2, 3);

    std::cout << "good to go!" << std::endl;
}

