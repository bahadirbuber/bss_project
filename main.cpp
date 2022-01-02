#include <iostream>
#include "geojson.hh"
#include <stdio.h>
#include <getopt.h>
#include "calculations.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;


int main(int argc, char **argv) {


    const char* capitalsFileName = "capitals.geojson";
    const char* countriesFileName = "countries.geojson";
    geojson_t countries,capitals;
    string c_parameter_iso_a3,t_parameter;

    for(;;)
    {
        switch(getopt(argc, argv, "c:t:")) // note the colon (:) to indicate that 'b' has a parameter and is not a switch
        {
            case 'c':
                c_parameter_iso_a3 = optarg;
                continue;
            case 't':
                t_parameter = optarg;
                continue;
            default :
                continue;
            case -1:
                break;
        }
        break;
    }

    if (countries.convert(countriesFileName) < 0){
        std::cerr << "Countries couldn't be converted. Please check your geojson file." << endl;
        return 1;
    }
    if (capitals.convert(capitalsFileName) < 0){
        std::cerr << "Capitals couldn't be converted. Please check your geojson file." << endl;
        return 1;
    }
    cout << "Dosyalar başarıyla okundu." << endl;
    bd::BorderData bDatas;
    cd::CableData cDatas;
    dataToVectors(c_parameter_iso_a3, t_parameter, countries, capitals, bDatas, cDatas);

    if(c_parameter_iso_a3.empty()){
        //All countries (ForEach)
        if(t_parameter == "cable"){
            json j = cDatas;
            std::cout << std::setw(4) << j << std::endl;
        }else {
            json j = bDatas;
            std::cout << std::setw(4) << j << std::endl;
        }
    }
    else{
        int index;
        for (int i = 0; i < bDatas.size(); ++i) {
            if (bDatas[i].iso_a3 == c_parameter_iso_a3) index = i;
        }
        if (t_parameter.empty() || t_parameter == "border"){
            json j = bDatas[index];
            std::cout << std::setw(4) << j << std::endl;
        } else if(t_parameter == "cable"){
            json j = cDatas[index];
            std::cout << std::setw(4) << j << std::endl;
        }else {
            std::cerr << "Wrong t parameter. Please check again." << endl;
            return -1;
        }
    }

    return 0;
}
