#pragma once
#include "ground.h"

class TerrainBoots : public Ground {
    public:
        TerrainBoots(double s, double mt, std::string n);
        TerrainBoots(double s, double mt);
        void calcTime(double d) override;
};