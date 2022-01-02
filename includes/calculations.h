//
// Created by haurogh on 1.01.2022.
//

#ifndef BSS_CALCULATIONS_H
#define BSS_CALCULATIONS_H
#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "../geojson.hh"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

//Border data namespace for json deserialization and struct for holding data
namespace bd{
    struct border_data{
        std::string name;
        std::string capital;
        std::string iso_a3;
        double borderLength;
    };
    typedef std::vector<border_data> BorderData;
    inline void to_json(json& j, const border_data& p)
    {
        j = {{"name", p.name}, {"iso_a3", p.iso_a3}, {"border", p.borderLength}};
    }
}
//Cable data namespace for json deserialization and struct for holding data

namespace cd{
    struct cable_data{
        std::string name;
        std::string capital;
        std::string iso_a3;
        double cableLength;
    };
    typedef std::vector<cable_data> CableData;
    inline void to_json(json& j, const cable_data& p)
    {
        j = {{"name", p.name}, {"iso_a3", p.iso_a3}, {"cable", p.cableLength}};
    }
}

double haversine(double lat1, double lon1,double lat2, double lon2);
double calculateLength(std::vector<coord_t> coordinations);
void dataToVectors(const string& cParameter, const string& tParameter, const geojson_t& countries, const geojson_t &capitals, bd::BorderData &bDatas, cd::CableData &cDatas);
double calculateCableLength(std::vector<coord_t> capitals,std::vector<coord_t> countries);
//int getIndex(vector<string> v, const string& K);

#endif //BSS_CALCULATIONS_H
