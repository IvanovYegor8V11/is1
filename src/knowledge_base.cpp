#include "knowledge_base.h"

knowledge_base::knowledge_base(std::string& team1_name, std::string& team2_name) {
    md_first_favorite = 0.0f;
    md_second_favorite = 0.0f;

    mnd_first_favorite = 0.0f;
    mnd_second_favorite = 0.0f;

    ku_first_favorite = 0.0f;
    ku_second_favorite = 0.0f;

    this->team1_name = team1_name;
    this->team2_name = team2_name;
}

void knowledge_base::shortliff(float mdff_k, float mdsf_k, float mndff_k, float mndsf_k) {
    md_first_favorite += mdff_k * (1.0f - md_first_favorite);
    md_second_favorite += mdsf_k * (1.0f - md_second_favorite);

    mnd_first_favorite += mndff_k * (1.0f - mnd_first_favorite);
    mnd_second_favorite += mndsf_k * (1.0f - mnd_second_favorite);
}

void knowledge_base::get_KU() {
    ku_first_favorite = md_first_favorite - mnd_first_favorite;
    ku_second_favorite = md_second_favorite - mnd_second_favorite;

    std::cout << team1_name << ": " << md_first_favorite << " " << mnd_first_favorite << " "<< ku_first_favorite << std::endl
            << team2_name << ": " << md_second_favorite << " " << mnd_second_favorite << " "<< ku_second_favorite << std::endl;
}

void knowledge_base::verdict() {
    if (ku_first_favorite == ku_second_favorite) {
        std::cout << "Can\'t say anything\n";
    }
    else {
        std::cout << (ku_first_favorite > ku_second_favorite ? team1_name : team2_name) << " has a better position\n";
    }
}
