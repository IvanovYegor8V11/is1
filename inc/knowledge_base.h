#ifndef KNOWLEDGE_BASE_LIB
#define KNOWLEDGE_BASE_LIB

#include <iostream>

class knowledge_base {
    float md_first_favorite;
    float md_second_favorite;

    float mnd_first_favorite;
    float mnd_second_favorite;

    float ku_first_favorite;
    float ku_second_favorite; 

    std::string team1_name;
    std::string team2_name;

public:
    knowledge_base(std::string&, std::string&);

    void shortliff(float, float, float, float);

    void get_KU();
    
    void verdict();
};

#endif