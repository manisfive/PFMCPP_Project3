 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
#include <cmath>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */
struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

struct Foot
    {
    float length;
    int toes = 5;
    bool flatFooted;
    bool isLeft = true;

    void stepForward();
    int stepSize();
    };

    void run(int howFast, bool startWithLeftFoot);
};

void Person::Foot::stepForward()
{
    if(isLeft==true)
    {
        std::cout << "Left!" << std::endl;
    }
    else
    {
        std::cout << "Right!" << std::endl;
    }
}

int Person::Foot::stepSize()
{
    if(flatFooted == true)
    {
        return 5;
    }
    return 8;  
}
 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */

/*
paste your code below
*/

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
    std::cout << "good to go!" << std::endl;
}
