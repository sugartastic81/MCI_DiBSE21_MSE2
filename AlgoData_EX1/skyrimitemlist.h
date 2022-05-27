//
// Created by juerg on 27.05.2022.
//

#ifndef ABGABE1_SKYRIMITEMLIST_H
#define ABGABE1_SKYRIMITEMLIST_H

#define SKYRIMITEMCOUNT 96

#include <iostream>
#include <string>

class Skyrimitemlist {
public:
    static const string skyrimitems[];
    void printitem()
    {
        std::cout << std::endl << "ITEM - " << skyrimitems[3] << " - ITEM" << std::endl;
    }
};

const string Skyrimitemlist::skyrimitems[96] = {
        "Splash Damage",
        "Plasma Spaz",
        "The Professional",
        "Nuka Chemist",
        "Hand Loader",
        "Vigilant Recycler",
        "Jury Rigging",
        "Shotgun Surgeon",
        "Laser Commander",
        "Rad Child",
        "Stonewall",
        "Unstoppable Force",
        "Slayer",
        "Hit The Deck",
        "Center Of Mass",
        "Spray And Pray",
        "Ferocious Loyalty",
        "Friend Of The Night",
        "Loose Cannon",
        "Piercing Strike",
        "Super Slam",
        "Run N Gun",
        "Heave Ho",
        "Pack Rat",
        "Meltdown",
        "Living Anatomy",
        "Long Haul",
        "Weapon Handling",
        "Travel Light",
        "Cowboy",
        "Built To Destroy",
        "Good Natured",
        "Miss Fortune Perk",
        "Quick Draw",
        "Rapid Reload",
        "Deathclaw Omelet",
        "Confirmed Bachelor",
        "Cherchez La Femme",
        "Purifier",
        "Hunter",
        "Kamikaze",
        "Ghastly Scavenger",
        "Trigger Discipline",
        "Fast Shot",
        "Small Frame",
        "Heavy Handed",
        "Four Eyes",
        "Math Wrath",
        "Retention",
        "GrimReaper Sprint",
        "Chemist",
        "Commando",
        "Chem Resistant",
        "Adamantium Skeleton",
        "Finesse",
        "Fast Metabolism",
        "Night Person",
        "Cannibal",
        "Gunslinger",
        "Bloody Mess",
        "Lady Killer",
        "Black Widow",
        "Action Girl",
        "Intense Training",
        "Infiltrator",
        "Concentrated Fire",
        "Paralyzing Palm",
        "Lead Belly",
        "Nerd Rage",
        "Explorer",
        "Fortune Finder",
        "Comprehension",
        "Toughness",
        "StrongBack",
        "Entomologist",
        "Educated",
        "SwiftLearner",
        "Ninja",
        "Solar Powered",
        "Computer Whiz",
        "Robotics Expert",
        "Tag",
        "Mysterious Stranger",
        "Better Criticals",
        "Action Boy",
        "Light Step",
        "Animal Friend",
        "Sniper",
        "Silent Running",
        "Pyromaniac",
        "Life Giver",
        "Mister Sandman",
        "Here and Now",
        "Demolition Expert",
        "Scrounger",
        "Rad Resistance"
};

// https://stackoverflow.com/questions/440133/how-do-i-create-a-random-alpha-numeric-string-in-c
std::string gen_random_word(const int len) {
    static const char first_cons_letter[] = "BCDFGHJKLMNPRSTVW";
    static const char voc_letter[] = "aeiou";
    static const char cons_letter[] = "bdfghklmnprstuvw";
    std::string tmp_s;
    tmp_s.reserve(len);

    tmp_s += first_cons_letter[rand() % (sizeof(first_cons_letter) - 1)];
    for (int i = 0; i < len; ++i) {
        if( i % 2 == 0) {
            tmp_s += voc_letter[rand() % (sizeof(voc_letter) - 1)];
        }else{
            tmp_s += cons_letter[rand() % (sizeof(voc_letter) - 1)];
        }
    }
    return tmp_s;
}

#endif //ABGABE1_SKYRIMITEMLIST_H
