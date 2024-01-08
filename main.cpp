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
    //5 properties:
    //    1) make/model (std::string)
    std::string makeModel = "Fender Telecaster";
    //    2) number of strings (int)
    int numberOfStrings = 6;
    //    3) number of pickups (int)
    int numberOfPickups = 2;
    //    4) acoustic/electric/nylon (std::string)
    std::string acousticElectricNylon = "Electric";
    //    5) active pickups yes/no (bool)
    bool activePickups = false;

    struct GuitarString
    {
        std::string brand = "D'addario";
        int gauge = 10;
        std::string material = "Nickel wound";
        bool flatwound = false;
        bool coated = false;
        std::string tuningOpen = "E4";

        float bend(int whichString, float distance = 0.0f); //adds pitchbend to emitNote() based on added tension
        float degrade(float time, std::string material = "Nickel wound", bool coated = false); //lowers frequency value on a lowpass filter based on style of string
        void snap();
    };

    //3 things it can do:
    //    1) emit note
    int emitNote(GuitarString string, int fret = 0); //midi note number
    //    2) feedback
    void feedback();
    //    3) detach from strap
    void detachFromStrap();
};

struct Oven
{
    //5 properties:
    //    1) number of burners on the stovetop (int)
    int numberOfBurners = 4;
    //    2) glass top, coil, gas (std::string)
    std::string glassCoilGas = "Gas";
    //    3) rate of temperature increase (float)
    float rateOfTemperatureIncrease = 16.5f;
    //    4) cubic feet of interior (float)
    float cubicFeetOfInterior = 9.8f;
    //    5) self cleaning (bool)
    bool selfCleaning = true;
    //3 things it can do:
    //    1) heats to desired temperature
    void heatToDesiredTemperature(float temp);
    //    2) alert timer expired
    bool alertTimerExpired(int time); //input seconds until true, returns alarmSounds == true
    //    3) self-clean
    void selfClean();
};

struct Book
{
    //5 properties:
    //    1) height (float)
    float height = 7.9f;
    //    2) width (float)
    float width = 5.5f;
    //    3) hardcover yes/no (bool)
    bool hardcover = false;
    //    4) number of pages (int)
    int numberOfPages = 350;
    //    5) author (std::string)
    std::string author = "Kieth, Sam";
    //3 things it can do:
    //    1) display next page
    int displayNextPage(); //new page number
    //    2) display previous page
    int displayPreviousPage(); //new page number
    //    3) increment progress from white to yellow
    float whiteToYellowProgress(float amount); //input percent yellowed, output total percentage
};

struct Bird
{
    //5 properties:
    //    1) height (float)
    float height = 7.0f;
    //    2) altitude (float)
    float altitude = 4800.0f;
    //    3) wingspan (float)
    float wingspan = 15.0f;
    //    4) type (string)
    std::string type = "pigeon";
    //    5) gender (bool)
    bool isMale = true;

    struct Progeny
    {
        bool stillEgg = true;
        float percentToMaturity = 0.0f;
        float satedLevel = 0.0f;
        bool canFly = false;
        bool canForage = false;

        float flyTheNest(float maturePercent, float satedPercent);// returns a liklihood that a fledgling will successfully make it off and become a new Bird, or no effect, or die
        float eat(float maturePercent, std::string target); //returns an amount to increment percentToMaturity
        float chirp(bool parentPresent, float location, float timeOfDay);//retrns a liklihood that chirp will have no effect, attract parents' attention, attrect predator attention
    };

    //3 things it can do:
    //    1) fly
    float fly(float x, float y); //input target coordinates, output travel time
    //    2) sing
    void sing();
    //    3) eat
    float eat(std::string target); //input what's being eaten, ouput new total weight
    std::string forage(Progeny progeny);//makes appropriate food available to progeny to eat based on percentToMaturity
};

struct CPU
{
    //5 properties:
    //    1) manufacturer (std::string)
    std::string manufacturer = "AMD";
    //    2) temperature (float)
    float temperature = 55.5f;
    //    3) clock speed (float)
    float clockSpeed = 3.5f;
    //    4) cores (int)
    int cores = 6;
    //    5) socket size (std::string)
    std::string socket = "AM4";
    //3 things it can do:
    //    1) store data
    float storeData(); //returns stored values
    //    2) output results
    float outputResults(); //returns current values
    //    3) compute
    float compute(float x, float y);//returns result of operations on inputs
};

struct Motherboard
{
    //5 properties:
    //    1) manufacturer (std::string)
    std::string manufacturer = "Gigabyte";
    //    2) wireless LAN capability (bool)
    bool wirelessLAN = false;
    //    3) number of m.2 slots (int)
    int m2Slots = 2;
    //    4) number of expansion slots (int
    int expansionSlots = 4;
    //    5) max RAM capacity (int)
    int maxRAM = 64;
    //3 things it can do:
    //    1) transmit data to RAM
    void dataToRAM();
    //    2) generate A/V signals
    void generateAVSignals();
    //    3) auto suspend
    void autoSuspend();
};

struct KeyboardAndMouse
{
    //5 properties:
    //    1) number of mouse buttons (int)
    int numberOfMouseButtons = 3;
    //    2) keyboard style chiclet/mechanical (bool)
    bool mechanicalStyle = false;
    //    3) wireless yes/no (bool)
    bool wireless = true;
    //    4) language setting (std::string)
    std::string language = "English";
    //    5) numpad yes/no (bool)
    bool numpad = false;
    //3 things it can do:
    //    1) transmit keystroke data
    int transmitKeystrokeData(); //returns ASCII value
    //    2) transmit mouse XY change
    float transmitXYChange(); //returns distance from a 0,0 position, which refreshes periodically
    //    3) toggle status light (like capslock)
    bool toggleStatus(std::string status);//in which indicator to toggle, out isLit true or false
};

struct CoolingSystem
{
    //5 properties:
    //    1) liquid yes/no (bool)
    bool liquid = false;
    //    2) number of rgb lights (int)
    int numberOfRGB = 5;
    //    3) number of fans (int)
    int numberOfFans = 3;
    //    4) fan setting (int)
    int fanSetting = 2;
    //    5) molex power connector yes/no (bool)
    bool molex = false;
    //3 things it can do:
    //    1) set fan speed
    void setFanSpeed(int speed);
    //    2) set light color    
    void setLightColor(std::string color);
    //    3) spring a leak
    void springALeak();
};

struct GPU
{
    //5 properties:
    //    1) intel/nvidia (bool)
    bool intel = false;
    //    2) amount of ram (int)
    int ram = 8;
    //    3) clock speed (float)
    float clockSpeed = 1525.f;
    //    4) number of fans (int)
    int numberOfFans = 3;
    //    5) number of outputs (int)
    int numberOfOutputs = 4;
    //3 things it can do:
    //    1) output a/v signal
    void outputAVSignal();
    //    2) cycle RGB display
    int cycleRGBDisplay(); //increments current display cycle
    //    3) adjust fan speed
    void adjustFanSpeed(int speed);
};

struct Computer
{
    //5 properties:
    //    1) CPU
    CPU myCPU;
    //    2) motherboard
    Motherboard myMotherboard;
    //    3) keyboard and mouse
    KeyboardAndMouse myKeyboardAndMouse;
    //    4) cooling system
    CoolingSystem myCoolingSystem;
    //    5) GPU
    GPU myGPU;
    //3 things it can do:
    //    1) run program
    void runProgram();
    //    2) allocate RAM
    void allocateRAM();
    //    3) refresh display
    void refreshDisplay();
};

int main()
{
    std::cout << "good to go!" << std::endl;
}
