#include <iostream>
#include <stdlib.h>
#include <stdio.h>

/* Ground includes */
#include "camel.h"
#include "camelSpeed.h"
#include "centaur.h"
#include "terrainBoots.h"

/* Air includes */
#include "carpetPlane.h"
#include "eagle.h"
#include "broom.h"

#include "race.h"
#include "racepool.h"
#include "transport.h"



void safe_input_number(const char *msg, int &input) {

    for(;;)
    {
        std::cout << msg;
        if (std::cin >> input) {
            break;
        }
        else {
            std::cerr << "Error, input value must contain only numbers!\n";
            std::cin.clear();
            std::cin.ignore(0xFFFF, '\n');
        }
    }
}
void safe_input_number(const char *msg, double &input) {

    for(;;)
    {
        std::cout << msg;
        if (std::cin >> input) {
            break;
        }
        else {
            std::cerr << "Error, input value must contain only numbers!\n";
            std::cin.clear();
            std::cin.ignore(0xFFFF, '\n');
        }
    }
}

// Race it...
void raceOut(RacePool &rcp, Race &rc)
{
    std::cout << std::endl;
    Transport *go = rcp.head;
    int i = 0;

    double dist = rc.getDistance();
    Transport *max = nullptr;

    std::cout << "Racing result: \n";
    while(go != nullptr)
    {
        if (go->regStatus())
        {
            max = go;
            max->calcTime(dist);
            Transport *go2 = max->next;

            while (go2 != nullptr) {

                if (go2->regStatus()) {
                    go2->calcTime(dist);

                    if (go2->getfullTime() > max->getfullTime())
                        max = go2;
                }

                go2 = go2->next;
            }


            std::cout << ++i << ". " << max->name << ". "
                         << "Time: " << max->getfullTime()
                         << std::endl;
            max->unreg();
        }

        if (go->regStatus())
            continue;
        
        go = go->next;
    }

}

Race *race_init() {

    int userInput = 0, raceType = 0;
    double distance = 0.0;

    do
    {
        std::cout << "1. Racing for ground transport" << std::endl;
        std::cout << "2. Racing for air transport" << std::endl;
        std::cout << "3. Racing for ground and air transport" << std::endl;
        std::cout << "Input 0 for exit" << std::endl;

        safe_input_number("selected rancing type: ", userInput);

        // Выходим
        if (!userInput)
            exit(0);

        switch (userInput) {
            case GROUND:
                raceType = GROUND;
            break;

            case AIR:
                raceType = AIR;
            break;
            
            case GROUND_AND_AIR:
                raceType = GROUND_AND_AIR;
            break;

            default:
                system("clear");
                std::cout << "Unknown type of racing!\n";
                std::cout << "Hit any button, for continue...\n";
                std::cin.ignore(0xFFFF, '\n');
                std::cin.get();
                system("clear");
                raceType = -1;
            break;
        }

    } while(raceType < 0);

    system("clear");
    for(;;)
    {
        safe_input_number("Set up distance (must be positive): ", distance);

        if (distance > 0)
            break;
        std::cerr << "The distance, must be positive and greather than 0\n";
    }

    return new Race(raceType, distance);
}

int main()
{    
    RacePool rcPool;

    Camel cl(10, 30);
    CamelSpeed cls(40, 10);
    Centaur cn(15, 8);
    TerrainBoots tb(6, 60);

    CarpetPlane cp(10);
    Eagle ea(8);
    Broom br(20);

    rcPool.addTransport(&cl);
    rcPool.addTransport(&cls);
    rcPool.addTransport(&cn);
    rcPool.addTransport(&tb);
    rcPool.addTransport(&cp);
    rcPool.addTransport(&ea);
    rcPool.addTransport(&br);

    int selected = 0, action = 0, nowRegistered = 0;
    int poolSize = rcPool.getPoolSize();
    Race *rc;
    
    system("clear");
    
    std::cout << "Welcome to the racing simulator!\n";
    for(;;) /* Main loop */
    {
        /* Initialization object "Race" */
        rc = race_init();
        if (rc == nullptr) {
            std::cerr << "Error race init!" << std::endl;
            return -1;
        }

        do {
            system("clear");

            Transport *curr = rcPool.head;
            nowRegistered = rc->getRegisteredCount(curr);

            if (nowRegistered < 2 && nowRegistered >= 0 && !selected) {

                std::cout << "You must register atleast 2 transports" << std::endl;
                for(;;)
                {         
                    std::cout << "1. Register transport" << std::endl;
                    safe_input_number("Choose action: ", action);

                    if (action != 1)
                        std::cerr << "\nUnknown option, try again" << std::endl;
                    else
                        break;
                }

            } else if (nowRegistered >= 2 && !selected) {

                std::cout << "1. Register transport" << std::endl;
                std::cout << "2. Start racing" << std::endl;

                for(;;)
                {
                    safe_input_number("Choose action: ", action);
                    if (action < 1 || action > 2)
                        std::cerr << "\nUnknown option, try again" << std::endl;
                    else
                        break;
                }
            }

            if (action == 2) {

                raceOut(rcPool, *rc);

                for(;;) {
                    std::cout << "\n1. Another racing\n";
                    std::cout << "2. Exit\n";
                    safe_input_number("Choose action: ", action);

                    if (action > 2 || action < 1)
                        std::cout << "\nUnknown option, try again\n";
                    else
                        break;
                }

                if (action == 2)
                    return 0;

                action = 0;
                delete rc;
                break;
            }

            std::string msg;
            for(;;)
            {
                system("clear");
                std::cout << msg;

                curr = rcPool.head;
                std::cout << rc->typeToString() << " Distance: "
                        << rc->getDistance() << std::endl;

                if (rc->getRegisteredCount(curr) > 0) {
                    std::cout << "Registered transports: "
                            << rc->getRegistered(curr)
                            << std::endl;
                }

                while(curr != nullptr) {
                    std::cout << curr->count << ". "
                            << curr->name << " "
                            << std::endl;
                    curr = curr->next;
                }
                
                safe_input_number("Select a transport or 0 for exit from registration: ", selected);
                if ( selected > poolSize || selected < 0)
                    msg = "Unknown transport, choose from list below\n";
                else if (!selected)
                    break;
                else
                {
                    Transport *findId;
                    if ( (findId = rcPool.findMemberById(selected) ) == nullptr)
                        break;

                    int res = rc->regTransport(findId);
                    switch(res)
                    {
                        case REG_NOT_REGISTERED:
                            msg = findId->name + " Successfully registered!\n";
                        break;

                        case REG_REGISTERED:
                            msg = findId->name + " Already registered!\n";
                        break;

                        default:
                            msg = "Attempt to register the wrong type of transport!\n";
                        break;
                    }
                }
            }
        } while(true);

    } /* Main loop */

    delete rc;
    return 0;
}