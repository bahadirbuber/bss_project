//
// Created by haurogh on 1.01.2022.
//

#include "calculations.h"



/**
 * Calculate the approximate distance between two coordinates (lat/lon)
 *
 * © Chris Veness, MIT-licensed,
 * http://www.movable-type.co.uk/scripts/latlong.html#equirectangular
 */

double haversine(double lat1, double lon1,double lat2, double lon2){
    // distance between latitudes
    // and longitudes
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;
    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;
    // apply formulae
    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}
//Calculate border length
double calculateLength(std::vector<coord_t> coordinations) {
    if (coordinations.size() < 2) return 0;
    double result = 0;
    for (int i = 1; i < coordinations.size(); i++) {
        result += haversine(coordinations[i - 1].x, coordinations[i - 1].y, coordinations[i].x, coordinations[i].y);
    }

    return result;
}
//Calculate minimum cable length from capital to borders
double calculateCableLength(std::vector<coord_t> capitals,std::vector<coord_t> countries){
    double min = 100000;
    for(coord_t i: capitals){
        for (coord_t j: countries) {
            double temp = haversine(i.x, i.y, j.x, j.y);
            if (min > temp) min = temp;
        }
    }
    return min;
}

void dataToVectors(const string &cParameter, const string& tParameter, const geojson_t &countries, const geojson_t &capitals, bd::BorderData &bDatas, cd::CableData &cDatas) {
    double borderLength = 0;
    double cableLength = 0;
    bd::border_data bData;
    cd::cable_data cData;

    //ForEach for every country and capital
    for(feature_t i: countries.m_feature){
        for(feature_t k: capitals.m_feature){
            if (k.m_iso3 == i.m_iso3){
                for (const polygon_t& j: i.m_geometry.at(0).m_polygons){
                    borderLength += calculateLength(j.m_coord);
                    for(const polygon_t& z: k.m_geometry.at(0).m_polygons){
                        cableLength = calculateCableLength(z.m_coord,j.m_coord);
                    }
                }
                bData.name = i.m_country;
                bData.iso_a3 = i.m_iso3;
                bData.capital= k.m_city;
                bData.borderLength = borderLength;
                bDatas.push_back(bData);
                cData.name = i.m_country;
                cData.iso_a3 = i.m_iso3;
                cData.capital= k.m_city;
                cData.cableLength = cableLength + borderLength;
                cDatas.push_back(cData);
                cableLength = 0;
                borderLength = 0;
            }
        }
    }
    cableLength = 0;
}
