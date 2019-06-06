#include <bits/stdc++.h>
#include "Geometry.hpp"
#include "Utils.hpp"

int main() {
    std::vector<std::string> 
    city_paths = read_dir_instances("./polygons/");
    
    std::vector<std::string> 
    deflorestation_paths = read_dir_instances("./points/");
    int total = 0;

    for(const auto& file_name_city : city_paths) {
        std::ifstream file_city(file_name_city);
        std::string line_city;
        std::vector<Point> cidade;
        int number_points = 0;

        while(getline(file_city, line_city)) {
            std::vector<double> arr_p = split(line_city);
            
            //
            for(int i=1; i<arr_p.size(); i+=2) {
                Point p(arr_p[i-1], arr_p[i]);
                cidade.push_back(p);
            }

            Polygon poly(cidade);

            for(const auto& file_name_deflorestation: deflorestation_paths) {
                std::ifstream file_deflorestation(file_name_deflorestation);
                std::string line_deflorestation;
                std::vector<Point> desmatamento;

                while(getline(file_deflorestation, line_deflorestation)) {
                    std::vector<double> centroid = split(line_deflorestation);
                    Point pt(centroid[0], centroid[1]);
                    if(poly.inside(pt)){
                        number_points ++;
                        total++;
                    }
                }
            }   
        }
        std::cout << cleanName(file_name_city) << "," << number_points <<  "\n";
    }

    std::cout << "Total de desmatamento no estado do Pará: " << total << 
    std::endl;
}